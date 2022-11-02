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

const int maxn = 2e5 + 9;
vector<int> g[maxn];
int h[maxn];
int b[maxn];
int dp[maxn][2];
int n;

void dfs(int v, int pr)
{
    int cnt1 = 0, cnt2 = 0;
    int sum = 0;
    vector<int> cur;
    for (int to : g[v])
    {
        if (to == pr)
            continue;
        dfs(to, v);
        if (h[to] > h[v])
        {
            cnt1++;
            sum += dp[to][0];
        }
        else if (h[to] < h[v])
        {
            cnt2++;
            sum += dp[to][1];
        }
        else
        {
            cnt1++;
            sum += dp[to][0];
            cur.pb(dp[to][1] - dp[to][0]);
        }
    }
    sort(all(cur));
    if (!v)
    {
        dp[v][0] = sum + max(cnt1, cnt2) * b[v];
        for (int e : cur)
        {
            cnt1--;
            cnt2++;
            sum += e;
            dp[v][0] = min(dp[v][0], sum + max(cnt1, cnt2) * b[v]);
        }
        return;
    }
    dp[v][0] = sum + max(cnt1, cnt2 + 1) * b[v];
    dp[v][1] = sum + max(cnt1 + 1, cnt2) * b[v];
    for (int e : cur)
    {
        cnt1--;
        cnt2++;
        sum += e;
        dp[v][0] = min(dp[v][0], sum + max(cnt1, cnt2 + 1) * b[v]);
        dp[v][1] = min(dp[v][1], sum + max(cnt1 + 1, cnt2) * b[v]);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(0, -1);
    cout << dp[0][0];
}