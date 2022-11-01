#include <bits/stdc++.h>
using namespace std;
#define INF ((ll)1e9)
#define N (111)
#define ll int
#define ld long double
inline ll tavan(ll a,ll n) {ll p=1;while(n>0){if(n%2){p=p*a;}n>>=1;a*=a;a;}return p;}

ll n,a[N],b[N];
vector <ll> e[N];
bool mark[N];

bool dfs(ll x,ll val)
{
    if(x==val)
        return 1;
    mark[x]=1;
    for(int i=0;i<e[x].size();i++)
        if(!mark[e[x][i]])
            if(dfs(e[x][i],val))
                return 1;
    return 0;               
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        if(i-b[i]>=1)e[i].push_back(i-b[i]),e[i-b[i]].push_back(i);
        if(i+b[i]<=n)e[i].push_back(i+b[i]),e[i+b[i]].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<N;j++)mark[j]=0;
        if(!dfs(i,a[i]))
            return cout<<"NO",0;
    }
        
    cout<<"YES";
    return 0;
}