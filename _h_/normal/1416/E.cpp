#include <bits/stdc++.h>
using namespace std;
#define trav(x,v) for(auto &x : v)
typedef long long ll;

void erase_lt(ll x, set<ll> &s){
	while(!s.empty()){
		auto it = s.begin();
		if(*it >= x) break;
		s.erase(it);
	}
}

void erase_gt(ll x, set<ll> &s){
	while(!s.empty()){
		auto it = prev(s.end());
		if(*it <= x) break;
		s.erase(it);
	}
}

ll solve(){
	ll n;
	cin >> n;
	vector<ll> a(n);
	trav(x, a) cin >> x, x -= 2;
	ll ans = 0, l = 0;
	while(l < n){
		ll sgsum = 0;
		ll mn = 0, mx = 1e9;
		set<ll> spor;
		ll r = l;
		while(r < n){
			bool flg = false;
			ll y;
			if((r+l)%2){
				sgsum -= a[r];
				if(mn < sgsum){
					mn = sgsum;	
				}
				erase_lt(sgsum, spor);
				if(a[r]%2 == 0){
					y = sgsum + a[r]/2;
					flg = true;
				}
			} else {
				sgsum += a[r];
				if(sgsum < mx){
					mx = sgsum;	
				}
				erase_gt(sgsum, spor);
				if(a[r]%2 == 0){
					y = sgsum - a[r]/2;
					flg = true;
				}
			}
			if(flg){
				if((mn <= y && y <= mx) || spor.count(y)){
					--ans;
					mn = mx+1;
					spor.clear();
					spor.insert(y);
				} else {
					spor.insert(y);
				}
			}
			if(mx < mn && spor.empty()) break;
			++r;
		}
		ans += r-l+1;
		l = r;
	}
	return ans;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	ll n;
	cin >> n;
	while(n--) cout << solve() << endl;
}