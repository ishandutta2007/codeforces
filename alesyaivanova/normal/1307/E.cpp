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

const int maxn = 5009;
int n, m;
int s[maxn];
pii a[maxn];
vector<int> pos[maxn];
pii len[maxn];
pair<bool, int> dp[maxn];
int mod = 1e9 + 7;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        s[i]--;
        pos[s[i]].pb(i);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a[i].ff >> a[i].ss;
        a[i].ff--;
        if ((int)pos[a[i].ff].size() < a[i].ss)
        {
            i--; m--;
            continue;
        }
    }
    sort(a, a + m);
    for (int i = 0; i <= n; i++)
    {
        bool F = (i == n);
        int cur = 1;
        int cnt = 0;
        for (int e = 0; e < m; e++)
        {
            //cout << " " << e << "\n";
            int cnt1 = 0;
            int cnt2 = 0;
            int fl = 0;
            for (int j = e; j <= m; j++)
            {
                if (j == m || a[j].ff != a[e].ff)
                {
                    //cout << "     " << j << "\n";
                    e = j - 1;
                    break;
                }
                int pos1 = pos[a[j].ff][a[j].ss - 1];
                int pos2 = pos[a[j].ff][(int)pos[a[j].ff].size() - a[j].ss];
                if (pos2 == i)
                {
                    if (pos1 < i)
                        fl = 1;
                    else
                        fl = 2;
                    F = 1;
                }
                else if (pos1 < i && pos2 >= i)
                    cnt2++;
                else if (pos1 < i || pos2 >= i)
                    cnt1++;
            }
            if (fl == 2)
            {
                cnt++;
                if (cnt2)
                {
                    cur = (cur * cnt2) % mod;
                    cnt++;
                }
            }
            else if (fl == 1)
            {
                cnt++;
                if (cnt1 + cnt2)
                {
                    cur = (cur * (cnt1 + cnt2)) % mod;
                    cnt++;
                }
            }
            else if (min(cnt1, 1ll) + cnt2 >= 2)
            {
                cur = (cur * (((cnt1 * cnt2) + (cnt2 * (cnt2 - 1))) % mod)) % mod;
                cnt += 2;
            }
            else if (cnt2 == 1)
            {
                cur = (cur * 2) % mod;
                cnt++;
            }
            else if (cnt1 >= 1)
            {
                cur = (cur * cnt1) % mod;
                cnt++;
            }
        }
        if (F)
        {
            //cout << i << " " << cnt << " " << cur << "\n";
            dp[cnt].ff = 1;
            dp[cnt].ss = (dp[cnt].ss + cur) % mod;
        }
    }
    for (int i = n; i >= 1; i--)
    {
        if (dp[i].ff)
        {
            cout << i << " " << dp[i].ss;
            return 0;
        }
    }
    cout << "0 1";
}