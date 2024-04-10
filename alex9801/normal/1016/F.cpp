#include<bits/stdc++.h>
using namespace std;

struct edg
{
    int x, w;
};

int n, m;
vector<edg> adj[300010];

bool f(int x, int p, vector<int>& v)
{
    v.push_back(x);
    if(x == n)
        return 1;
    for(auto [y, w] : adj[x])
    {
        if(y == p)
            continue;

        if(f(y, x, v))
            return 1;
    }
    v.pop_back();
    return 0;
}

int val[300010];
long long sum[300010];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n - 1; i++)
    {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        adj[x].push_back({ y, w });
        adj[y].push_back({ x, w });
    }

    bool ok = 1;

    vector<int> v;
    assert(f(1, -1, v));
    int sz = (int)v.size();
    assert(sz >= 2);

    int cnt = sz;
    for(int i = 0; i < sz; i++)
    {
        for(auto [y, w] : adj[v[i]])
        {
            if(i != 0 && y == v[i - 1])
                sum[i] = sum[i - 1] + w;
            else if(i == sz - 1 || y != v[i + 1])
            {
                if(val[i])
                    ok = 0;
                else
                {
                    cnt++;
                    val[i] = w;
                }
            }
        }
    }
    if(cnt != n)
        ok = 0;

    if(!ok)
    {
        for(int i = 0; i < m; i++)
            printf("%lld\n", sum[sz - 1]);
        return 0;
    }

    long long mem = 1e18, mem2 = 1e18, save = 1e18;
    for(int i = 0; i < sz; i++)
    {
        if(i != 0)
        {
            if(val[i] != 0)
                save = min(save, sum[i] - val[i] + mem);
            else
                save = min(save, sum[i] - val[i] + mem2);
        }

        mem = min(mem, -sum[i] - val[i]);
        if(i != 0 && val[i - 1] == 0)
            mem2 = min(mem2, -sum[i - 1] - val[i - 1]);
        if(val[i] != 0)
            mem2 = min(mem2, -sum[i] - val[i]);
    }

    for(int i = 0; i < m; i++)
    {
        int nw;
        scanf("%d", &nw);

        long long res = sum[sz - 1] - max(0LL, save - nw);
        printf("%lld\n", res);
    }
    return 0;
}