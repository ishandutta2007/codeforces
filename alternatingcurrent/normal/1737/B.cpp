#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

ll qsqrt(ll x){
	ll lb = 0, ub = 1e9;
	while(lb <= ub){
		ll mid = (lb+ub) >> 1;
		if(mid * mid <= x)
			lb = mid+1;
		else
			ub = mid-1;
	}
	return ub;
}

int main(){
	ios::sync_with_stdio(false);
	
	int T;
	cin >> T;
	while(T--){
		ll l, r;
		cin >> l >> r;
		ll lk = qsqrt(l-1), rk = qsqrt(r);
		auto check = [&](ll val){
			return val >= l && val <= r;
		};
		
		ll ans = 0;
		if(lk == rk){
			ans = check(lk * lk) + check(lk * (lk + 1)) + check(lk * (lk + 2));
		} else {
			ans = 3ll * (rk-lk-1);
			ans += check(lk * lk) + check(lk * (lk + 1)) + check(lk * (lk + 2));
			ans += check(rk * rk) + check(rk * (rk + 1)) + check(rk * (rk + 2));
		}
		
		cout << ans << endl;
	}
	
	return 0;
}