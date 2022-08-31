#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio                ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f                     first                 
#define  s                     second
#define  endl                  "\n"
#define  pb                    push_back  
#define  mset(a,x)             memset(a,x,sizeof(a))             
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  1e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1,n,m,g,r,a[N],b[N];
vll adj[N];
ll ans[10008][1008];
deque <pll> s;

void djik(){
    mset(ans,-1);
    ans[0][0] = 0;
    s.push_front({0,0});
    while(s.size()){
        auto it = s.front();
        ll x = (it).f;
        ll y = (it).s;
        s.pop_front();
        for(auto i : adj[y]){
            if(x/(g+r) != (x+abs(a[y]-a[i]))/(g+r)) continue;
            ll t = (x+abs(a[y]-a[i]))%(g+r);
            //cout<<y<<" "<<i<<" "<<t<<endl;
            if(0 < t && t <= g){
                ll x1 = x;
                if(t == g) {t = 0;if(i != m-1) x1 += r;}
                if(ans[i][t] == -1){
                    ans[i][t] = (x1+abs(a[y]-a[i]));
                    //cout<<a[i]<<" "<<t<<" "<<ans[i][t]<<endl;
                    if(t == 0) s.push_back({ans[i][t],i});
                    else s.push_front({ans[i][t],i});
                }
            }
        }
    }
    ll res = INF;
    for(int j = 0; j < g; j++){
        if(ans[m-1][j] == -1) continue;
        res = min(res,ans[m-1][j]);
    }

    if(res == INF) cout<<-1<<endl;
    else cout<<res<<endl;
}

void solve(){
    cin>>n>>m;
    for(int i = 0; i < m; i++) cin>>a[i];
    sort(a,a+m);
    for(int i = 0; i < m; i++){
        if(i != 0){
            adj[i].pb(i-1);
        }
        if(i != m-1){
            adj[i].pb(i+1);
        }
    }
    cin>>g>>r;
    djik();
}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}