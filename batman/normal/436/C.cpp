#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N (1010)
#define K (13)

int n,m,k,w,d[N][N],ans,par[N];
char s[N][K][K];
bool mark[N];
vector <pair<int,pair <ll,ll> > > ed;
vector <ll> e[N];


ll root(ll x){if(par[x]<0)return x;return par[x]=root(par[x]);}
void merge(ll x,ll y){x=root(x);y=root(y);par[x]=y;}

void dfs(ll x,ll par=0)
{
    if(x!=1)printf("%d %d\n",x-1,par-1);
    for(int i=0;i<e[x].size();i++)
        if(e[x][i]!=par)
            dfs(e[x][i],x); 
}

int main()
{
    for(int i=1;i<N;i++)par[i]=-i;
    scanf("%d%d%d%d",&n,&m,&k,&w);
    for(int t=2;t<=k+1;t++)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf(" %c",&s[t][i][j]);
        d[1][t]=d[t][1]=n*m;
        ed.push_back({n*m,{1,t}});
        for(int p=2;p<t;p++)
        {
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    if(s[p][i][j]!=s[t][i][j])
                        d[p][t]+=w,d[t][p]+=w;
            ed.push_back({d[p][t],{p,t}});
        }
    }
    sort(ed.begin(),ed.end());
    for(int i=0;i<ed.size();i++)
    {
        ll u=ed[i].second.first;
        ll v=ed[i].second.second;
        ll w=ed[i].first;
        if(root(u)!=root(v))
        {   
            e[v].push_back(u);
            e[u].push_back(v);
            ans+=w;
            merge(u,v);
        }
    }
    printf("%d\n",ans);
    dfs(1);
    return 0;
}