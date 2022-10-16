#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define mod 1000000007
#define lint long long int
#define inf (1ll << 61)
using namespace std;

int a[300005];

lint dp[5005][5005];

inline void upd (lint &x, lint val) {
    if (val < x)
        x = val;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    int n, k;

    cin >> n >> k;
    for (int i = 1; i <= n; ++ i)
        cin >> a[i];
    sort(a + 1, a + n + 1);

    //t1 = lungi
    //t2 = scurte

    int lt1 = (n - 1) / k + 1, lt2 = n / k;
    int ct1 = 0, ct2 = 0;

    for (int i = 1; i <= k; ++ i)
        if ((n - i) / k + 1 == lt1)
            ct1 ++;
        else
            ct2 ++;

    int j, where;

    for (int i = 0; i <= ct1; ++ i)
        for (j = 0; j <= ct2; ++ j)
            dp[i][j] = inf;

    dp[0][0] = 0;
    for (int i = 0; i <= ct1; ++ i)
        for (j = 0; j <= ct2; ++ j) {
            where = (i * lt1 + j * lt2);

            if (where + lt1 <= n)
                 upd(dp[i + 1][j], dp[i][j] + a[where + lt1] - a[where + 1]);

            if (where + lt2 <= n)
                 upd(dp[i][j + 1], dp[i][j] + a[where + lt2] - a[where + 1]);
        }

    cout << dp[ct1][ct2] << '\n';
    return 0;
}