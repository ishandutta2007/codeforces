#include<bits/stdc++.h>
using namespace std;


set<int> G[202020];

int vv[202020];

int ans;
void add(int u, int v)
{
    G[u].insert(v);
    set<int>::iterator it = G[u].end();
    it--;
    if((*it) > u)
    {
        if(vv[u] == 0)
        {
            vv[u] = 1;
            ans--;
        }
    }
}

void del(int u, int v)
{
    G[u].erase(G[u].find(v));
    bool flag = 0;
    if(G[u].size() == 0)
        flag = 1;
    else
    {
        set<int>::iterator it = G[u].end();
        it--;
        if(*it < u)
            flag = 1;
    }
    if(flag)
    {
        if(vv[u] == 1)
        {
            vv[u] = 0;
            ans++;
        }
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    ans = n;
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }

    int q;
    scanf("%d", &q);
    while(q--)
    {
        int type;
        scanf("%d", &type);
        if(type == 1)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v);
            add(v, u);
        }
        if(type == 2)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            del(u, v);
            del(v, u);
        }
        if(type == 3)
        {
            printf("%d\n", ans);
        }
    }


    return 0;
}