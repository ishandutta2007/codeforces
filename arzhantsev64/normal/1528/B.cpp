#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int ans = 1;
	vector<int> divs(n + 1);
	for (int t = 1; t <= n; ++t) {
		for (int i = t; i <= n; i += t)
			divs[i]++;
		if (t == n) {
			cout << (ans + divs[t] - 1) % mod << endl;
			return 0;
		}
		ans = ((2 * ans) % mod + divs[t] - 1) % mod;
	}
	
	return 0;
}