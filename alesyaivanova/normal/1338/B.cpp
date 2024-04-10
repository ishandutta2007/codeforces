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

const int maxn = 1e5 + 9;
vector<int> g[maxn];
int dp[2];
int n, ans;

void dfs(int v, int pr, int h)
{
    bool fl = 0;
    for (int to : g[v])
    {
        if (to == pr)
            continue;
        if ((int)g[to].size() == 1)
        {
            if (!fl)
            {
                ans++;
                fl = 1;
            }
        }
        else
            ans++;
        dfs(to, v, h ^ 1);
    }
    if ((int)g[v].size() == 1)
        dp[h]++;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    int st = 0;
    for (int i = 0; i < n; i++)
    {
        if (g[i].size() >= 2)
        {
            st = i;
            break;
        }
    }
    dfs(st, -1, 0);
    if (dp[0] && dp[1])
        cout << "3 ";
    else
        cout << "1 ";
    cout << ans;
}