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
 
const ll   N     =  505;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1,n,m;
char a[N][N];
vpll ans;
vector <char> ch;

ll dfs(ll i, ll j, ll f){
    ans.pb({i,j});
    ch.pb('B');
    a[i][j] = '#';
    if(a[i-1][j] != '#'){
        dfs(i-1,j,0);
    }
    if(a[i+1][j] != '#'){
        dfs(i+1,j,0);
    }
    if(a[i][j-1] != '#'){
        dfs(i,j-1,0);
    }
    if(a[i][j+1] != '#'){
        dfs(i,j+1,0);
    }
    if(f != 1){
        ans.pb({i,j});
        ch.pb('D');
        ans.pb({i,j});
        ch.pb('R');
    }
}

void solve(){
    cin>>n>>m;
    for(int i = 0; i <= n+1; i++){
        for(int j = 0; j <= m+1; j++){
            a[i][j] = '#';
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>a[i][j];
        }
    } 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] != '#') dfs(i,j,1);
        }
    }
    ll sz = ans.size();
    cout<<sz<<endl;
    for(int i = 0; i < sz; i++){
        cout<<ch[i]<<" "<<ans[i].f<<" "<<ans[i].s<<endl;
    }
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