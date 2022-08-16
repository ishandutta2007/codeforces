#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
#define  x                     first                 
#define  y                     second

const ll   N     =  2e+5+5;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll m,n,ans,dp[N][11];

ll fastModInv(ll x){
    ll res=1;
    ll y=mod-2;
    while(y){
        if(y&1)res=(res*x)%mod;
        y>>=1;x=(x*x)%mod;
    }
    return res;
}

ll NCR(ll n, ll r) {
	if (r == 0) return 1;
	if (r > n / 2) return NCR(n, n - r);
	ll res = 1, den = 1;
	for (ll k = 1; k <= r; ++k){
		res = (res*(n - k + 1))%mod;
		den = (den*k)%mod;
	}
	return (res*fastModInv(den))%mod;
}

int main(){
	fastio;
 	cin>>n>>m;
 	cout<<NCR(2*m+n-1,2*m)<<endl;
 }