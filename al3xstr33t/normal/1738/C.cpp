#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <bitset>
#include <unordered_map>
#include <complex>
#include <unordered_set>
#include <chrono>
#include <random>
#include <functional>
#include <random>

using namespace std;

const int maxN = 209;
int N, dp[maxN + 10][maxN + 10][2];

int main() {
    //freopen("../input", "r", stdin);
    //freopen("../output", "w", stdout);
    int tests;
    scanf("%d", &tests);
    //dp[i][j][k] = who wins if there are i evens, j odds and the player at turn wins iff sum is k
    for (int i=0; i<=maxN; i++)
        dp[0][i][((i + 1) / 2) % 2] = 1,
        dp[i][0][0] = 1;
    for (int i=1; i<=maxN; i++)
        for (int j=1; i + j<=maxN; j++)
            for (int k=0; k<2; k++) {
                dp[i][j][k] = 1 ^ (dp[i - 1][j][(j & 1) ^ k ^ 1] & dp[i][j - 1][(j & 1) ^ k ^ 1]);
            }
    while (tests --) {
        scanf("%d", &N);
        int cnt[2] = {0, 0};
        while (N --) {
            int x;
            scanf("%d", &x), cnt[x & 1] ++;
        }
        if (dp[cnt[0]][cnt[1]][0]) printf ("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/