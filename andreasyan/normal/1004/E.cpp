#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 100005, INF = 1000000009;

int n, k;
vector<pair<int, int> > a[N];
vector<int> v[N];

int d[N];
void dfs0(int x, int p)
{
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        if (h == p)
            continue;
        dfs0(h, x);
        v[x][i] = a[x][i].second + d[h];
        d[x] = max(d[x], v[x][i]);
    }
}
void dfs1(int x, int p, int dp)
{
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        if (h == p)
        {
            v[x][i] = a[x][i].second + dp;
            break;
        }
    }
    multiset<int> s;
    for (int i = 0; i < a[x].size(); ++i)
    {
        s.insert(v[x][i]);
    }
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        if (h == p)
            continue;
        s.erase(s.find(v[x][i]));
        if (!s.empty())
            dfs1(h, x, *(--s.end()));
        else
            dfs1(h, x, 0);
        s.insert(v[x][i]);
    }
}

int q[N];
void dfs2(int x, int p, int dd)
{
    int qq = 0;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        if (h == p)
            continue;
        dfs2(h, x, dd);
        if (v[x][i] > dd)
            ++qq;
    }
    if (qq > 1)
    {
        q[x] = N;
        return;
    }
    if (qq == 0)
    {
        q[x] = 1;
        return;
    }
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        if (h == p)
            continue;
        if (v[x][i] > dd)
        {
            q[x] = q[h] + 1;
        }
    }
}

bool dfs3(int x, int p, int dd)
{
    bool z = true;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        if (h == p)
        {
            if (v[x][i] > dd)
            {
                z = false;
            }
            break;
        }
    }
    int qq = 0;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        if (h == p)
            continue;
        if (v[x][i] > dd)
        {
            ++qq;
        }
    }
    if (qq > 2)
        z = false;
    int kk = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        if (h == p)
            continue;
        if (v[x][i] > dd)
        {
            kk += q[h];
        }
    }
    if (kk > k)
        z = false;
    if (z)
        return true;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        if (h == p)
            continue;
        if (dfs3(h, x, dd))
            return true;
    }
    return false;
}

bool stg(int dd)
{
    dfs2(1, 1, dd);
    return dfs3(1, 1, dd);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[x].push_back(m_p(y, z));
        a[y].push_back(m_p(x, z));
    }
    for (int i = 1; i <= n; ++i)
        v[i].assign(a[i].size(), 0);
    dfs0(1, 1);
    dfs1(1, 1, 0);
    /*for (int x = 1; x <= n; ++x)
    {
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i].first;
            cout << x << ' ' << h << ' ' << v[x][i] << endl;
        }
    }*/
    int l = 0, r = INF;
    int ans;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(m))
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    cout << ans << endl;
    return 0;
}