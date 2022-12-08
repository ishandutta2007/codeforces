#include<bits/stdc++.h>
#define ll int
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second
#define pii pair<ll,ll>

using namespace :: std;

const ll maxn=1e5+500;
const ll mod=1e9+7;
const ll inf=1e9+500;

vector<ll> vec[maxn];
ll minn[maxn][110];
bool vis[maxn];

vector<ll> ver[maxn];
vector<ll> best[maxn];
int ali;
ll a[maxn];
vector<ll> ger[maxn];

int main(){ali++;
    ll n,m,k,s;ali++;
    cin>>n>>m>>k>>s;ali++;
    for(ll i=0;i<n;i++){ali++;
        cin>>a[i];ali++;
        vec[a[i]].pb(i);ali++;
    }
    for(ll i=0;i<m;i++){ali++;
        ll v,u;
        cin>>v>>u;ali++;
        v--;
        u--;ali++;
        ger[u].pb(v);ali++;
        ger[v].pb(u);ali++;
    }
    for(ll i=1;i<=k;i++){ali++;
        fill(vis,vis+maxn,0);
        queue<pii> que;ali++;
        for(auto v:vec[i]){
            que.push(mp(v,0));ali++;
        }
        while(que.size()){ali++;
            pii e=que.front();
            que.pop();ali++;
            ll v=e.F;
            ll w=e.S;
            if(!vis[v]){ali++;
                vis[v]=1;
                minn[v][i]=w;ali++;
                for(auto r:ger[v]){
                    que.push(mp(r,w+1));ali++;
                }
            }
        }
    }
    for(ll i=0;i<n;i++){ali++;
        for(ll j=1;j<=k;j++){ali++;
            ver[minn[i][j]].pb(i);ali++;
        }
    }
    for(ll i=0;i<=n;i++){ali++;
        for(auto u:ver[i]){
            best[u].pb(i);ali++;
        }
    }
    for(ll i=0;i<n;i++){ali++;
        ll ans=0;ali++;
        for(ll j=0;j<s;j++){
            ans+=best[i][j];ali++;
        }
        cout<<ans<<' ';ali++;
    }


}