#include <bits/stdc++.h>
using namespace std;
const int N=1000003,M=100000000;
struct ban
{
    int x;
    long long d;
};

vector<long long> v,p;
void pre()
{
    long long t=0;
    v.push_back(t);
    for(int i=1;;++i)
    {
        t+=i;
        v.push_back(t);
        if(t>M)
            break;
    }
    p.push_back(v[0]);
    for(int i=1;i<v.size();++i)
        p.push_back(p[i-1]+v[i]);
}
int byn(long long x)
{
    int l=0,r=v.size()-1;
    while((r-l)>4)
    {
        int m=(l+r)/2;
        if(v[m]<x)
            l=m;
        else
            r=m;
    }
    for(int i=r;i>=l;--i)
        if(v[i]<=x)
            return i;
}
long long hav(long long x)
{
    int i=byn(x);
    return x*(i+1)-p[i];
}

int n,m,s;
vector<ban> a[N];
vector<ban> b[N];

int c[N];

vector<int> topo;
void dfs(int x)
{
    c[x]=1;
    for(int i=0;i<a[x].size();++i)
    {
        int h=a[x][i].x;
        if(!c[h])
            dfs(h);
    }
    topo.push_back(x);
}
void dfs1(int x,int k)
{
    c[x]=k;
    for(int i=0;i<b[x].size();++i)
    {
        int h=b[x][i].x;
        if(!c[h])
            dfs1(h,k);
    }
}

long long dx[N],ans[N];
vector<ban> g[N];
int cs[N];
void dfsolve(int x)
{
    ans[x]=dx[x];
    cs[x]=1;
    for(int i=0;i<g[x].size();++i)
    {
        ban h=g[x][i];
        if(!cs[h.x])
            dfsolve(h.x);
        ans[x]=max(ans[x],h.d+dx[x]+ans[h.x]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    pre();
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        ban t;
        int x,y;
        cin>>x>>y>>t.d;
        t.x=y;
        a[x].push_back(t);
        t.x=x;
        b[y].push_back(t);
    }
    cin>>s;
    //////////////////////
    for(int x=1;x<=n;++x)
        if(!c[x])
            dfs(x);
    reverse(topo.begin(),topo.end());
    for(int x=1;x<=n;++x)
        c[x]=0;
    int k=0;
    for(int i=0;i<n;++i)
    {
        int x=topo[i];
        if(!c[x])
        {
            ++k;
            dfs1(x,k);
        }
    }
    for(int x=1;x<=n;++x)
    {
        for(int i=0;i<a[x].size();++i)
        {
            ban t=a[x][i];
            if(c[x]==c[t.x])
                dx[c[x]]+=hav(t.d);
            else
            {
                t.x=c[t.x];
                g[c[x]].push_back(t);
            }
        }
    }
    for(int x=1;x<=k;++x)
        cs[x]=0;
    dfsolve(c[s]);
    cout<<ans[c[s]]<<endl;
    return 0;
}