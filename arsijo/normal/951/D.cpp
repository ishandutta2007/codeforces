#include <bits/stdc++.h>

using namespace std;

const int MaxN = 5e5 + 15;

const int MaxK = 20;

int n, k, m;
vector <pair<int, int> > v[MaxN];

int sz[MaxN], tin[MaxN], tout[MaxN], timer;
int nxt[MaxN];

int jump[MaxN][MaxK];

set<int> s;

int p[MaxN];

int findset(int x)
{
    if(p[x] != x)
        p[x] = findset(p[x]);
    return p[x];
}

bool unionset(int x, int y)
{
    x = findset(x);
    y = findset(y);

    if(x == y)
        return false;

    if(rand() & 1)
        p[x] = y;
    else
        p[y] = x;

    return true;
}

void clearSet()
{
    for(int i = 1; i <= n; ++i)
        p[i] = i;
}

void dfs(int x, int p = 0)
{
    sz[x] = 1;

    for(int i = 0; i < v[x].size(); ++i)
    {
        if(v[x][i].first == p)
        {
            v[x].erase(v[x].begin() + i);
            --i;
        }else
        {
            dfs(v[x][i].first, x);

            sz[x] += sz[v[x][i].first];

            if(sz[v[x][i].first] > sz[v[x][0].first])
                swap(v[x][i], v[x][0]);
        }
    }
}

void hld(int x, int p = 0)
{
    tin[x] = ++timer;
    jump[x][0] = p;

    if(!nxt[x])
        nxt[x] = x;

    for(int i = 1; i < MaxK; ++i)
        jump[x][i] = jump[jump[x][i - 1]][i - 1];

    if(!v[x].empty())
    {
        if(!v[x][0].second)
            s.insert(timer + 1);
        nxt[v[x][0].first] = nxt[x];
        hld(v[x][0].first, x);

        for(int i = 1; i < v[x].size(); ++i)
        {
            if(!v[x][i].second)
                s.insert(timer + 1);
            hld(v[x][i].first, x);
        }
    }

    tout[x] = timer;
}

bool isParent(int x, int y)
{
    return tin[x] <= tin[y] && tout[x] >= tout[y];
}

int lca(int x, int y)
{
    if(isParent(x, y))
        return x;
    if(isParent(y, x))
        return y;

    for(int i = MaxK - 1; i >= 0; --i)
        if(jump[x][i])
            if(!isParent(jump[x][i], y))
                x = jump[x][i];

    return jump[x][0];
}

long long ans = 0;

set<int> :: iterator it;

void setCostUp(int x, int y, int c)
{
    while(tin[x] > tin[y] && x != 0)
    {
        int to;

        if(isParent(y, nxt[x]))
            to = nxt[x];
        else
            to = y;

        int l = tin[to];

        if(to == y)
            ++l;

        int r = tin[x];

        it = s.lower_bound(l);
        while(it != s.end() && (*it) <= r)
        {
            ans += c;
            s.erase(it);
            it = s.lower_bound(l);
        }

        x = jump[to][0];
    }
}

void setCost(int a, int b, int c)
{
    int o = lca(a, b);

    if(o == a)
        setCostUp(b, o, c);
    else
    if(o == b)
        setCostUp(a, o, c);
    else
    {
        setCostUp(a, o, c);
        setCostUp(b, o, c);
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(NULL));

    cin >> n;

    cin >> k >> m;

    clearSet();

    for(int i = 1; i <= k; ++i)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(make_pair(y, 0));
        v[y].push_back(make_pair(x, 0));

        unionset(x, y);
    }

    vector <pair<int, pair<int, int> > > edges2, edges;

    for(int i = 1; i <= m; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;

        edges2.push_back({z, {x, y}});
    }

    sort(edges2.begin(), edges2.end());

    for(auto p : edges2)
    {
        int x = p.second.first;
        int y = p.second.second;

        if(unionset(x, y))
        {
            v[x].push_back({y, p.first});
            v[y].push_back({x, p.first});
        }else
            edges.push_back(p);
    }

    dfs(1);
    hld(1);

    for(auto p : edges)
        setCost(p.second.first, p.second.second, p.first);

    if(!s.empty())
        ans = -1;

    cout << ans << '\n';

    return 0;
}