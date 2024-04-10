#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int SZ = 333;
const int N = 1e5 + 7;

int dp[N][SZ];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j < SZ; j++)
        {
            if (i + a[i] + j >= n)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i + a[i] + j][j] + 1;
            }
        }
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int i, k;
        scanf("%d%d", &i, &k);
        i--;
        if (k < SZ)
        {
            printf("%d\n", dp[i][k]);
        }
        else
        {
            int ans = 1;
            while (i + a[i] + k < n)
            {
                ans++;
                i = i + a[i] + k;
            }
            printf("%d\n", ans);
        }
    }
}