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
 
const ll   N  =  3e+5+5;
const ll   MOD   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
 
ll n,a[N],m;
 
int solve(int mid){
	ll prev,cur;
	if(m-a[0] <= mid) prev = 0;
	else prev = a[0];
	for(int i = 1; i < n; i++){
		ll ch = prev - a[i];
		if(ch < 0) ch += m;

		if(ch <= mid) cur = prev;
		else cur = a[i];
		if(cur < prev) return 0;
		prev = cur;
	}
	return 1;
}
 
int bs(){  
	ll l = 0;
	ll r = m-1;
	ll mid;
	ll ans = 0;
	while(r >= l){
		mid = (r+l)/2;
		//cout<<r<<" "<<l<<endl;
		if(solve(mid) == 0) l = mid + 1;
		else{
			ans = mid;
			r = mid - 1;
		}
	}
	return ans;
}
 
int main(){
    fastio;
    cin>>n>>m;
    for(int i = 0; i < n; i++){
    	cin>>a[i];
    }

    cout<<bs()<<endl;
}