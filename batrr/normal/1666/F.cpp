#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 5050, mod = 998244353;

int n, cnt[N];
int dp[N], tmp[N];
int C[N][N];

void solve()
{
    scanf("%d", &n);

    for (int i = 0; i <= n; i++)
    {
        cnt[i] = 0;
        dp[i] = tmp[i] = 0;
    }

    int mn = 1e9, mx = -1e9;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        cnt[x]++;
        mn = min(mn, x);
        mx = max(mx, x);
    }

    if (cnt[mx] > 1)
    {
        printf("0\n");
        return;
    }
    if (n == 2)
    {
        if (mx == mn)
            printf("0\n");
        else
            printf("1\n");
        return;
    }
    cnt[mx]--;

    dp[0] = 1;

    for (int i = n; i >= 1; i--)
    {
        if (cnt[i] == 0)
            continue;

        {
            {
                int k = cnt[i] - 1;
                for (int j = k; j <= n; j++)
                    tmp[j - k + 1] = (tmp[j - k + 1] + 1ll * dp[j] * C[j][k]) % mod;
            }

            {

                int sr = 0, koef = 1;
                for (int j = 0; j < i; j++)
                {
                    sr += cnt[j];
                    koef = 1ll * koef * C[sr][cnt[j]] % mod;
                }
                if (sr > 0)
                    ans = (ans + 1ll * tmp[sr - 1] * koef) % mod;
            }

            {
                int k = cnt[i];
                for (int j = k; j <= n; j++)
                    tmp[j - k] = (tmp[j - k] + 1ll * dp[j] * C[j][k]) % mod;
            }
        }
        for (int i = 0; i <= n; i++)
            dp[i] = tmp[i], tmp[i] = 0;

        // cerr << i << " " << cnt[i] << endl;
        // for (int i = 0; i <= n; i++)
        //     cerr << dp[i] << " ";
        // cerr << endl;
    }
    printf("%d\n", ans);
}
int main()
{
    for (int i = 0; i < N; i++)
        C[i][0] = 1;
    for (int i = 1; i < N; i++)
        for (int j = 1; j <= i; j++)
        {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            if (C[i][j] >= mod)
                C[i][j] -= mod;
        }

    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}