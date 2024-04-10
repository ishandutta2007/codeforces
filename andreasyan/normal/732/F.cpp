#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 400005;
struct ban
{
    int x, i;
    ban(){}
    ban(int x, int i)
    {
        this->x = x;
        this->i = i;
    }
};

int n, m;
vector<ban> a[N];

bool cc[N];

int tim;
int tin[N], fup[N];
int c[N];

void dfs(int x, int p)
{
    c[x] = true;
    fup[x] = tin[x] = tim++;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].x;
        if (h == p)
            continue;
        if (c[h])
            fup[x] = min(fup[x], tin[h]);
        else
        {
            dfs(h, x);
            if (fup[h] > tin[x])
                cc[a[x][i].i] = true;
            fup[x] = min(fup[x], fup[h]);
        }
    }
}

int q[N];
int k;
void dfs2(int x)
{
    ++q[k];
    c[x] = k;
    for (int i = 0; i < a[x].size(); ++i)
    {
        if (cc[a[x][i].i])
            continue;
        int h = a[x][i].x;
        if (!c[h])
            dfs2(h);
    }
}

pair<int, int> ans[N];

void dfs3(int x)
{
    cc[x] = true;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].x;
        if (c[x] != c[h])
            continue;
        ans[a[x][i].i] = m_p(x, h);
        if (!cc[h])
        {
            dfs3(h);
        }
    }
}

vector<ban> g[N];
vector<pair<int, int> > gg[N];

void dfs4(int x, int p)
{
    for (int i = 0; i < g[x].size(); ++i)
    {
        if (p == g[x][i].x)
            continue;
        ans[g[x][i].i] = gg[x][i];
        dfs4(g[x][i].x, x);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    //cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        //cin >> x >> y;
        a[x].push_back(ban(y, i));
        a[y].push_back(ban(x, i));
        ans[i] = m_p(x, y);
    }
    dfs(1, -1);
    for (int i = 1; i <= n; ++i)
        c[i] = false;
    int ans1 = 0, ansi;
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
        {
            ++k;
            dfs2(i);
            if (q[k] > ans1)
            {
                ans1 = q[k];
                ansi = k;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        cc[i] = false;
    for (int i = 1; i <= n; ++i)
    {
        if (!cc[i])
        {
            dfs3(i);
        }
    }
    for (int i = 0; i < m; ++i)
    {
        int x = ans[i].first, y = ans[i].second;
        if (c[x] != c[y])
        {
            g[c[x]].push_back(ban(c[y], i));
            gg[c[x]].push_back(m_p(y, x));
            g[c[y]].push_back(ban(c[x], i));
            gg[c[y]].push_back(m_p(x, y));
        }
    }
    dfs4(ansi, -1);
    ////////////////////////////
    printf("%d\n", ans1);
    //cout << ans1 << endl;
    for (int i = 0; i < m; ++i)
        printf("%d %d\n", ans[i].first, ans[i].second);
        //cout << ans[i].first << ' ' << ans[i].second << endl;
    return 0;
}