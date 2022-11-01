#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
ll tavan(ll a,ll n,ll mod){ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (201*1000)
#define MOD ((ll)1e9+7)

ll n,m,dp_down[N],dp_up[N],res,min_res,cnt,max_cnt,dis_down[N],dis_up[N];
vector <ll> e[N];
bool att[N],mark[N];

void dfs(ll x)
{
    mark[x]=1;
    if(att[x])
    {
        dp_down[x]=0;
        for(int i=0;i<e[x].size();i++)
        if(!mark[e[x][i]])
        {
            dfs(e[x][i]);
            if(dp_down[e[x][i]]!=-1)
                dp_down[x]+=dp_down[e[x][i]]+2;     
        }
    }
    else
    {
        dp_down[x]=0;
        ll p=0;
        for(int i=0;i<e[x].size();i++)
        if(!mark[e[x][i]])
        {
            dfs(e[x][i]);
            if(dp_down[e[x][i]]!=-1)
                p++,dp_down[x]+=dp_down[e[x][i]]+2;     
        }
        if(p==0)
            dp_down[x]=-1;
            
    }       
    mark[x]=0;
}

void dfs2(ll x,ll par)
{
    mark[x]=1;
    ll p=0;
    for(int i=0;i<e[par].size();i++)
        if(e[par][i]!=x && dp_down[e[par][i]]!=-1 && !mark[e[par][i]])
            p++,dp_up[x]+=dp_down[e[par][i]]+2;
    if(p)
        dp_up[x]+=3;        
    if(dp_up[par]!=-1)
    {
        if(dp_up[x]==-1)dp_up[x]+=3;
        dp_up[x]+=dp_up[par];   
    }
    if(att[x])dp_up[x]=max(dp_up[x],0);
    for(int i=0;i<e[x].size();i++)
        if(!mark[e[x][i]])
            dfs2(e[x][i],x);
    mark[x]=0;              
                
}

void dfs11(ll x)
{
    mark[x]=1;
    for(int i=0;i<e[x].size();i++)
        if(!mark[e[x][i]])
        {
            dfs11(e[x][i]);
            if(dis_down[e[x][i]]!=-1)
                dis_down[x]=max(dis_down[e[x][i]]+1,dis_down[x]);
        }
    if(att[x])dis_down[x]=max(dis_down[x],0); 
    mark[x]=0;  
}

void dfs21(ll x,ll par)
{
    mark[x]=1;
    
    for(int i=0;i<e[par].size();i++)
        if(!mark[e[par][i]] && dis_down[e[par][i]]!=-1)
            dis_up[x]=max(dis_up[x],dis_down[e[par][i]]+2);
    if(dis_up[par]!=-1)
        dis_up[x]=max(dis_up[x],dis_up[par]+1);  
    if(att[x])dis_up[x]=max(dis_up[x],0);      
    for(int i=0;i<e[x].size();i++)
        if(!mark[e[x][i]])
            dfs21(e[x][i],x);
    mark[x]=0;  
}

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i=0;i<N;i++)dp_down[i]=dp_up[i]=dis_down[i]=dis_up[i]=-1;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n-1;i++)
    {
        ll v,u;
        scanf("%d%d",&v,&u);
        e[v].push_back(u);
        e[u].push_back(v);
    }
    for(int i=0;i<m;i++)
    {
        ll x;
        scanf("%d",&x);
        att[x]=1;
    }
    dfs(1);
    dfs2(1,0);
    dfs11(1);
    dfs21(1,0);
    ll ans=MOD;
    for(int i=1;i<=n;i++)
    {
        //cout<<i<<" "<<dis_down[i]<<" "<<dis_up[i]<<"\n";
        if(dp_down[i]==-1)
            ans=min(ans,dp_up[i]-dis_up[i]);
        else if(dp_up[i]==-1)
            ans=min(ans,dp_down[i]-dis_down[i]);
        else        
            ans=min(ans,dp_up[i]+dp_down[i]-max(dis_down[i],dis_up[i]));
        //cout<<ans<<endl;  
        
    }
    ll last_res=MOD;
    for(int i=1;i<=n;i++)
    {
        ll ex;
        
        if(dp_down[i]==-1)
            ex=dp_up[i]-dis_up[i];
        else if(dp_up[i]==-1)
            ex=dp_down[i]-dis_down[i];
        else        
            ex=dp_up[i]+dp_down[i]-max(dis_down[i],dis_up[i]); 
        //cout<<i<<" "<<ex<<"\n";    
        if(ex==ans)
        {
            printf("%d\n%d",i,ans);
            return 0; 
        }
            
    }
    
    return 0;
}