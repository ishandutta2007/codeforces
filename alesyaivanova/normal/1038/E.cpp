#include <bits/stdc++.h>

using namespace std;

int n;
pair<int, pair<int, int> > ed[100];
vector<pair<int, int> > g[4];
bool used[4];
long long sum[4];

long long dfs(int v, int& num1, int& num2, int w)
{
    used[v] = true;
    int sz = g[v].size();
    long long ans = sum[v];
    if (w != -1 && v == ed[w].second.first)
    {
        sz--;
        ans -= ed[w].first;
    }
    if (w != -1 && v == ed[w].second.second)
    {
        sz--;
        ans -= ed[w].first;
    }
    if (sz % 2 == 1)
        num1++;
    else
        num2++;
    for (pair<int, int> to : g[v])
    {
        if (!used[to.first] && to.second != w)
            ans += dfs(to.first, num1, num2, w);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        c--;
        ed[i].first = b;
        ed[i].second.first = a;
        ed[i].second.second = c;
        g[a].emplace_back(c, i);
        g[c].emplace_back(a, i);
    }
    for (int i = 0; i < 4; i++)
    {
        for (pair<int, int> v: g[i])
            sum[i] += ed[v.second].first;
    }
    long long ans = 0;
    for (int i = 0; i < 4; i++)
    {
        if (!used[i])
        {
            int num1 = 0;
            int num2 = 0;
            long long cur = dfs(i, num1, num2, -1);
            if (num1 <= 2)
                ans = max(ans, cur);
        }
    }
    for (int j = 0; j < n; j++)
    {
        for (int e = 0; e < 4; e++)
            used[e] = false;
        for (int i = 0; i < 4; i++)
        {
            if (!used[i])
            {
                int num1 = 0;
                int num2 = 0;
                long long cur = dfs(i, num1, num2, j);
                if (num1 <= 2)
                    ans = max(ans, cur);
            }
        }
    }
    cout << ans / 2;
}