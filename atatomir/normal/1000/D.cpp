#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

const int maxN = 1024;
const int mod = 998244353;

int n, i, a[maxN], j;
int dp[maxN][maxN];

void add(int& a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);

    dp[0][0] = 1;
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            if (dp[i][j] == 0) continue;

            //cerr << i << ' ' << j << ' ' << dp[i][j] << '\n';

            add(dp[i + 1][j], dp[i][j]);
            if (j > 0) {
                add(dp[i + 1][j - 1], dp[i][j]);
            } else {
                if (a[i + 1] > 0 && a[i + 1] <= n)
                    add(dp[i + 1][a[i + 1]], dp[i][j]);
            }
        }
    }

    add(dp[n][0], mod - 1);
    printf("%d", dp[n][0]);

    return 0;
}