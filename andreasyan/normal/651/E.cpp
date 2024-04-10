#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 1000006;

int n, m;
int **a;

map<int, vector<pair<int, int> > > mp;

bool **c;
int **ans;

int maxt[N], maxs[N];
vector<int> vt[N], vs[N];

void dfs(int x, int y, int u)
{
    ans[x][y] = u;
    maxt[x] = max(maxt[x], ans[x][y]);
    maxs[y] = max(maxs[y], ans[x][y]);
    c[x][y] = true;
    vector<pair<int, int> > v;
    for (int i = 0; i < vt[x].size(); ++i)
        v.push_back(m_p(x, vt[x][i]));
    for (int i = 0; i < vs[y].size(); ++i)
        v.push_back(m_p(vs[y][i], y));
    vt[x].clear();
    vs[y].clear();
    for (int i = 0; i < v.size(); ++i)
    {
        if (!c[v[i].first][v[i].second])
            dfs(v[i].first, v[i].second, u);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    a = new int*[n + 5];
    for (int i = 0; i < n + 5; ++i)
        a[i] = new int[m + 5];
    for (int i = 0; i < n + 5; ++i)
        for (int j = 0; j < m + 5; ++j)
            a[i][j] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            scanf("%d", &a[i][j]);
            mp[a[i][j]].push_back(m_p(i, j));
        }
    }
    ans = new int*[n + 5];
    for (int i = 0; i < n + 5; ++i)
        ans[i] = new int[m + 5];
    for (int i = 0; i < n + 5; ++i)
        for (int j = 0; j < m + 5; ++j)
            ans[i][j] = 0;
    c = new bool*[n + 5];
    for (int i = 0; i < n + 5; ++i)
        c[i] = new bool[m + 5];
    for (int i = 0; i < n + 5; ++i)
        for (int j = 0; j < m + 5; ++j)
            c[i][j] = false;
    for (map<int, vector<pair<int, int> > >::iterator it = mp.begin(); it != mp.end(); ++it)
    {
        vector<pair<int, pair<int, int> > > v;
        for (int i = 0; i < it->second.size(); ++i)
        {
            int x = it->second[i].first;
            int y = it->second[i].second;
            v.push_back(m_p(max(maxt[x], maxs[y]) + 1, it->second[i]));
            vt[x].push_back(y);
            vs[y].push_back(x);
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        for (int i = 0; i < v.size(); ++i)
        {
            int x = v[i].second.first;
            int y = v[i].second.second;
            if (c[x][y])
                continue;
            ans[x][y] = v[i].first;
            maxt[x] = max(maxt[x], ans[x][y]);
            maxs[y] = max(maxs[y], ans[x][y]);
            dfs(x, y, ans[x][y]);
        }
        /*printf("\n");
        printf("\n");
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
                printf("%d ", ans[i][j]);
            printf("\n");
        }*/
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            printf("%d ", ans[i][j]);
        printf("\n");
    }
    return 0;
}