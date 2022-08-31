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
 
const ll   N     =  1.5e+7+5;
const ll   mod   =  1e+6+3;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
 
ll p[N],n,a,ans,m[N];

int main(){
	fastio;

	cin>>n;
	ll g = 0;
	ll maxx = 0;
	for(int i = 0; i < n; i++){
		cin>>a; g = __gcd(g,a); m[a]++;
	}
	
	for(int i = g+1; i < N; i++){
		if(p[i] == 0){
			ll ch = 0;
			for(int j = i; j < N; j += i) p[j] = i, ch += m[j];
			ans = max(ans,ch);
		}
	}
	if(ans == 0) cout<<-1<<endl;
	else cout<<n-ans<<endl;

	#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}