#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (101*1000)
#define INF ((ll)1e9)

ll n,m,dis[N],ans,num[N];
vector <ll> e[N];
bool mark[N];


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        ll v,u;
        cin>>v>>u;
        e[max(v,u)].push_back(min(v,u));
        num[v]++;num[u]++;
    }
    dis[1]=1;
    ans=max(ans,num[1]);
    for(int i=1;i<=n;i++)
    {
        dis[i]=1;
        for(int j=0;j<e[i].size();j++)
            dis[i]=max(dis[i],dis[e[i][j]]+1);
        ans=max(ans,dis[i]*num[i]);     
    }
    cout<<ans;
        
    return 0;
}