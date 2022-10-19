#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector <ll> get(ll x) {
	vector <ll> res;
	for (ll i = 1; i * i <= x; i++)
		if (!(x % i))
			res.push_back(i);
	return res;
}

int main() {
	ll a, b;
	scanf("%lld%lld", &a, &b);
	
	ll ans = 1e18;
	for (int i = 0; i < 2; i++) {
		vector <ll> A = get(a);
		vector <ll> C = get(a + b);
		for (auto it : C) {
			auto ptr = lower_bound(A.begin(), A.end(), it + 1);
			if (ptr-- == A.begin())
				continue;
			if (a / *ptr <= (a + b) / it)
				ans = min(ans, it + (a + b) / it);
		}
		swap(a, b);
	}
	
	printf("%lld\n", 2 * ans);
	
	return 0;
}