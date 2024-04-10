#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N (3003)
#define INF ((ll)1e6)

ll n,m,k,d[N][N],par_[N][N];
vector <ll> e[N];
set <pair<ll,pair<ll,ll> > > s;

int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<m;i++)
    {
        ll v,u;
        scanf("%d %d",&v,&u);
        e[v].push_back(u);
        e[u].push_back(v);  
    }
    for(int i=0;i<k;i++)
    {
        ll a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        s.insert({a,{b,c}});
    }
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)d[i][j]=INF;
    queue <pair<ll,ll> > q;q.push({0,1});
    d[0][1]=1;
    while(q.size())
    {
        ll par=q.front().first,x=q.front().second;q.pop();
        for(int i=0;i<e[x].size();i++)
            if(d[x][e[x][i]]==INF && !s.count({par,{x,e[x][i]}}))
                d[x][e[x][i]]=d[par][x]+1,par_[x][e[x][i]]=par,q.push({x,e[x][i]});
            
    }
    ll mini=INF,id;
    for(int i=0;i<e[n].size();i++)
        if(mini>d[e[n][i]][n])
            mini=d[e[n][i]][n],id=e[n][i];
    if(mini==INF){printf("-1");return 0;}       
    printf("%d\n",mini-1);
    stack <ll> ans;
    ll par=id,x=n,tmp;
    while(par)
        ans.push(x),tmp=par,par=par_[par][x],x=tmp;
    printf("1 ");
    while(ans.size())
        printf("%d ",ans.top()),ans.pop();  
    return 0;
}