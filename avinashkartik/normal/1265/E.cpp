#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
#define	 x                     first                 
#define  y                     second                
 
const ll   N     =  2e+5+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
 
ll a[N],n,ans;
ll b[N];

ll fastModInv(ll x){
	ll res=1;
	ll y=mod-2;
	while(y){
		if(y&1)res=(res*x)%mod;
		y>>=1;x=(x*x)%mod;
	}
	return res;
}

int main(){
	fastio;

	cin>>n;

	for(int i = 0; i < n; i++){
		cin>>a[i];
		b[i] = (100*fastModInv(a[i]))%mod;
	}
	
	ans = 1;
	for(int i = 0; i < n; i++){
		ans = (ans*b[i])%mod;
	}
		
	ll res = ans;
	for(int i = 0; i < n-1; i++){
		ans = (ans*fastModInv(b[i]))%mod;
		res = (res + ans)%mod;
	}

	cout<<res%mod<<endl;
	#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}