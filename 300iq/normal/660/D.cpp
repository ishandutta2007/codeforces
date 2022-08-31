//SOLUTION BY YAKUTOV DMITRY

#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

typedef long long ll;
typedef std::pair<ll, ll> Point;

int const N = 2020;

Point a[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[i] = {x, y};
	}
	std::map<Point, int> c2cnt;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			ll x = (a[i].first + a[j].first);
			ll y = (a[i].second + a[j].second);
			++c2cnt[{x, y}];
		}
	}
	ll ans = 0;
	for (auto& p : c2cnt) {
		int x = p.second;
		ans += (ll) x * (x - 1) / 2;
	}
	printf("%I64d\n", ans);
}