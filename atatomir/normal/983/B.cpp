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

const int maxN = 5011;

int n, q, i, j, bit, limit, l, r;
int a[maxN];

int v[4 * maxN];
int dp[maxN][maxN];

void solve() {
    int i, j;

    for (i = 0; i <= bit; i++) {
        for (j = 0; j < limit; j++) {
            if ((j >> i) & 1)
                v[j] ^= v[j ^ (1 << i)];
        }
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (bit = 0; (1 << bit) <= n - 1; bit++);
    bit--;

    for (i = 1; i <= n; i++) {
        if ( (1 << bit) > n - i ) bit--;

        limit = 1 << (bit + 1);
        for (j = 0; j < limit; j++) v[j] = 0;

        for (j = i; j <= n; j++)
            v[j - i] = a[j];

        solve();
        for (j = i; j <= n; j++)
            dp[i][j] = max(dp[i][j], v[j - i]);
    }

    for (i = n; i >= 1; i--)
        for (j = i; j <= n; j++)
            dp[i][j] = max(dp[i][j], max(dp[i + 1][j], dp[i][j - 1]));

    scanf("%d", &q);
    for (i = 1; i <= q; i++) {
        scanf("%d%d", &l, &r);
        printf("%d\n", dp[l][r]);
    }

    return 0;
}