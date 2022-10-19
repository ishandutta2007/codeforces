#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n, k;
vector<int> a[N];

int d[N];
void dfs0(int x, int p)
{
    d[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs0(h, x);
        d[x] = max(d[x], d[h] + 1);
    }
}

void dfs1(int x, int p, int dp)
{
    multiset<int> s;
    if (dp)
        s.insert(dp);
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        s.insert(d[h]);
    }
    if (k != 2 && s.size() >= 3 && *(--(--(--s.end()))) + *(--(--s.end())) + 1 >= k)
    {
        printf("No");
        exit(0);
    }
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        s.erase(s.find(d[h]));
        if (s.empty())
            dfs1(h, x, 1);
        else
            dfs1(h, x, *(--s.end()) + 1);
        s.insert(d[h]);
    }
}

vector<int> v;
int c[N];

void dfs2(int x, int p, int u)
{
    c[x] = u;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (c[h])
            continue;
        dfs2(h, x, (u % k) + 1);
    }
}
void dfs3(int x, int p, int u)
{
    c[x] = u;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (c[h])
            continue;
        dfs3(h, x, (u - 2 + k) % k + 1);
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs0(1, 1);
    dfs1(1, 1, 0);
    printf("Yes\n");
//////////////////////////////////////////////////////////////
    int x = 1;
    dfs0(x, x);
    while (1)
    {
        int maxu = 0, maxx;
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i];
            if (d[h] > d[x])
                continue;
            if (d[h] > maxu)
            {
                maxu = d[h];
                maxx = h;
            }
        }
        if (!maxu)
            break;
        x = maxx;
    }
    dfs0(x, x);
    while (1)
    {
        v.push_back(x);
        int maxu = 0, maxx;
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i];
            if (d[h] > d[x])
                continue;
            if (d[h] > maxu)
            {
                maxu = d[h];
                maxx = h;
            }
        }
        if (!maxu)
            break;
        x = maxx;
    }
    int u = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        c[v[i]] = u + 1;
        u = (u + 1) % k;
    }
    for (int i = 0; i < v.size(); ++i)
    {
        if ((v.size() - i) < (i + 1))
        {
            dfs2(v[i], v[i], c[v[i]]);
        }
        else
        {
            dfs3(v[i], v[i], c[v[i]]);
        }
    }
    for (int i = 1; i <= n; ++i)
        printf("%d ", c[i]);
    printf("\n");
    return 0;
}