#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
typedef long long ll;
void scan(ll n, ll m, vector<pair<ll, ll> > &a) {
	for (ll i = 0; i < n; i++) {
		pair<ll, ll> x = { 0, 1 };
		scanf("%lld", &x.first);
		while (x.first % m == 0) {
			x.first /= m;
			x.second *= m;
		}
		if (a.empty() || a.back().first != x.first) {
			a.push_back(x);
		} else {
			a.back().second += x.second;
		}
	}
}
bool solve() {
	vector<pair<ll, ll> > a, b;
	ll n, m, k;
	scanf("%lld%lld", &n, &m);
	scan(n, m, a);
	scanf("%lld", &k);
	scan(k, m, b);
	return a == b;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		if (solve()) printf("Yes\n");
		else printf("No\n");
	}
}