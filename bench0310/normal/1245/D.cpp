#include <bits/stdc++.h>

using namespace std;

long long ab(long long a)
{
    if(a>=0) return a;
    else return -a;
}

const int N=2001;
int p[N];
int sz[N];

void make_set(int a)
{
    p[a]=a;
    sz[a]=1;
}

int find_set(int a)
{
    if(a==p[a]) return a;
    else return p[a]=find_set(p[a]);
}

bool merge_sets(int a,int b)
{
    a=find_set(a);
    b=find_set(b);
    if(a==b) return 0;
    if(sz[a]<sz[b]) swap(a,b);
    p[b]=a;
    sz[a]+=sz[b];
    return 1;
}

int main()
{
    int n;
    scanf("%d",&n);
    long long x[n+1],y[n+1];
    for(int i=1;i<=n;i++) scanf("%I64d%I64d",&x[i],&y[i]);
    long long c[n+1];
    for(int i=1;i<=n;i++) scanf("%I64d",&c[i]);
    long long k[n+1];
    for(int i=1;i<=n;i++) scanf("%I64d",&k[i]);
    int idx=0;
    vector<pair<int,int>> edges;
    vector<pair<long long,int>> weights;
    for(int o=1;o<=n;o++)
    {
        for(int i=o+1;i<=n;i++)
        {
            edges.push_back({o,i});
            weights.push_back({(k[o]+k[i])*(ab(x[o]-x[i])+ab(y[o]-y[i])),idx++});
        }
    }
    for(int i=1;i<=n;i++)
    {
        edges.push_back({0,i});
        weights.push_back({c[i],idx++});
    }
    sort(weights.begin(),weights.end());
    for(int i=0;i<=n;i++) make_set(i);
    vector<int> powers;
    vector<pair<int,int>> connections;
    long long res=0;
    for(pair<long long,int> t:weights)
    {
        long long w=t.first;
        int id=t.second;
        if(merge_sets(edges[id].first,edges[id].second)==0) continue;
        res+=w;
        if(edges[id].first==0) powers.push_back(edges[id].second);
        else connections.push_back(edges[id]);
    }
    printf("%I64d\n",res);
    printf("%d\n",(int)powers.size());
    for(int a:powers) printf("%d ",a);
    printf("\n");
    printf("%d\n",(int)connections.size());
    for(pair<int,int> t:connections) printf("%d %d\n",t.first,t.second);
    return 0;
}