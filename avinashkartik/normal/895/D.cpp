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
 
const ll   N     =  1e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, fre[26], f[N], n;
string a, b;

ll fastmod(ll x, ll y = mod-2){
    ll res = 1;
    while(y > 0){
        if(y&1) res = (res*x)%mod;
        x = (x*x)%mod;
        y /= 2;
    }
    return res;
}

ll calc(string b){
    ll res = 0;
    for(int i = 0; i < n; i++){
        int ind = b[i]-'a';
        ll ans = f[n-i-1];
        ll den = 1;
        for(int j = 0 ; j < 26; j++) den = (den*f[fre[j]])%mod;
        ans = (ans*fastmod(den))%mod;
        for(int j = 0 ; j < 26; j++){
            if(j >= ind) break;
            if(fre[j] == 0) continue;
            res = (res+ans*fre[j])%mod;
        }
        if(fre[ind] == 0) break;
        fre[ind]--;
    }
    return res;
}

void solve(){
    f[0] = 1;
    for(int i = 1; i < N; i++) f[i] = (f[i-1]*i)%mod;
    cin>>a>>b;
    n = a.size();
    for(int i = 0; i < n; i++){
        fre[a[i]-'a']++;
    }
    ll res = calc(b);
    mset(fre,0);
    for(int i = 0; i < n; i++){
        fre[a[i]-'a']++;
    }
    res = (res+mod-calc(a)-1)%mod;
    deb1(res);
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