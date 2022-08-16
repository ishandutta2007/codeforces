#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
          
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  2e3+5;
const ll   mod   =  998244353;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, m, vis[N][N];
vector <pair<ll,pll>> ans;
string s[N];

void put(int x, int y){
    int ct = 0, res = INFi;
    for(int i = x; i <= n; i++){
        if(s[i][y] == '*') ct++;
        else break;
    }
    res = min(res,ct);
    ct = 0;
    for(int i = x; i > 0; i--){
        if(s[i][y] == '*') ct++;
        else break;
    }
    res = min(res,ct);
    ct = 0;
    for(int i = y; i <= m; i++){
        if(s[x][i] == '*') ct++;
        else break;
    }
    res = min(res,ct);
    ct = 0;
    for(int i = y; i > 0; i--){
        if(s[x][i] == '*') ct++;
        else break;
    }
    res = min(res,ct);
    res--;
    if(res) vis[x][y] = 1;
    for(int i = 1; i <= res; i++){
        vis[x+i][y] = vis[x-i][y] = vis[x][y+i] = vis[x][y-i] = 1;
    }
    if(res) ans.pb({x,{y,res}});
}

void solve(){
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>s[i];
        s[i] = '.'+s[i]+'.';
    }
    s[0] = s[n+1] = string(m+2,'.');
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i][j] == '*') put(i,j);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i][j] == '*' and vis[i][j] != 1){
                deb1(-1)
                return;
            }
        }
    }
    deb1(ans.size());
    for(auto it : ans) deb3(it.f,it.s.f,it.s.s)
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