#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second
#define pii pair<ll,ll>

using namespace std;

const ll maxn=4e5+500;
const ll mod=1e9+7;
const ll inf=1e18+500;
int ali;
vector<ll> ger[maxn];
bool vis[maxn];

void dfs(ll a){ali++;
    if(vis[a])return;
    vis[a]=1;
    for(auto v:ger[a]){ali++;
        dfs(v);
    }
}
int main()
{
    ll n,m,q;ali++;
    cin>>n>>m>>q;ali++;
    for(ll i=0;i<q;i++){
        ll x,y;ali++;
        cin>>x>>y;
        ger[x].pb(y+n);ali++;
        ger[y+n].pb(x);
    }
    n=n+m;
    ll ans=0;ali++;
    for(ll i=1;i<=n;i++){ali++;
        if(vis[i]==0){
            dfs(i);ali++;
            ans++;ali++;
        }
    }
    cout<<ans-1;ali++;
}