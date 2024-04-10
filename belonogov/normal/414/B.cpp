#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int maxn = 2014;
const int inf = 1e9;
const int MOD = 1e9 + 7;

int dp[maxn][maxn];

int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
#endif
    int n, k;
    scanf("%d%d", &n, &k);
    dp[0][1] = 1;
    for (int i = 0; i < k; i++)
        for (int j = 1; j <= n; j++) {
            for (int t = 1; t * j <= n; t++)
                dp[i + 1][t * j] = (dp[i + 1][t * j] + dp[i][j]) % MOD;
        }
    //for (int i = 0; i < 

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (ans + dp[k][i]) % MOD;
    cout << ans << endl;

    return 0;
}