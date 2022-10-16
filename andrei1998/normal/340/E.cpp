#include <iostream>

using namespace std;

const int NMAX = 2000 + 5;
const int MOD = 1000000000 + 7;

int N;
int p[NMAX];
int degree[NMAX];

int dp[NMAX][NMAX]; // dp[paths][nodes]

inline void add(int &where, int val) {
    where += val;
    if (where >= MOD)
        where -= MOD;
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; ++ i) {
        cin >> p[i];
        ++ degree[p[i]];
    }

    int nodes = 0, paths = 0;
    for (int i = 1; i <= N; ++ i)
        if (!degree[i]) {
            if (p[i] > 0)
                ++ paths;
            else
                ++ nodes;
        }

    dp[0][0] = 1;
    for (int j = 2; j <= nodes; ++ j)
        dp[0][j] = ((j - 1LL) * (dp[0][j - 1] + dp[0][j - 2])) % MOD;

    for (int i = 1; i <= paths; ++ i)
        for (int j = 0; j <= nodes; ++ j) {
            //Close a cycle
            dp[i][j] = dp[i - 1][j];

            //Group with a free node
            if (j > 0)
                dp[i][j] = (dp[i][j] + 1LL * j * dp[i][j - 1]) % MOD;

            //Group with another cycle
            if (i > 1)
                dp[i][j] = (dp[i][j] + 1LL * (i - 1) * dp[i - 1][j]) % MOD;
        }


    cout << dp[paths][nodes] << '\n';
    return 0;
}