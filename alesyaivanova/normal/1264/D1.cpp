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

const int maxn = 2007;
int cnt[maxn][3];
int c[maxn][maxn];
string s;
int n;
int mod = 998244353;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    n = s.size();
    c[0][0] = 1;
    for (int i = 1; i < n; i++)
    {
        c[i][0] = 1;
        for (int e = 1; e <= i; e++)
            c[i][e] = (c[i - 1][e] + c[i - 1][e - 1]) % mod;
    }
    for (int i = 0; i < n; i++)
    {
        if (i)
        {
            for (int j = 0; j < 3; j++)
                cnt[i][j] = cnt[i - 1][j];
        }
        if (s[i] == '(')
            cnt[i][0]++;
        else if (s[i] == ')')
            cnt[i][1]++;
        else
            cnt[i][2]++;
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int h = 1; h <= n / 2; h++)
        {
            if (h < cnt[n - 1][1] - cnt[i][1] || h < cnt[i][0])
                continue;
            int cur = c[cnt[n - 1][2] - cnt[i][2]][h - (cnt[n - 1][1] - cnt[i][1])];
            ans = (ans + h * ((cur * c[cnt[i][2]][h - cnt[i][0]]) % mod)) % mod;
        }
    }
    cout << ans;
}