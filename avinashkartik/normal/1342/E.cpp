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
typedef  unordered_map<ll,pll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  2e5+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1,n,k;

ll fastmod(ll x, ll y = mod-2){
	ll res = 1;
	while(y > 0){
		if(y&1) res = (res*x)%mod;
		x = (x*x)%mod;
		y /= 2;
	}
	return res;
}

ll NCR(ll n, ll r) {
	if (r == 0) return 1;
    if (r > n / 2) return NCR(n, n - r);
    ll res = 1;
    for (ll k = 1; k <= r; ++k){
        res = (res*(n-k+1))%mod;
        res = (res*fastmod(k))%mod;
    }
	return res;
}


ll stirling(ll n, ll k){
	ll res = 0,num = 1, den = 1;
	for(int i = 0; i < k; i++){
		if(i%2 == 0){
			res = (res+((num*fastmod(den))%mod)*fastmod(k-i,n))%mod;
		}
		else{
			res = (res+mod-(((num*fastmod(den))%mod)*fastmod(k-i,n))%mod)%mod;
		}
		num = (num*(k-i))%mod;
		den = (den*(i+1))%mod;
	}
	return res;
}

void solve(){
	cin>>n>>k;
	if(k >= n){
		cout<<0<<endl;
	}
	else{
		ll res = (NCR(n,n-k)*stirling(n,n-k))%mod;
		if(k != 0) res = (res*2)%mod;
		cout<<res<<endl;
	}

}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
}