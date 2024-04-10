#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 7;
vector <int> g[N];
ll sum[N];
int a[N];
ll res = 0;

void dfs(int v, int pr)
{
    sum[v] = a[v];
    for (auto to: g[v])
    {
        if (to != pr)
        {
            dfs(to, v);
            sum[v] += sum[to];
        }
    }
}

void des(int v, int pr)
{
    for (auto to: g[v])
    {
        if (to != pr)
        {
            des(to, v);
            sum[v] = max(sum[v], sum[to]);
        }
    }
}

void dfs(int v, int pr, ll kek)
{
    if (kek != LLONG_MIN)
    {
        res = max(res, kek + sum[v]);
    }
    multiset <ll> s;
    for (auto to: g[v])
    {
        if (to != pr)
        {
            s.insert(sum[to]);
        }
    }
    for (auto to: g[v])
    {
        if (to != pr)
        {
            s.erase(s.find(sum[to]));
            dfs(to, v, max(kek, (s.size() == 0 ? LLONG_MIN : *s.rbegin())));
            s.insert(sum[to]);
        }
    }
}



int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    res = LLONG_MIN;
    dfs(1, -1);
    des(1, -1);
    dfs(1, -1, LLONG_MIN);
    if (res == LLONG_MIN)
    {
        puts("Impossible");
    }
    else
    {
        printf("%lld\n", res);
    }
}