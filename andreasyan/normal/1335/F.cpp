#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1000006;
const long long INF = 1000000009000000009;
const int xx[4] = {-1, 1, 0, 0};
const int yy[4] = {0, 0, 1, -1};
const char uu[4] = {'U', 'D', 'R', 'L'};

int n, m;
char** c;
char** a;

int** cc;
pair<int, int>** p;

pair<int, int> s, f;
bool dfs(int x, int y)
{
    cc[x][y] = 1;
    for (int i = 0; i < 4; ++i)
    {
        if (a[x][y] == uu[i])
        {
            int hx = x + xx[i];
            int hy = y + yy[i];
            if (cc[hx][hy] == 1)
            {
                s = m_p(hx, hy);
                f = m_p(x, y);
                cc[x][y] = 2;
                return true;
            }
            else if (cc[hx][hy] == 0)
            {
                p[hx][hy] = m_p(x, y);
                if (dfs(hx, hy))
                {
                    cc[x][y] = 2;
                    return true;
                }
            }
        }
    }
    cc[x][y] = 2;
    return false;
}

int yvs;
bool gg[N];

void dfs1(int x, int y, int s, int d)
{
    if (c[x][y] == '0')
        gg[(d + s) % yvs] = true;
    for (int i = 0; i < 4; ++i)
    {
        int hx = x + xx[i];
        int hy = y + yy[i];
        if (hx >= 0 && hx < n && hy >= 0 && hy < m && a[hx][hy] == uu[(i ^ 1)] && !cc[hx][hy])
            dfs1(hx, hy, s, d + 1);
    }
}

void solv()
{
    scanf("%d%d", &n, &m);
    c = new char*[n + 5];
    for (int i = 0; i < n; ++i)
        c[i] = new char[m + 5];
    a = new char*[n + 5];
    for (int i = 0; i < n; ++i)
        a[i] = new char[m + 5];
    for (int i = 0; i < n; ++i)
        scanf(" %s", c[i]);
    for (int i = 0; i < n; ++i)
        scanf(" %s", a[i]);
    cc = new int*[n + 5];
    for (int i = 0; i < n; ++i)
        cc[i] = new int[m + 5];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cc[i][j] = 0;
    p = new pair<int, int>*[n + 5];
    for (int i = 0; i < n; ++i)
    {
        p[i] = new pair<int, int>[m + 5];
    }
    vector<vector<pair<int, int> > > vv;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (cc[i][j] == 0)
            {
                if (dfs(i, j))
                {
                    vector<pair<int, int> > v;
                    for (pair<int, int> u = f; u != s; u = p[u.first][u.second])
                    {
                        v.push_back(u);
                    }
                    v.push_back(s);
                    vv.push_back(v);
                }
            }
        }
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cc[i][j] = 0;
    int ans1 = 0, ans2 = 0;
    for (int ii = 0; ii < vv.size(); ++ii)
    {
        vector<pair<int, int> > v = vv[ii];
        yvs = v.size();
        for (int i = 0; i < v.size(); ++i)
        {
            cc[v[i].first][v[i].second] = 1;
        }
        for (int i = 0; i < v.size(); ++i)
            gg[i] = false;
        for (int i = 0; i < v.size(); ++i)
        {
            dfs1(v[i].first, v[i].second, i, 0);
        }
        ans1 += v.size();
        for (int i = 0; i < v.size(); ++i)
        {
            if (gg[i])
                ++ans2;
        }
    }
    printf("%d %d\n", ans1, ans2);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}