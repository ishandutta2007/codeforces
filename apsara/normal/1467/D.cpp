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

int dp[V][V], xs[V], n, m, Q, x, y, a[V];

int main() {
    while (~scanf("%d%d%d", &n, &m, &Q)) {
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) dp[i][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (j > 1) dp[j - 1][i + 1] = (dp[j - 1][i + 1] + dp[j][i]) % P;
                if (j < n) dp[j + 1][i + 1] = (dp[j + 1][i + 1] + dp[j][i]) % P;
            }
        }
        for (int i = 1; i <= n; ++i) {
            xs[i] = 0;
            for (int j = 0; j <= m; ++j) xs[i] = (xs[i] + (LL) dp[i][j] * dp[i][m - j]) % P;
        }
        //for (int i = 1; i <= n; ++i) printf("%d ", xs[i]); puts("");
        int ans = 0;
        for (int i = 1; i <= n; ++i) ans = (ans + (LL) xs[i] * a[i]) % P;
        while (Q--) {
            scanf("%d%d", &x, &y);
            ans = (ans - (LL) xs[x] * a[x] % P + P) % P;
            a[x] = y;
            ans = (ans + (LL) xs[x] * a[x] % P + P) % P;
            printf("%d\n", ans);
        }
    }
    return 0;
}

/*
5 1 5
3 5 1 4 2
1 9
2 4
3 6
4 6
5 2

5 2 5
3 5 1 4 2
1 9
2 4
3 6
4 6
5 2

4 40 6
92 21 82 46
3 56
1 72
4 28
1 97
2 49
2 88
*/