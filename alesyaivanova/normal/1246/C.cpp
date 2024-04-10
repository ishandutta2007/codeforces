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

const int MAXN = 2007;
int a[MAXN][MAXN];
int cnt[MAXN][MAXN][2];
int dp[MAXN];
int add[MAXN][MAXN];
int mod = 1e9 + 7;
int n, m;
int kek[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int e = 0; e < m; e++)
        {
            if (s[e] == 'R')
                a[i][e] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int e = m - 1; e >= 0; e--)
            cnt[i][e][0] = cnt[i][e + 1][0] + a[i][e];
    }
    for (int e = 0; e < m; e++)
    {
        for (int i = n - 1; i >= 0; i--)
            cnt[i][e][1] = cnt[i + 1][e][1] + a[i][e];
    }
    dp[0] = 1;
    //q[0].emplace(n - cnt[0][0][1], 1);
    add[n - cnt[0][0][1]][0] = 1;
    for (int i = 0; i < n; i++)
    {
//        for (int e = 0; e < m; e++)
//            cout << dp[e] << " ";
//        cout << "\n";
        for (int e = 0; e < m; e++)
        {
            dp[e] -= add[i][e];
            if (dp[e] < 0)
                dp[e] += mod;
//            while (!q[e].empty() && (*q[e].begin()).ff == i)
//            {
//                dp[e] -= (*q[e].begin()).ss;
//                if (dp[e] < 0)
//                    dp[e] += mod;
//                q[e].erase(q[e].begin());
//            }
        }
//        for (int e = 0; e < m; e++)
//            cout << " " << dp[e];
//        cout << "\n";
        for (int e = 0; e < m; e++)
            kek[e] = 0;
        int cur = 0;
        for (int e = 0; e < m; e++)
        {
//            while (!s.empty() && (*s.begin()).ff == e)
//            {
//                cur -= (*s.begin()).ss;
//                if (cur < 0)
//                    cur += mod;
//                s.erase(s.begin());
//            }
            cur -= kek[e];
            if (cur < 0)
                cur += mod;
            int t = cur;
            cur += dp[e];
            if (cur >= mod)
                cur -= mod;
            //s.emplace(m - cnt[i][e + 1][0], dp[e]);
            kek[m - cnt[i][e + 1][0]] += dp[e];
            if (kek[m - cnt[i][e + 1][0]] >= mod)
                kek[m - cnt[i][e + 1][0]] -= mod;
            //q[e].emplace(n - cnt[i + 1][e][1], t);
            add[n - cnt[i + 1][e][1]][e] += t;
            if (add[n - cnt[i + 1][e][1]][e] >= mod)
                add[n - cnt[i + 1][e][1]][e] -= mod;
            dp[e] += t;
            if (dp[e] >= mod)
                dp[e] -= mod;
        }
    }
    cout << dp[m - 1];
}