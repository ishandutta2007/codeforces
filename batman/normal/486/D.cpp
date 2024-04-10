#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define INF ((ll)1e14)
#define N (2002)
#define MOD ((ll)1e9+7)

ll n,d,ans,a[N];
vector <ll> e[N];

ll dfs(ll x,ll par,ll root)
{
    ll res=1;
    for(int i=0;i<e[x].size();i++)
        if(e[x][i]!=par && a[e[x][i]]<=a[root]+d &&(a[e[x][i]]>a[root] || (a[e[x][i]]==a[root] && e[x][i]>root)))
            res*=dfs(e[x][i],x,root)+1,res%=MOD;
    return res;     
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>d>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=0;i<n-1;i++)
    {
        ll v,u;
        cin>>v>>u;
        e[v].push_back(u);
        e[u].push_back(v);  
    }
    for(int i=1;i<=n;i++)
        ans+=dfs(i,0,i),ans%=MOD;;
    cout<<ans;  
    return 0;
}