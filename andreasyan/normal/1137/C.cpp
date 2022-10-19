#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 100005, D = 52;

int n, m, d;
pair<int, int> k[N];
char u[N][D];

vector<int> a[N * D];

int c[N * D];

vector<int> v;
void dfs0(int x)
{
    c[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (!c[h])
            dfs0(h);
    }
    v.push_back(x);
}
int z;
void dfs1(int x)
{
    c[x] = z;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (!c[h])
            dfs1(h);
    }
}

int ss[N * D];

void dfs(int x)
{
    c[x] = 1;
    int maxu = 0;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (!c[h])
            dfs(h);
        maxu = max(maxu, ss[h]);
    }
    ss[x] += maxu;
}

int main()
{
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 0; i < m; ++i)
        scanf("%d%d", &k[i].first, &k[i].second);
    for (int x = 1; x <= n; ++x)
    {
        scanf(" %s", u[x]);
    }
    for (int i = 0; i < m; ++i)
    {
        int x = k[i].first;
        int y = k[i].second;
        for (int j = 0; j < d; ++j)
        {
            int jj = (j + 1) % d;
            a[(x - 1) * d + j].push_back((y - 1) * d + jj);
        }
    }
    for (int i = 0; i < n * d; ++i)
    {
        if (!c[i])
            dfs0(i);
    }
    for (int x = 0; x < n * d; ++x)
        a[x].clear();
    for (int i = 0; i < m; ++i)
    {
        int x = k[i].first;
        int y = k[i].second;
        for (int j = 0; j < d; ++j)
        {
            int jj = (j + 1) % d;
            a[(y - 1) * d + jj].push_back((x - 1) * d + j);
        }
    }
    reverse(v.begin(), v.end());
    memset(c, 0, sizeof c);
    for (int i = 0; i < n * d; ++i)
    {
        if(!c[v[i]])
        {
            ++z;
            dfs1(v[i]);
        }
    }
    v.clear();
    for (int x = 0; x < n * d; ++x)
        a[x].clear();
    for (int x = 1; x <= n; ++x)
    {
        for (int j = 0; j < d; ++j)
        {
            if (u[x][j] == '1')
                a[c[(x - 1) * d + j]].push_back(x);
        }
    }
    for (int i = 1; i <= z; ++i)
    {
        sort(a[i].begin(), a[i].end());
        for (int j = 0; j < a[i].size(); ++j)
        {
            if (!j || a[i][j] != a[i][j - 1])
                ++ss[i];
        }
        a[i].clear();
    }
    for (int i = 0; i < m; ++i)
    {
        int x = k[i].first;
        int y = k[i].second;
        for (int j = 0; j < d; ++j)
        {
            int jj = (j + 1) % d;
            if (c[(x - 1) * d + j] != c[(y - 1) * d + jj])
                a[c[(x - 1) * d + j]].push_back(c[(y - 1) * d + jj]);
        }
    }
    int st = c[0];
    memset(c, 0, sizeof c);
    dfs(st);
    cout << ss[st] << endl;
    return 0;
}