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

#define maxN 1024
#define maxK 111
#define inf 100000000

int n, p, k, i, j, cnt, x, ss, dd;
int dp[2][maxN][maxK];
int sum_a[maxN], sum_b[maxN], sum_both[maxN];

void fill_with_minus(int id) {
    static int i, j;

    for (i = 0; i <= n; i++)
        for (j = 0; j <= 2 * k; j++)
            dp[id][i][j] = -inf;
}

int how_many(int who, int l, int r, int limit) {
    r = min(r, n);
    if (l > r) return 0;

    if (who == 1)
        return (sum_a[r] - sum_a[l - 1]) - (sum_both[limit] - sum_both[l - 1]);
    else
        return (sum_b[r] - sum_b[l - 1]) - (sum_both[limit] - sum_both[l - 1]);
}

void compute() {
    int i, j, p1, p2;

    for (i = 0; i <= n; i++) {

        for (j = k; j >= 0; j--) {
            if (i - j < 0 || i - j > n) continue;
            if (dp[ss][i][k + j] < -inf) continue;

            dp[dd][i][k + j] = max(dp[dd][i][k + j], dp[ss][i][k + j]);
            dp[ss][i][k + j - 1] = max(dp[ss][i][k + j - 1], dp[ss][i][k + j]);

            p1 = i;
            p2 = min(n, i - j + k);
            if (p2 < 0) continue;

            if (-k <= p1 - p2 && p1 - p2 <= k)
                dp[dd][p1][k + p1 - p2] = max(dp[dd][p1][k + p1 - p2], dp[ss][i][k + j] + how_many(2, i - j + 1, i - j + k, i));
        }

        for (j = 0; j >= -k; j--) {
            if (i - j < 0 || i - j > n) continue;
            if (dp[ss][i][k + j] < -inf) continue;

            dp[dd][i][k + j] = max(dp[dd][i][k + j], dp[ss][i][k + j]);
            dp[ss][i + 1][k + j + 1] = max(dp[ss][i + 1][k + j + 1], dp[ss][i][k + j]);

            p1 = min(n, i + k);
            p2 = i - j;
            if (p2 < 0) continue;

            if (-k <= p1 - p2 && p1 - p2 <= k)
                dp[dd][p1][k + p1 - p2] = max(dp[dd][p1][k + p1 - p2], dp[ss][i][k + j] + how_many(1, i + 1, i + k, i - j));
        }
    }
}

int main()
{
    //freopen("test.in","r",stdin);
    //freopen("test.out", "w", stdout);

    scanf("%d%d%d", &n, &p, &k);
    scanf("%d", &cnt);
    for (i = 1; i <= cnt; i++) scanf("%d", &x), sum_a[x]++;
    scanf("%d", &cnt);
    for (i = 1; i <= cnt; i++) scanf("%d", &x), sum_b[x]++;

    for (i = 1; i <= n; i++) {
        sum_both[i] = sum_both[i - 1] + (sum_a[i] == 1 && sum_b[i] == 1);
        sum_a[i] += sum_a[i - 1];
        sum_b[i] += sum_b[i - 1];
    }

    ss = 0; dd = 1;
    fill_with_minus(ss);
    dp[ss][0][k] = 0;

    for (int i = 0; i <= p; i++) {
        fill_with_minus(dd);
        compute();

        swap(ss, dd);
    }

    printf("%d", dp[dd][n][k]);

    return 0;
}