#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 1003, m = 2520;

int n;
int b[N];
vector<int> a[N];

pair<int, int> p[N][m];
int c[N][m];

pair<int, int> g[N][m];

void dfs(int x, int i)
{
    if (c[g[x][i].first][g[x][i].second])
    {
        if (c[g[x][i].first][g[x][i].second] != -1)
        {
            c[x][i] = c[g[x][i].first][g[x][i].second];
            return;
        }
        set<int> s;
        pair<int, int> u = m_p(x, i);
        int q = 0;
        while (1)
        {
            s.insert(u.first);
            if (u == g[x][i])
                break;
            u = p[u.first][u.second];
        }
        c[x][i] = s.size();
        return;
    }
    c[x][i] = -1;
    p[g[x][i].first][g[x][i].second] = m_p(x, i);
    dfs(g[x][i].first, g[x][i].second);
    c[x][i] = c[g[x][i].first][g[x][i].second];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int x = 1; x <= n; ++x)
        cin >> b[x];
    for (int x = 1; x <= n; ++x)
    {
        int q;
        cin >> q;
        while (q--)
        {
            int y;
            cin >> y;
            a[x].push_back(y);
        }
    }
    for (int x = 1; x <= n; ++x)
    {
        for (int i = 0; i < m; ++i)
        {
            g[x][i] = m_p(a[x][i % a[x].size()], ((i + b[a[x][i % a[x].size()]]) % m + m) % m);
        }
    }
    for (int x = 1; x <= n; ++x)
    {
        for (int i = 0; i < m; ++i)
        {
            if (!c[x][i])
                dfs(x, i);
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x, i;
        cin >> x >> i;
        i += b[x];
        i = i % m;
        if (i < 0)
            i += m;
        cout << c[x][i] << endl;
    }
    return 0;
}