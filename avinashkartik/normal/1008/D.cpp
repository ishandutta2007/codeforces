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
#define  deb1(a)        cout<<a<<" "<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<" "<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  map<pair<pll,pll>,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  2e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test=1,a,b,c,fres,A[N];

vll fact(ll n){
    vll v;
    ll i = 1;
    while(i*i <= n){
        if(n%i == 0){
            v.pb(i);
            if(i*i != n) v.pb(n/i);
        }
        i++;
    }
    return v;
}

ll div2(vll v1, ll b, ll c, ll n){
    ll ct = 0,ct1 = 0;
    for(auto it : v1){
        if(b%it == 0){
            if(c%it != 0) ct++;
            ct1++;
        }
    }
    fres *= ct;
    ll res = 0;
    while(ct--){
        res += --ct1;
    }
    return res*n;
}

void solve(){
    fres = 1;
    cin>>a>>b>>c;
    vll v1 = fact(a), v2 = fact(b), v3 = fact(c);
    ll n1 = v1.size(), n2 = v2.size(), n3 = v3.size(), ct = 0, cnt = 0;
    for(auto it : v1)
        if(b%it == 0 && c%it == 0) ct++;
    ll ans = n1*n2*n3;
    ans -= ct*(ct-1)*(ct-2)*5/6 + ct*(ct-1)*2;
    ans -= div2(v1,b,c,n3);
    ans -= div2(v2,c,a,n1);
    ans -= div2(v3,a,b,n2);
    for(auto it : v1) if(A[it] == 0) A[it] = 1, cnt++;
    for(auto it : v2) if(A[it] == 0) A[it] = 1, cnt++;
    for(auto it : v3) if(A[it] == 0) A[it] = 1, cnt++;
    ans -= (cnt-ct)*ct*(ct-1)/2;
    ans -= fres;
    deb1(ans)
    for(auto it : v1) A[it] = 0;
    for(auto it : v2) A[it] = 0;
    for(auto it : v3) A[it] = 0;
}

int main(){
    fastio;
    cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}