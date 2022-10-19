#include <bits/stdc++.h>
using namespace std;
const int N = 500005;

int n;
int a[N];

vector<int> g[N];

set<int> c1, c2;

bool dfs(int x)
{
    c1.erase(x);
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (c1.find(h) != c1.end() && c2.find(h) != c2.end())
        {
            if (dfs(h))
                return true;
        }
        else if (c1.find(h) == c1.end() && c2.find(h) != c2.end())
        {
            return true;
        }
    }
    while (1)
    {
        set<int>::iterator it;
        it = c2.lower_bound(x + 1);
        if (*it >= a[x])
            break;
        int h = *it;
        if (c1.find(h) != c1.end() && c2.find(h) != c2.end())
        {
            if (dfs(h))
                return true;
        }
        else if (c1.find(h) == c1.end() && c2.find(h) != c2.end())
        {
            return true;
        }
    }
    c2.erase(x);
    return false;
}

set<int> c;
vector<int> v;
void dfs1(int x)
{
    c.erase(x);
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (c.find(h) != c.end())
            dfs1(h);
    }
    while (1)
    {
        set<int>::iterator it = c.lower_bound(x + 1);
        if (*it >= a[x])
            break;
        int h = *it;
        dfs1(h);
    }
    v.push_back(x);
}

int ans[N];
void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        g[i].clear();
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        g[a[i]].push_back(i);
    }

    c1.clear();
    c2.clear();
    for (int i = 1; i <= n + 1; ++i)
    {
        c1.insert(i);
        c2.insert(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (c1.find(i) != c1.end() && c2.find(i) != c2.end())
        {
            if (dfs(i))
            {
                cout << "-1" << endl;
                return;
            }
        }
    }

    v.clear();
    c.clear();
    for (int i = 1; i <= n + 1; ++i)
        c.insert(i);
    for (int i = 1; i <= n; ++i)
    {
        if (c.find(i) != c.end())
            dfs1(i);
    }

    for (int i = 0; i < v.size(); ++i)
        ans[v[i]] = i + 1;

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int tt;
    cin >> tt;
    while (tt--)
        solv();
    return 0;
}