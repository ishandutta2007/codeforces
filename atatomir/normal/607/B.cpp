#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 555
#define not_computed -1

int i, j, n;
int v[maxN];
int dp[maxN][maxN];

int compute(int l, int r) {

    if (l == 2 && r == 6) {
        l++; l--;
    }

    if (dp[l][r] == not_computed) {
        //! compute it

        if (l > r) {
            dp[l][r] = 0;
            goto end_place;
        }
        if (l == r) {
            dp[l][r] = 1;
            goto end_place;
        }
        if (l + 1 == r) {
            if (v[l] == v[r])
                dp[l][r] = 1;
            else
                dp[l][r] = 2;
            goto end_place;
        }

        dp[l][r] = n;

        for (int i = l; i < r; i++)
            dp[l][r] = min(dp[l][r], compute(l, i) + compute(i + 1, r));
        if (v[l] == v[r])
            dp[l][r] = min(dp[l][r], compute(l + 1, r - 1));
    }

    end_place:

    return dp[l][r];
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &v[i]);

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            dp[i][j] = not_computed;

    printf("%d", compute(1, n));


    return 0;
}