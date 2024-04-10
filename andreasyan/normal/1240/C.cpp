#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 500005;
const long long INF = 1000000000000015;

int n, k;
vector<pair<int, int> > a[N];

long long dp[N][2];

long long s[N];

void dfs(int x, int p)
{
    dp[x][0] = dp[x][1] = -INF;
    vector<pair<long long, int> > v;
    for (int i = 0; i < a[x].size(); ++i)
    {
        pair<int, int> h = a[x][i];
        if (h.first == p)
            continue;
        dfs(h.first, x);
        v.push_back(m_p(dp[h.first][0] + h.second - max(dp[h.first][0], dp[h.first][1]), h.first));
    }
    if (v.empty())
    {
        dp[x][0] = 0;
        return;
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    s[v.size()] = 0;
    for (int i = v.size() - 1; i >= 0; --i)
        s[i] = max(dp[v[i].second][0], dp[v[i].second][1]) + s[i + 1];
    dp[x][0] = s[0];
    long long pf = 0;
    for (int i = 0; i < min((int)v.size(), k); ++i)
    {
        pf += v[i].first + max(dp[v[i].second][0], dp[v[i].second][1]);
        if (i < k - 1)
            dp[x][0] = max(dp[x][0], pf + s[i + 1]);
        else
            dp[x][1] = pf + s[i + 1];
    }
}

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        a[i].clear();
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[x].push_back(m_p(y, z));
        a[y].push_back(m_p(x, z));
    }
    dfs(1, 1);
    printf("%lld\n", max(dp[1][0], dp[1][1]));
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}