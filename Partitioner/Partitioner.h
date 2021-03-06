#pragma once

#include "Types.h"
#include "NetList.h"

class Partitioner
{
public:
    Partitioner();
    ~Partitioner();

    bool parseInputFile();
    parsedInputStruct_t getParsedInput();
    void doPartitioning(NetList &netList);
    std::string getInfoportString();
    void updatePartitionLists(NetList &netList);
    void determineSwap();
    state_e getState();
    void setState(state_e state);

    std::string mFilename;                              ///< Current filename
    parsedInputStruct_t mParsedInput;                   ///< Parsed input struct
    clock_t mStartTime;                                 ///< start time for partitioning
    clock_t mEndTime;                                   ///< end time for partitioning
    state_e mState;                                     ///< Current partitioning state
    bool mFirstTime;                                    ///< To check if this is the first time
    int mCurrentGain;                                   ///< Keep track of the current gain
    unsigned int mCurrentPartition;                     ///< Keep track of current partition we are swapping from
    unsigned int mStartCutSize;                         ///< Keep track of the starting cut size
    unsigned int mCurrentCutSize;                       ///< Keep track of the current cut size
    unsigned int mBestCutSize;                          ///< Keep track of the best cut size so far
    unsigned int mCurrentIteration;                     ///< Current partitioner iteration
    std::vector<unsigned int> mSwapCandidates;          ///< Current swap candidates
    std::vector<unsigned int> mPartitionNodeList[2];    ///< Partition node lists
    std::vector<posStruct_t> mBestNodePositions;        ///< Node positions for best cut

private:
    const unsigned int MAX_ITERATIONS = 6;
};

