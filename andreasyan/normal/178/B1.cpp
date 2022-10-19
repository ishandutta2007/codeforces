#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 100005;

int n, m;
vector<int> a[N];

vector<pair<int, int> > v;
set<pair<int, int> > s;

int c[N];
int tin[N], fup[N];
int ti;
void dfs(int x, int p)
{
    c[x] = 1;
    fup[x] = tin[x] = ti++;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        if (c[h])
        {
            fup[x] = min(fup[x], tin[h]);
        }
        else
        {
            dfs(h, x);
            fup[x] = min(fup[x], fup[h]);
            if (fup[h] > tin[x])
            {
                // kamurj
                v.push_back(m_p(x, h));
                s.insert(m_p(x, h));
                s.insert(m_p(h, x));
            }
        }
    }
}

int k;
vector<int> t[N];

void dfs1(int x)
{
    c[x] = k;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (s.find(m_p(x, h)) != s.end())
            continue;
        if (!c[h])
            dfs1(h);
    }
}

int l;
int t_tin[N], t_tout[N];
int p[N][20];
int d[N];
void dfs2(int x, int pp)
{
    t_tin[x] = ti++;

    d[x] = d[pp] + 1;
    p[x][0] = pp;
    for (int i = 1; i <= l; ++i)
        p[x][i] = p[p[x][i - 1]][i - 1];

    for (int i = 0; i < t[x].size(); ++i)
    {
        int h = t[x][i];
        if (h == pp)
            continue;
        dfs2(h, x);
    }

    t_tout[x] = ti++;
}

bool pp(int x, int y)
{
    return (t_tin[x] <= t_tin[y] && t_tout[x] >= t_tout[y]);
}
int lca(int x, int y)
{
    if (pp(x, y))
        return x;
    if (pp(y, x))
        return y;
    for (int i = l; i >= 0; --i)
    {
        if (!pp(p[x][i], y))
            x = p[x][i];
    }
    return p[x][0];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, -1);
    for (int x = 1; x <= n; ++x)
        c[x] = 0;
    for (int x = 1; x <= n; ++x)
    {
        if (!c[x])
        {
            ++k;
            dfs1(x);
        }
    }
    for (int i = 0; i < v.size(); ++i)
    {
        t[c[v[i].first]].push_back(c[v[i].second]);
        t[c[v[i].second]].push_back(c[v[i].first]);
    }

    while ((1 << l) < k)
        ++l;
    dfs2(1, 1);

    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        x = c[x];
        y = c[y];
        int z = lca(x, y);
        cout << d[x] + d[y] - d[z] * 2 << endl;
    }
    return 0;
}