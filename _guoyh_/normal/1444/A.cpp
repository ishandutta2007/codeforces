# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll p, q;
ll work(ll x){
	ll p1 = p, q1 = q;
	ll a1 = 1, b1 = 1;
	while (p1 % x == 0){
		p1 /= x;
		a1 *= x;
	}
	while (q1 % x == 0){
		q1 /= x;
		b1 *= x;
	}
	return p1 * min(a1, b1 / x);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--){
		cin >> p >> q;
		ll q1 = q;
		ll ans = 1;
		for (ll i = 2; i * i <= q1; i++){
			if (q1 % i) continue;
			ans = max(ans, work(i));
			while (q1 % i == 0) q1 /= i;
		}
		if (q1 > 1) ans = max(ans, work(q1));
		cout << ans << '\n';
	}
	return 0;
}