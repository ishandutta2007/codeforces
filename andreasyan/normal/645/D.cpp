#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 100005;

int n, m;
pair<int, int> b[N];
vector<int> a[N];

int dp[N];
bool c[N];
void dfs(int x)
{
    c[x] = true;
    dp[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (!c[h])
            dfs(h);
        dp[x] = max(dp[x], dp[h] + 1);
    }
}

set<pair<int, int> > s;

int u[N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &b[i].first, &b[i].second);
        a[b[i].first].push_back(b[i].second);
    }
    int maxu = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
            dfs(i);
        maxu = max(maxu, dp[i]);
    }
    if (maxu < n)
    {
        printf("-1\n");
        return 0;
    }
    for (int i = 1; i <= n; ++i)
        u[n - dp[i] + 1] = i;
    for (int i = 1; i < n; ++i)
        s.insert(m_p(u[i], u[i + 1]));
    for (int i = 0; i < m; ++i)
    {
        if (s.find(b[i]) != s.end())
        {
            s.erase(b[i]);
        }
        if (s.empty())
        {
            printf("%d\n", i + 1);
            return 0;
        }
    }
    return 0;
}