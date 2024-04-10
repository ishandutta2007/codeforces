#define _CRT_SECURE_NO_WARNINGS

#include <memory>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <random>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>
#include <sstream>
#include <numeric>
#include <chrono>

using namespace std;

typedef long long ll;

const int N = 5e5 + 10;

ll a[N];

ll gcd(ll x, ll y) {
	if (!x) return y;
	return gcd(y % x, x);
}

void solve() {
	int n, m;
	//cin >> n >> m;
	scanf("%d %d", &n, &m);
	vector<vector<int>>g(n);
	for (int i = 0; i < n; ++i) {
		//cin >> a[i];
		scanf("%lld", &a[i]);
	}
	for (int i = 0; i < m; ++i) {
		int v, u;
		//cin >> v >> u;
		scanf("%d %d", &v, &u);
		g[u - 1].push_back(v - 1);
	}
	
	map<vector<int>, ll> mm;

	for (int i = 0; i < n; ++i) {
		if (!g[i].empty()) {
			sort(g[i].begin(), g[i].end());
			mm[g[i]] += a[i];
		}
	}

	ll ans = 0;
	for (const auto& el : mm) {
		ans = gcd(ans, el.second);
	}

	//cout << ans << "\n";
	printf("%lld\n", ans);
}

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie();
	//cout.tie();

	int t;
	//cin >> t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
}