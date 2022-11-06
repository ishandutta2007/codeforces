#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

ll calc(ll l, ll k){
	ll ans = 0;
	map<ll,ll> m;
	m[l] = 1;
	while(true){
		auto it = m.end();
		--it;
		auto pa = *it;
		if(pa.first == 0) return ans;
		m.erase(it);
		ll x = (pa.first-1)/2;
		if(x >= k) ans += pa.second;
		else return ans;
		m[pa.first/2] += pa.second;
		m[x] += pa.second;
	}
}

ll solve(ll n, ll k){
	if(k == 1) return 1;
	if(k == 2) return n;
	k-=2;
	ll lo = 0, hi = n-1;
	while(lo+1 < hi){
		ll mi = (lo+hi)/2;
		if(calc(n-2, mi) >= k)
			lo = mi;
		else
			hi = mi;
	}
	k -= calc(n-2, hi);
	ll fr = 2, to = n-1;
	while((to-fr)/2 > lo){
		ll mi = (to+fr)/2;
		ll num = calc(mi-fr, lo)-calc(mi-fr,lo+1);
		if(num >= k){
			to = mi-1;
		} else {
			k -= num;
			fr = mi+1;
		}
	}
	return fr + lo + k-1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll n, k;
	cin >> n >> k;
	cout << solve(n,k) << endl;
}