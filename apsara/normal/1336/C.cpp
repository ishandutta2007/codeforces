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
const int P = 998244353;
const int V = 3010;
char s[V], t[V];
int dp[V][V], n, m;
int main() {
    while (~scanf("%s", s)) {
        scanf("%s", t);
        n = strlen(s);
        m = strlen(t);
        memset(dp, 0, sizeof(dp));
        for (int i = m; i <= n; ++i) dp[1][i] = 1;
        //dp[1][n] = 1;
        for (int l = n; l >= 1; --l) {
            for (int x = 1; x + l - 1 <= n; ++x) {
                int y = l + x - 1;
                if (x - 1 >= m || t[x - 1] == s[l - 1]) {
                    dp[x + 1][y] = (dp[x + 1][y] + dp[x][y]) % P;
                }
                if (y - 1 >= m || t[y - 1] == s[l - 1]) {
                    dp[x][y - 1] = (dp[x][y - 1] + dp[x][y]) % P;
                }
            }
        }
        int ans = 0;
        for (int x = 1; x <= n + 1; ++x) {
            ans = (ans + dp[x][x - 1]) % P;
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
abab
ba
defineintlonglong
signedmain
rotator
rotator
cacdcdbbbb
bdcaccdbbb
*/