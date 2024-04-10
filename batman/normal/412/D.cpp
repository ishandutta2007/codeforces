#include <bits/stdc++.h>
using namespace std;
#define INF ((ll)1e9)
#define N (31*1000)
#define ll int
#define ld long double
inline ll tavan(ll a,ll n) {ll p=1;while(n>0){if(n%2){p=p*a;}n>>=1;a*=a;a;}return p;}

ll n,m;
vector <ll> e[N];
bool mark[N];

void dfs(ll x)
{
    mark[x]=1;
    for(int i=0;i<e[x].size();i++)
        if(!mark[e[x][i]])
            dfs(e[x][i]);
    cout<<x<<" ";       
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        ll v,u;
        cin>>v>>u;
        e[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        if(!mark[i])
            dfs(i);
    return 0;
}