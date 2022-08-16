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
typedef  unordered_map<ll,pll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  3e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test=1,n,dp[N][2][2];
string s,w;

ll mem(ll ind, int f1, int f2){
    if(ind == n){
        return (f1 && f2);
    }
    if(dp[ind][f1][f2] != -1) return dp[ind][f1][f2];
    ll ans = 0;
    ll li = 0, ri = 9, lj = 0, rj = 9;
    if(s[ind] != '?') li = ri = s[ind]-'0';
    if(w[ind] != '?') lj = rj = w[ind]-'0';
    for(int i = li; i <= ri; i++){
        for(int j = lj; j <= rj; j++){
            ans += mem(ind+1,f1|(i<j),f2|(i>j));
        }
    }
    return dp[ind][f1][f2] = ans%mod;
}

void solve(){
    mset(dp,-1);
    cin>>n>>s>>w;
    deb1(mem(0,0,0));
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