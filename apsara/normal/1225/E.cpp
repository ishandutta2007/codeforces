#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long LL;
const int P = 1000000007;
const int V = 2010;
int R[V][V], D[V][V];
char mp[V][V];
//0 down, 1 right
int dp[V][V][2], s[V][V][2], pos[V][V][2];
int n, m;

int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < n; ++i) scanf("%s", mp[i]);
        for (int i = 0; i < n; ++i) {
            R[i][m] = 0;
            for (int j = m - 1; j >= 0; --j)
                R[i][j] = R[i][j + 1] + (mp[i][j] == 'R'?1:0);
        }
        for (int j = 0; j < m; ++j) {
            D[n][j] = 0;
            for (int i = n - 1; i >= 0; --i)
                D[i][j] = D[i + 1][j] + (mp[i][j] == 'R'?1:0);
        }
        //for (int i = 0; i < n; ++i, puts(""))
            //for (int j = 0; j < m; ++j) printf("%d ", R[i][j]);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 && j == 0) {
                    dp[i][j][0] = dp[i][j][1] = 1;
                } else {
                    if (j == 0) pos[i][j][0] = 0;
                    else pos[i][j][0] = pos[i][j - 1][0];
                    while (pos[i][j][0] + 1 < m && R[i][pos[i][j][0] + 1] > m - 1 - j) ++pos[i][j][0];
                    dp[i][j][0] = 0;
                    if (pos[i][j][0] < j) {
                        if (j > 0) dp[i][j][0] += s[i][j - 1][0];
                        if (pos[i][j][0] != 0) dp[i][j][0] -= s[i][pos[i][j][0] - 1][0];
                        dp[i][j][0] = (dp[i][j][0] % P + P) % P;
                    }

                    if (i == 0) pos[i][j][1] = 0;
                    else pos[i][j][1] = pos[i - 1][j][1];
                    while (pos[i][j][1] + 1< n && D[pos[i][j][1] + 1][j] > n - 1 - i) ++pos[i][j][1];
                    dp[i][j][1] = 0;
                    if (pos[i][j][1] < i) {
                        if (i > 0) dp[i][j][1] += s[i - 1][j][1];
                        if (pos[i][j][1] != 0) dp[i][j][1] -= s[pos[i][j][1] - 1][j][1];
                        dp[i][j][1] = (dp[i][j][1] % P + P) % P;
                    }
                    //printf("pos %d %d %d %d\n", i, j, pos[i][j][0], pos[i][j][1]);
                }
                if (j == 0) s[i][j][0] = dp[i][j][1];
                else s[i][j][0] = (s[i][j - 1][0] + dp[i][j][1]) % P;
                if (i == 0) s[i][j][1] = dp[i][j][0];
                else s[i][j][1] = (s[i - 1][j][1] + dp[i][j][0]) % P;
               // printf("DP %d %d %d %d %d %d\n", i, j, dp[i][j][0], dp[i][j][1], s[i][j][0], s[i][j][1]);
            }
        }
        int ans = (dp[n - 1][m - 1][0] + dp[n - 1][m - 1][1]) % P;
        if (n == 1 && m == 1) ans = 1;
        printf("%d\n", ans);
    }
    return 0;
}

/*
1 1
.
2 2
.R
..
2 2
..
R.
2 3
...
..R
4 4
...R
.RR.
.RR.
R...

*/