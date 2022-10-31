#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

int main() {
	int n;
	while (~scanf("%d", &n)) {
		map<int, pair<int, int>> value;
		for (int i = 0; i < n; ++ i) {
			int a; int x;
			scanf("%d%d", &a, &x);
			amax(value[a].first, x);
		}
		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; ++ i) {
			int a; int x;
			scanf("%d%d", &a, &x);
			amax(value[a].second, x);
		}
		long long ans = 0;
		for (auto p : value)
			ans += max(p.second.first, p.second.second);
		printf("%lld\n", ans);
	}
}