#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define N (51*1000)
#define K (550)
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n) {ll p=1;while(n>0){if(n%2){p=p*a;}n>>=1;a*=a;a;}return p;}

int n,k;
ll dis_down[N][K],dis_up[N][K];
vector <ll> e[N];
bool mark[N];

void dfs(ll x,ll par=0)
{
    dis_down[x][0]=1;
    for(int i=0;i<e[x].size();i++)
        if(e[x][i]!=par)
        {
            dfs(e[x][i],x);
            for(int j=1;j<=k;j++)
                dis_down[x][j]+=dis_down[e[x][i]][j-1];
        }
}

void dfs2(ll x,ll par=0)
{
    mark[x]=1;
    dis_up[x][0]=1;
    //cout<<x<<" ";
    for(int i=1;i<=k && par;i++)
    {
        dis_up[x][i]+=dis_up[par][i-1];
        if(i>1)
            dis_up[x][i]+=dis_down[par][i-1]-dis_down[x][i-2];
    }
    for(int i=0;i<e[x].size();i++)
        if(!mark[e[x][i]])
            dfs2(e[x][i],x);
    mark[x]=0;      
    //cout<<x<<" ";     
}

int main()
{ 
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    scanf("%d%d",&n,&k);
    for(int i=0;i<n-1;i++)
    {
        int v,u;
        scanf("%d%d",&v,&u);
        e[v].push_back(u);
        e[u].push_back(v);
    }
    dfs(1);
    dfs2(1);
    ll ans=0;
    for(int i=1;i<=n;i++)ans+=dis_down[i][k]+dis_up[i][k];
    printf("%I64d",ans/2);  
    return 0;
}