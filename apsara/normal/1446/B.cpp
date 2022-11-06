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
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;

const int V = 5010;
char s[V], t[V];
int dp[V][V];
int n, m;
int main() {
    while (~scanf("%d%d", &n, &m)) {
        scanf("%s%s", s, t);
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for (int i = 0; i <= n; ++i) {
            for(int j = 0; j <= m; ++j) {
                ans = max(ans, dp[i][j]);
                if (i < n) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - 1);
                if (j < m) dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] - 1);
                if (i < n && j < m && s[i] == t[j]) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 2);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
4 5
abba
babab

8 10
bbbbabab
bbbabaaaaa

7 7
uiibwws
qhtkxcn
*/