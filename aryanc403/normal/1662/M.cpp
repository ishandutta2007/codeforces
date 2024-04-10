#include "bits/stdc++.h"
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
using ll = long long int;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		int mx1 = 0, mx2 = 0;
		for (int i = 0; i < m; ++i) {
			int x, y; cin >> x >> y;
			mx1 = max(mx1, x);
			mx2 = max(mx2, y);
		}
		if (mx1 + mx2 > n) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		int rem = n - mx1 - mx2;
		cout << string(mx1, 'R') + string(mx2, 'W') + string(rem, 'W') << '\n';
	}
}