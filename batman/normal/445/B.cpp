#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define N (111)
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n) {ll p=1;while(n>0){if(n%2){p=p*a;}n>>=1;a*=a;a;}return p;}

ll n,m,p,ans=1;
vector <ll> e[N];
bool mark[N];

void dfs(ll x)
{
    p++;
    mark[x]=1;
    for(int i=0;i<e[x].size();i++)
        if(!mark[e[x][i]])
            dfs(e[x][i]);               
}

int main()
{ 
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        ll v,u;
        cin>>v>>u;
        e[v].push_back(u);
        e[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
        if(!mark[i])
        {
            p=0;
            dfs(i);
            //cout<<i<<" "<<p<<"\n";
            ans*=tavan(2,p-1);
        }
    cout<<ans;
    return 0;
}