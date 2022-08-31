#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" "<<endl;
#define  deb1(a)        cout<<a<<" "<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<" "<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  3e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, a[N], p[N], dp[2][1<<19], pow2[N];
um ind, fre;

ll mask(ll x){
    ll res = 0;
    for(int i = 2; i <= 70; i++){
        if(p[i] == 0){
            while(x%i == 0){
                x /= i;
                res ^= (1<<ind[i]);
            }
        }
    }
    return res;
}

void solve(){
    pow2[0] = 1;
    cin>>n;
    for(int i = 0; i < n; i++) cin>>a[i], fre[a[i]]++, pow2[i+1] = (pow2[i]*2)%mod;
    for(int i = 2; i*i <= N; i++){
        if(p[i] == 0){
            for(int j = i*i; j < N; j += i) p[j] = 1;
        }
    }
    int ct = 0;
    for(int i = 2; i < 70; i++) if(p[i] == 0) ind[i] = ct++;
    dp[0][0] = 1;
    ll ptr = 0;
    for(int i = 1; i <= 70; i++){
        if(fre[i] == 0) continue;
        ll msk = mask(i);
        for(int j = 0; j < (1<<19); j++){
            dp[1-ptr][j] = (dp[ptr][j]*pow2[fre[i]-1])%mod;
            dp[1-ptr][j] += (dp[ptr][j^msk]*pow2[fre[i]-1])%mod;
            dp[1-ptr][j] %= mod;
        }
        ptr = 1-ptr;
    }
    deb1(dp[ptr][0]-1);
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