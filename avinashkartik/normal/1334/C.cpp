#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  x                     first                 
#define  y                     second                
 
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

ll t=1,n,a[N],b[N],pre[N];

ll solve(){
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i]>>b[i];
		pre[i] = a[i];
	}
	ll s = 0;
	pre[0] = max(0ll,pre[0]-b[n-1]);
	s += pre[0];
	for(int i = 1; i < n; i++){
		pre[i] = max(0ll,pre[i]-b[i-1]);
		s += pre[i];
	}
	ll ans = s-pre[0]+a[0];
	for(int i = 1; i < n; i++){
		ans = min(ans,s-pre[i]+a[i]);
	}
	cout<<ans<<"\n";
}

int main(){
    fastio;
    cin>>t;
    while(t--){
        solve();
    }
}