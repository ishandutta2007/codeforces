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

#define maxN 333

ll n, m, k, x, y, i, j;
ll sz, cnt, aux;

ll bonus[maxN][maxN];
ll mini, maxi;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld%lld%lld%lld", &n, &m, &k, &x, &y);

    if (n == 1) {
        cnt = k / m;
        k -= cnt * m;

        if (k == 0) {
            printf("%lld %lld %lld", cnt, cnt, cnt);
            return 0;
        }

        //if (cnt % 2 == 0)
            aux = cnt + (y <= k ? 1 : 0);
        /*else
            aux = cnt + (y >= m - k + 1 ? 1 : 0);*/

        printf("%lld %lld %lld", cnt + 1, cnt, aux);
        return 0;
    }

    sz = (2 * n - 2) * m;
    cnt = k / sz;
    k -= sz * cnt;

    for (i = 1; k > 0; i++)
        for (j = 1; j <= m && k > 0; j++, k--)
            bonus[i][j]++;

    for (i = 1; i <= 2 * n - 2; i++)
        for (j = 1; j <= m; j++)
            bonus[i][j] += cnt;

    for (i = n + 1; i <= 2 * n - 2; i++)
        for (j = 1; j <= m; j++)
            bonus[2 * n - i][j] += bonus[i][j];

    mini = 1LL << 62;
    maxi = -1;

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            maxi = max(maxi, bonus[i][j]), mini = min(mini, bonus[i][j]);

    printf("%lld %lld %lld", maxi, mini, bonus[x][y]);



    return 0;
}