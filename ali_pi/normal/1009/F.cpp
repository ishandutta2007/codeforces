#include<bits/stdc++.h>

#define ll int
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second
#define pii pair<ll,ll>

using namespace std;

const ll maxn=1e6+500;
const ll mod=1e9+7;
const ll inf=1e9+500;


vector<ll> ger[maxn];
ll sz[maxn];
ll h[maxn];
ll ans[maxn];

void dfs_sz(ll a,ll p=-1,ll H=0){
    sz[a]=1;
    h[a]=H;
    H++;
    for(auto v:ger[a]){
        if(v!=p){
            dfs_sz(v,a,H);
            sz[a]+=sz[v];
        }
    }
}

ll d[maxn];
ll maxx=0;
ll kimax=maxn-2;

stack<ll> stk;

inline void sefrkon(){
    while(stk.size()){
        d[stk.top()]=0;
        stk.pop();
    }
    maxx=0;
    kimax=maxn-2;
}
inline void ADD(ll a){
    d[h[a]]++;
    stk.push(h[a]);
    if(d[h[a]]>maxx){
        maxx=d[h[a]];
        kimax=h[a];
    }
    else if (d[h[a]]==maxx){
        kimax=min(kimax,h[a]);
    }
}
void dfs_add(ll a,ll p=-1){
    ADD(a);
    for(auto v:ger[a]){
        if(v!=p){
            dfs_add(v,a);
        }
    }
}
void dfs(ll a,ll p=-1){
    ll M=-1;
    ll KM=-1;
    for(auto v:ger[a]){
        if(v!=p){
            M=max(M,sz[v]);
            if(sz[v]==M){
                KM=v;
            }
        }
    }
    for(auto v:ger[a]){
        if(v!=KM && v!=p){
            dfs(v,a);
            sefrkon();
        }
    }
    if(KM!=-1){
        dfs(KM,a);
    }
    for(auto v:ger[a]){
        if(v!=p && v!=KM){
            dfs_add(v,a);
        }
    }
    ADD(a);
    ans[a]=kimax;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int tmppp = 0;
    ll n;
    cin>>n;
    
    tmppp = n;
    for(ll i=1;i<n;i++){
        ll v,u;
        cin>>v>>u;
        ger[u].pb(v);
        ger[v].pb(u);
    }
    tmppp++;
    dfs_sz(1);
    dfs(1);
    
    tmppp--;
    
    for(ll i=1;i<=n;i++){
        cout<<ans[i]-h[i] + tmppp - n<<endl;
    }
}