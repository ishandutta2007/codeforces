#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) (x).begin(), (x).end()

const int MAXN = 3609;
int a[MAXN];
bool used[2][MAXN];
int n[2];
int k;
int cnt[2];
int dp[2][MAXN][MAXN];
int mod = 998244353;
int f[MAXN];
int c[MAXN][MAXN];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    c[0][0] = 1;
    f[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        f[i] = (f[i - 1] * i) % mod;
        c[i][0] = 1;
        for (int e = 1; e <= i; e++)
            c[i][e] = (c[i - 1][e] + c[i - 1][e - 1]) % mod;
    }
    cin >> n[0] >> n[1] >> k;
    for (int i = 0; i < 2 * k; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        used[0][x] = 1;
        used[1][y] = 1;
    }
    for (int j = 0; j <= 1; j++)
    {
        dp[j][0][0] = 1;
        for (int i = 0; i < n[j]; i++)
        {
            if (!used[j][i])
                cnt[j]++;
            if (i && !used[j][i] && !used[j][i - 1])
            {
                dp[j][i][0] = 1;
                for (int cnt = 1; cnt < MAXN; cnt++)
                    dp[j][i][cnt] = (dp[j][i - 1][cnt] + (i >= 2 ? dp[j][i - 2][cnt - 1] : (cnt == 1 ? 1 : 0))) % mod;
            }
            else if (i)
            {
                for (int cnt = 0; cnt < MAXN; cnt++)
                    dp[j][i][cnt] = dp[j][i - 1][cnt];
            }
        }
    }
    int ans = 0;
    for (int a = 0; a <= cnt[0] / 2; a++)
    {
        for (int b = 0; b <= cnt[1] / 2; b++)
        {
            int x = cnt[0] - 2 * a;
            int y = cnt[1] - 2 * b;
            if (x < b || y < a)
                continue;
            //cout << a << " " << y << " " << b << " " << x << " ";
            int cur = (dp[0][n[0] - 1][a] * dp[1][n[1] - 1][b]) % mod;
            cur = (cur * c[x][b]) % mod;
            cur = (cur * c[y][a]) % mod;
            cur = (cur * f[a]) % mod;
            cur = (cur * f[b]) % mod;
            //cout << cur << "\n";
            ans += cur;
            if (ans >= mod)
                ans -= mod;
        }
    }
    cout << ans;
}