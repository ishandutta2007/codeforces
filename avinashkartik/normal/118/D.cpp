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
typedef  vector<ld>            vll;
typedef  unordered_map<ll,pll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  1e5+5;
const ll   mod   =  1e8;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1,n1,n2,k1,k2;
ll dp[108][108][2];

ll mem(ll n1, ll n2, ll prev){
    if(n1+n2 == 0) return 1;
    if(dp[n1][n2][prev] != -1) return dp[n1][n2][prev];
    dp[n1][n2][prev] = 0;
    if(prev == 1){
        for(int i = 1; i <= k2; i++){
            if(i > n2) break;
            dp[n1][n2][prev] += mem(n1,n2-i,prev^1);
            dp[n1][n2][prev] %= mod;
        }
    }
    else{
        for(int i = 1; i <= k1; i++){
            if(i > n1) break;
            dp[n1][n2][prev] += mem(n1-i,n2,prev^1);
            dp[n1][n2][prev] %= mod;
        }
    }
    return dp[n1][n2][prev];
}

void solve(){
    mset(dp,-1);
    cin>>n1>>n2>>k1>>k2;
    cout<<(mem(n1,n2,1)+mem(n1,n2,0))%mod<<endl;
}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
}