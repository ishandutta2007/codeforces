#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 300005;

int n;
int b[N];
vector<pair<int, int> > a[N];

long long ans;

long long dp[N];
void dfs(int x, int p)
{
    dp[x] = b[x];
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        int d = a[x][i].second;
        if (h == p)
            continue;
        dfs(h, x);
        if (dp[h] >= d)
            dp[x] = max(dp[x], dp[h] - d + b[x]);
    }
    ans = max(ans, dp[x]);
}

void dfs1(int x, int p, long long dpp, int dd)
{
    multiset<long long> s;
    if (dpp >= dd)
        ans = max(ans, dpp - dd + b[x]);
    if (dpp >= dd)
        s.insert(dpp - dd + b[x]);
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        int d = a[x][i].second;
        if (h == p)
            continue;
        if (dp[h] >= d)
            s.insert(dp[h] - d + b[x]);
    }
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        int d = a[x][i].second;
        if (h == p)
            continue;
        if (dp[h] >= d)
            s.erase(s.find(dp[h] - d + b[x]));
        if (!s.empty())
            dfs1(h, x, *(--s.end()), d);
        else
            dfs1(h, x, 0, 0);
        if (dp[h] >= d)
            s.insert(dp[h] - d + b[x]);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a[x].push_back(m_p(y, z));
        a[y].push_back(m_p(x, z));
    }
    dfs(1, 1);
    dfs1(1, 1, 0, 0);
    cout << ans << endl;
    return 0;
}