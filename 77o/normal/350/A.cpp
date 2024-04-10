#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	// freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int& i : a) {
		cin >> i;
	}	
	for (int& i : b) {
		cin >> i;
	}
	sort(a.begin(), a.end());
	int ans = max(a[0] * 2, a[n - 1]);
	if (ans < *min_element(b.begin(), b.end())) {
		cout << ans << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}