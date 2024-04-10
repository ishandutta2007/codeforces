#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define INF ((ll)1e9)
#define N (101*1000)

ll n,m,d,dis_down[N],dis_up[N];
vector <ll> e[N];
bool is[N],mark[N];

void dfs(ll x,ll par=0)
{
    mark[x]=1;
    for(int i=0;i<e[x].size();i++)
        if(!mark[e[x][i]])
            dfs(e[x][i],x),dis_down[x]=max(dis_down[x],dis_down[e[x][i]]+1);
    mark[x]=0;              
}

void dfs2(ll x,ll par=0)
{
    //cout<<x<<": "<<dis_up[x]<<"\n";
    pair <ll,ll> maxi[2]={};
    maxi[0].first=maxi[1].first=-INF;
    for(int i=0;i<e[x].size();i++)
        if(e[x][i]!=par)
        {
            if(dis_down[e[x][i]]>maxi[1].first)
                maxi[0]=maxi[1],maxi[1]={dis_down[e[x][i]],e[x][i]};
            else if(dis_down[e[x][i]]>maxi[0].first)
                maxi[0]={dis_down[e[x][i]],e[x][i]};        
        }   
    for(int i=0;i<e[x].size();i++)
        if(e[x][i]!=par)
        {
            dis_up[e[x][i]]=max(dis_up[e[x][i]],dis_up[x]+1);
            if(maxi[1].second!=e[x][i])
                dis_up[e[x][i]]=max(dis_up[e[x][i]],maxi[1].first+2);
            else
                dis_up[e[x][i]]=max(dis_up[e[x][i]],maxi[0].first+2);
            dfs2(e[x][i],x);            
        }       
}

int main()
{
    scanf("%d%d%d",&n,&m,&d);
    for(int i=0;i<N;i++)dis_down[i]=dis_up[i]=-INF;
    for(int i=0;i<m;i++)
    {
        ll v;
        scanf("%d",&v);
        dis_up[v]=dis_down[v]=0;
    }
    for(int i=0;i<n-1;i++)
    {
        ll v,u;
        scanf("%d%d",&v,&u);
        e[v].push_back(u);
        e[u].push_back(v);
    }
    dfs(1);
    dfs2(1);
    ll ans=0;
    
    for(int i=1;i<=n;i++)
        if(dis_down[i]<=d && dis_up[i]<=d)
            ans++;
        
    printf("%d",ans);       
    return 0;
}