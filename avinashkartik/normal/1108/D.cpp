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
 
const ll   N     =  2e5+5;
const ll   MAXN  =  1e7+1;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, dp[N][3] = {};
string s, ans = "";

int calc(char x){
    if(x == 'R') return 0;
    if(x == 'G') return 1;
    return 2;
}

char add(int x){
    if(x == 0) return 'R';
    if(x == 1) return 'G';
    return 'B';
}

void solve(){
    cin>>n>>s;
    s = '.'+s;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 3; j++){
            dp[i][j] = min(dp[i-1][(j+1)%3],dp[i-1][(j+2)%3])+(calc(s[i]) != j);
        }
    }
    int st = 0;
    if(dp[n][1] < dp[n][st])
        st = 1;
    if(dp[n][2] < dp[n][st])
        st = 2;
    deb1(dp[n][st])
    ans += add(st);
    for(int i = n; i > 1; i--){
        if(dp[i-1][(st+1)%3] < dp[i-1][(st+2)%3])
            st = (st+1)%3;
        else
            st = (st+2)%3;
        ans += add(st);
    }
    reverse(ans.begin(), ans.end());
    deb1(ans)
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