#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
int a[N][3];
set<int> s[N];
set<int> g[N];
vector<int> gg[N];

int p[N];
int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}
void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    p[x] = y;
}

int q[N];

bool c[N];
void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        s[i].clear();
        g[i].clear();
        gg[i].clear();
        p[i] = i;
        q[i] = 0;
        c[i] = false;
    }
    for (int i = 1; i <= n - 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            scanf("%d", &a[i][j]);
            s[a[i][j]].insert(i);
        }
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                if (j == k)
                    continue;
                g[a[i][j]].insert(a[i][k]);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        q[i] = g[i].size();
    queue<int> qq;
    for (int i = 1; i <= n; ++i)
    {
        if (q[i] == 2)
            qq.push(i);
    }
    vector<int> v;
    while (!qq.empty())
    {
        int x = qq.front();
        qq.pop();
        if (s[x].empty())
            break;
        v.push_back(*s[x].begin());
        for (set<int>::iterator it = g[x].begin(); it != g[x].end(); ++it)
        {
            int h = (*it);
            if (fi(x) != fi(h))
            {
                gg[x].push_back(h);
                gg[h].push_back(x);
                kpc(x, h);
            }
            --q[x];
            --q[h];
            s[h].erase(*s[x].begin());
            if (q[h] == 2)
                qq.push(h);
        }
    }
    int x;
    for (int i = 1; i <= n; ++i)
    {
        if (gg[i].size() == 1)
            x = i;
    }
    for (int ii = 0; ii < n; ++ii)
    {
        printf("%d ", x);
        c[x] = true;
        for (int i = 0; i < gg[x].size(); ++i)
        {
            int h = gg[x][i];
            if (c[h])
                continue;
            x = h;
            break;
        }
    }
    printf("\n");
    for (int i = 0; i < v.size(); ++i)
        printf("%d ", v[i]);
    printf("\n");
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}