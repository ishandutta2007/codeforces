#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int x;
		for (int i = 0; i < n; ++i)
			cin >> x;
		cout << n * 3 << '\n';
		for (int i = 1; i < n; i += 2) {
			cout << 1 << ' ' << i << ' ' << i + 1 << '\n';
			cout << 1 << ' ' << i << ' ' << i + 1 << '\n';
			cout << 2 << ' ' << i << ' ' << i + 1 << '\n';
			cout << 1 << ' ' << i << ' ' << i + 1 << '\n';
			cout << 1 << ' ' << i << ' ' << i + 1 << '\n';
			cout << 2 << ' ' << i << ' ' << i + 1 << '\n';
		}
	}

	return 0;
}