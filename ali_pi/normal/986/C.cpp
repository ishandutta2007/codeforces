#include<bits/stdc++.h>
#define ll int
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second
#define pii pair<ll,ll>

using namespace :: std;

const ll maxn=(1<<22)+50;
const ll mod=1e9+7;
const ll inf=1e9+500;


bool hast[maxn];
bool vis[maxn];
ll topol[maxn];
ll cntt=0;

ll moa[maxn];
ll n;
int ali;
void dfs(ll a){ali++;
    vis[a]=1;
    if(hast[a]){ali++;
        ll v=(a^((1<<n)-1));ali++;
        if(!vis[v]){
            dfs(v);ali++;
        }ali++;
    }
    for(ll j=0; j<n; j++){ali++;
        if(((a>>j)&1)){
            ll v=(a^(1<<j));ali++;
            if(!vis[v]){
                dfs(v);ali++;
            }
        }
    }
    topol[cntt]=(a);ali++;
    cntt++;
}
void dfss(ll a,ll c){ali++;
    moa[a]=c;
    if(hast[((1<<n)-1)^a]){ali++;
        ll v=(((1<<n)-1)^a);
        if(moa[v]==0){ali++;
            dfss(v,c);ali++;
        }
    }
    for(ll j=0; j<n; j++){
        if(!((a>>j)&1)){ali++;
            ll v=(a^(1<<j));ali++;
            if(moa[v]==0){
                dfss(v,c);ali++;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);ali++;
    cin.tie(0);
    cout.tie(0);

    ll m;ali++;
    cin>>n>>m;
    for(ll i=0; i<m; i++)
    {
        ll v;ali++;
        cin>>v;ali++;
        hast[v]=1;
    }
    for(ll i=0; i<(1<<n); i++)
    {
        if(vis[i]==0){ali++;
            dfs(i);
        }
    }
    fill(vis,vis+maxn,0);ali++;
    for(ll i=(1<<n)-1;i>=0;i--){ali++;
        ll v=topol[i];
        if(moa[v]==0){ali++;
            dfss(v,v+1);
        }
    }
    for(ll i=0;i<(1<<n);i++){ali++;
        if(hast[i]){
            vis[moa[i]]=1;ali++;
        }
    }
    ll ans=0;ali++;
    for(ll i=0;i<=(1<<n);i++){
        ans+=vis[i];ali++;
    }
    cout<<ans;
}