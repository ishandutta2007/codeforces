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
 
const ll   N     =  1e+5+5;
const ll   mod   =  1e+6+3;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
 
ll a[N],n,k;
um m;
set <ll> s;

int main(){
	cin>>n>>k;
	for(int i = 0; i < n; i++) cin>>a[i];
	for(int i = 0; i < k; i++) m[a[i]]++;
	for(int i = 0; i < k; i++)
		if(m[a[i]] == 1) s.insert(a[i]);
	if(s.size() == 0)cout<<"Nothing"<<endl;
	else{
		auto it = s.end();
		it--;
		cout<<(*it)<<endl;
	}

	for(int i = k; i < n; i++){
		m[a[i-k]]--;
		if(m[a[i-k]] == 1)s.insert(a[i-k]);
		if(m[a[i-k]] == 0)s.erase(a[i-k]);
		m[a[i]]++;
		if(m[a[i]] == 1) s.insert(a[i]);
		if(m[a[i]] > 1)s.erase(a[i]);
		if(s.size() == 0)cout<<"Nothing"<<endl;
		else{
			auto it = s.end();
			it--;
			cout<<(*it)<<endl;
		}
	}
}