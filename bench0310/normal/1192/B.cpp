#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

int _n;
const int N=100005;
vector<set<pair<int,int>>> v(N);
vector<int> g[N];
vector<int> centroid_depth(N);
vector<pair<int,int>> edges;
vector<long long> weights;
unordered_map<int,long long> dist[N];
unordered_map<int,int> depth[N];
unordered_map<int,int> up[N];
unordered_map<int,int> sub[N];
unordered_map<int,int> tin[N];
unordered_map<int,int> tout[N];
vector<int> sz(N);
vector<int> dad(N);
vector<long long> tree[N];
vector<long long> lazy[N];
int time_id;
vector<int> centroid_size(N);
multiset<long long> best[N];
vector<long long> old(N);

void push(int idx,int centroid)
{
    tree[centroid][2*idx]+=lazy[centroid][idx];
    lazy[centroid][2*idx]+=lazy[centroid][idx];
    tree[centroid][2*idx+1]+=lazy[centroid][idx];
    lazy[centroid][2*idx+1]+=lazy[centroid][idx];
    lazy[centroid][idx]=0;
}

void update(int idx,int l,int r,int ql,int qr,long long val,int centroid)
{
    if(ql>qr) return;
    if(l==ql&&r==qr)
    {
        tree[centroid][idx]+=val;
        lazy[centroid][idx]+=val;
    }
    else
    {
        if(lazy[centroid][idx]!=0) push(idx,centroid);
        int m=(l+r)/2;
        update(2*idx,l,m,ql,min(qr,m),val,centroid);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,val,centroid);
        tree[centroid][idx]=max(tree[centroid][2*idx],tree[centroid][2*idx+1]);
    }
}

long long query(int idx,int l,int r,int ql,int qr,int centroid)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return tree[centroid][idx];
    if(lazy[centroid][idx]!=0) push(idx,centroid);
    int m=(l+r)/2;
    return max(query(2*idx,l,m,ql,min(qr,m),centroid),query(2*idx+1,m+1,r,max(ql,m+1),qr,centroid));
}

int dfs_ini(int a,int p)
{
    sz[a]=1;
    for(pair<int,int> t:v[a])
    {
        int to=t.first;
        if(to!=p) sz[a]+=dfs_ini(to,a);
    }
    return sz[a];
}

int get_centroid(int a,int p,int n)
{
    for(pair<int,int> t:v[a])
    {
        int to=t.first;
        if(to!=p&&sz[to]>n/2) return get_centroid(to,a,n);
    }
    return a;
}

void dfs(int a,int p,int centroid,int sub_id,int n)
{
    if(a==centroid)
    {
        dist[centroid].insert({a,0});
        depth[centroid].insert({a,0});
    }
    else
    {
        dist[centroid].insert({a,dist[centroid][p]+weights[up[centroid][a]]});
        depth[centroid].insert({a,depth[centroid][p]+1});
    }
    sub[centroid].insert({a,sub_id});
    tin[centroid].insert({a,time_id++});
    update(1,1,n,tin[centroid][a],tin[centroid][a],dist[centroid][a],centroid);
    for(pair<int,int> t:v[a])
    {
        int to=t.first;
        if(to==p) continue;
        up[centroid].insert({to,t.second});
        dfs(to,a,centroid,(a==centroid?to:sub_id),n);
    }
    tout[centroid].insert({a,time_id-1});
}

long long best_two(int centroid)
{
    if(best[centroid].empty()) return 0;
    multiset<long long>::reverse_iterator it=best[centroid].rbegin();
    long long now=*(it++);
    if(it!=best[centroid].rend()) now+=(*it);
    return now;
}

void build(int a,int p)
{
    int n=dfs_ini(a,p);
    int centroid=get_centroid(a,p,n);
    centroid_size[centroid]=n;
    dad[centroid]=p;
    tree[centroid].resize(4*n,0);
    lazy[centroid].resize(4*n,0);
    time_id=1;
    dist[centroid].reserve(n);
    depth[centroid].reserve(n);
    up[centroid].reserve(n);
    sub[centroid].reserve(n);
    tin[centroid].reserve(n);
    tout[centroid].reserve(n);
    dfs(centroid,-1,centroid,-1,n);
    for(pair<int,int> t:v[centroid])
    {
        int to=t.first;
        best[centroid].insert(query(1,1,n,tin[centroid][to],tout[centroid][to],centroid));
        v[to].erase({centroid,t.second});
        build(to,centroid);
    }
    old[centroid]=best_two(centroid);
    update(1,1,_n,centroid,centroid,old[centroid],0);
}

void ini_centroid(int a,int p=-1)
{
    if(p!=-1) centroid_depth[a]=centroid_depth[p]+1;
    for(int to:g[a]) if(to!=p) ini_centroid(to,a);
}

void update_centroid(int centroid,int a,int b,long long d,long long e)
{
    if(depth[centroid][a]>depth[centroid][b]) swap(a,b);
    best[centroid].erase(best[centroid].find(query(1,1,centroid_size[centroid],tin[centroid][sub[centroid][b]],tout[centroid][sub[centroid][b]],centroid)));
    update(1,1,centroid_size[centroid],tin[centroid][b],tout[centroid][b],e-weights[d],centroid);
    best[centroid].insert(query(1,1,centroid_size[centroid],tin[centroid][sub[centroid][b]],tout[centroid][sub[centroid][b]],centroid));
    long long temp=best_two(centroid);
    update(1,1,_n,centroid,centroid,temp-old[centroid],0);
    old[centroid]=temp;
}

int main()
{
    int n,q;
    long long w;
    scanf("%d%d%I64d",&n,&q,&w);
    _n=n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        long long c;
        scanf("%d%d%I64d",&a,&b,&c);
        v[a].insert({b,i});
        v[b].insert({a,i});
        edges.push_back({a,b});
        weights.push_back(c);
    }
    tree[0].resize(4*n,0);
    lazy[0].resize(4*n,0);
    build(1,-1);
    int centroid=1;
    for(int i=1;i<=n;i++)
    {
        if(dad[i]!=-1) g[dad[i]].push_back(i);
        else centroid=i;
    }
    ini_centroid(centroid);
    long long d,e;
    long long last=0;
    while(q--)
    {
        scanf("%I64d%I64d",&d,&e);
        d=(d+last)%((long long)n-1);
        e=(e+last)%w;
        int a,b;
        tie(a,b)=edges[d];
        if(centroid_depth[a]>centroid_depth[b]) swap(a,b);
        int c=a;
        while(c!=-1)
        {
            update_centroid(c,a,b,d,e);
            c=dad[c];
        }
        weights[d]=e;
        last=query(1,1,_n,1,_n,0);
        printf("%I64d\n",last);
    }
    return 0;
}