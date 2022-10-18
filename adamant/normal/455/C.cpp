#include <bits/stdc++.h>

using namespace std;

const int maxn=3e5+1;
//
struct DSU
{
    int d[maxn];
    int parent[maxn];
    DSU()
    {
        for(int i=0;i<maxn;i++) parent[i]=i,d[i]=0;
    }
    int get(int x)
    {
        if(x==parent[x]) return x;
        else return parent[x]=get(parent[x]);
    }

    void uni(int a, int b)
    {
        a=get(a);
        b=get(b);
if(a==b) return;
        parent[a]=b;
        int ne=(d[a]+1)/2+(d[b]+1)/2+1;
        d[b]=max(ne,max(d[a],d[b]));
    }
    int len(int x)
    {
        return d[get(x)];
    }

    int set_len(int x,int l)
    {
        d[get(x)]=l;
    }
} me;


vector<vector<int>> G;

vector<int> used;
vector<int> dist;
void dfs(int x,int t,vector<int> &ret)
{
    dist[x]=t;
    used[x]=1;
    for(auto it:G[x]) if(!used[it]) dfs(it,t+1,ret);
    ret.push_back(x);
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
#endif
    int n,m,q;
    cin>>n>>m>>q;
    G.resize(n);
    dist.assign(n,0);
    used.assign(n,0);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
me.uni(a-1,b-1);
    }

    for(int i=0;i<n;i++)
    {
        if(used[i]) continue;
        vector<int> t;
        dfs(i,0,t);
        int mx=i;
        for(auto it:t) if(dist[it]>dist[mx]) mx=it;
        for(auto it:t) used[it]=dist[it]=0;
        t.clear();
        dfs(mx,0,t);
        for(auto it:t) if(dist[it]>dist[mx]) mx=it;
        me.set_len(i,dist[mx]);
    }
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int x;
            cin>>x;
            x--;
            cout<<me.len(x)<<"\n";
        }
        else
        {
            int a,b;
            cin>>a>>b;
            a--,b--;
            me.uni(a,b);
        }
    }
}