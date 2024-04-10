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
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 1e6 + 9;
int a[maxn];
int n;
int pr[maxn];
vector<pii> t[maxn];
int dp[maxn];
int mod = 1e9 + 7;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++)
        a[i] = (s[i] == '1');
    pr[0] = -1;
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1])
            pr[i] = i - 1;
        else
            pr[i] = pr[i - 1];
    }
    vector<pii> cur;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i])
        {
            while (!cur.empty() && cur.back().ff <= cnt)
                cur.pop_back();
            cur.pb(cnt, i);
            cnt = 0;
            t[i] = cur;
        }
        else
            cnt++;
    }
    int cnt1 = 1;
    for (int i = 0; (i < n) && (!a[i]); i++)
        cnt1++;
    if (cnt1 == n + 1)
    {
        cout << n;
        return 0;
    }
    int j = (a[n - 1] ? n - 1 : pr[n - 1]);
    dp[j] = n - j;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (!a[i])
            continue;
//        cout << i << " " << dp[i] << "\n";
        ans = (ans + dp[i] * cnt1) % mod;
        for (int e = (int)t[i].size() - 1; e >= 0; e--)
        {
            int x = t[i][e].ff - (e != (int)t[i].size() - 1 ? t[i][e + 1].ff : -1);
//            cout << i << " " << x << " " << t[i][e].ss << "\n";
            int pos = pr[t[i][e].ss];
            if (pos >= 0)
                dp[pos] = (dp[pos] + dp[i] * x) % mod;
        }
    }
    cout << ans;
}