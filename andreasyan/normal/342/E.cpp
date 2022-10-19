#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 100005;
int s;

int n, m;
vector<int> a[N];
pair<int, int> b[N];

int p[N];
int fi(int x)
{
    if (p[x] == x)
        return x;
    return p[x] = fi(p[x]);
}
void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    p[x] = y;
}

int ans[N];

vector<pair<int, int> > v[N];

int d[N];
void dfs(int x, int p)
{
    d[x] = d[p] + 1;
    for (int i = 0; i < v[x].size(); ++i)
    {
        int y = v[x][i].first;
        if (d[y])
        {
            int z = fi(y);
            ans[v[x][i].second] = min(ans[v[x][i].second], d[x] + d[y] - 2 * d[z]);
        }
    }
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        kpc(h, x);
    }
}

queue<int> q;

void bfs()
{
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i];
            if (d[x] + 1 < d[h])
            {
                d[h] = d[x] + 1;
                q.push(h);
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    b[0] = m_p(1, 1);
    for (int i = 1; i <= m; ++i)
        scanf("%d%d", &b[i].first, &b[i].second);
    ++m;
    s = sqrt(m);
    for (int i = 0; i < m; ++i)
        ans[i] = N;
    for (int i = 0; i < m; ++i)
    {
        if (b[i].first == 2)
        {
            for (int j = i; j >= 0 && (j / s) == (i / s); --j)
            {
                if (b[j].first == 2)
                    continue;
                v[b[i].second].push_back(m_p(b[j].second, i));
                v[b[j].second].push_back(m_p(b[i].second, i));
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        p[i] = i;
    dfs(1, 1);
    for (int i = 1; i <= n; ++i)
        d[i] = N;
    for (int i = 0; i < m; ++i)
    {
        if (i > 0 && (i - 1) / s != (i / s))
        {
            for (int j = ((i - 1) / s) * s; (j / s) == ((i - 1) / s); ++j)
            {
                if (b[j].first == 1)
                {
                    d[b[j].second] = 0;
                    q.push(b[j].second);
                }
            }
            bfs();
        }
        if (b[i].first == 2)
        {
            ans[i] = min(ans[i], d[b[i].second]);
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}