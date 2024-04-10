#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (201*1000)
#define K (60)

ll n,dp[N][K],cnt,start[N],finish[N],d[N];
vector <ll> e[N],h[N];
bool mark[N];

void dfs(ll x)
{
    mark[x]=1;
    h[d[x]].push_back(x);
    start[x]=cnt++;
    for(int i=1;i<K;i++)
        dp[x][i]=dp[dp[x][i-1]][i-1];
    for(int i=0;i<e[x].size();i++)
        if(!mark[e[x][i]])
            d[e[x][i]]=d[x]+1,dp[e[x][i]][0]=x,dfs(e[x][i]);
    finish[x]=cnt;                  
}

ll iPar(ll x,ll num)
{
    for(int i=0;num;i++,num/=2)
        if(num%2)x=dp[x][i];
    return x;
}


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        ll u;
        cin>>u;
        e[i].push_back(u),e[u].push_back(i);    
    }
    dfs(0);
    /*for(int i=0;i<4;i++)
    {
        for(int j=0;j<h[i].size();j++)
            cout<<h[i][j]<<" ";
        cout<<"\n"; 
    }*/
    ll q;
    cin>>q;
    while(q--)
    {
        ll v,p;
        cin>>v>>p;
        
        v=iPar(v,p);
        if(v==0){cout<<"0 ";continue;}
        ll dis=d[v]+p;
        ll b,e,l=-1,r=h[dis].size();
        while(l<r-1)
        {
            ll mid=(l+r)/2;
            if(start[h[dis][mid]]>=start[v])
                r=mid;
            else
                l=mid;  
        }
        b=min(r,(ll)h[dis].size()-1);
        //cout<<l<<" "<<r<<"\n";
        l=-1,r=h[dis].size();
        while(l<r-1)
        {
            ll mid=(l+r)/2;
            if(start[h[dis][mid]]<=finish[v])
                l=mid;
            else 
                r=mid;
            //cout<<mid<<" "<<finish[h[dis][mid]]<<" "<<finish[v]<<" "<<v<<" "<<h[dis][mid]<<"\n";      
        }
        
        //cout<<l<<" "<<r<<"\n";
        e=max(l,0ll);
        //cout<<b<<" "<<e<<"\n";
        cout<<abs(e-b)<<" ";
    }   
    return 0;
}