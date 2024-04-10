#include <bits/stdc++.h>
using namespace std;

const int N = 200 * 1000 + 5, inf = 1000 * 1000 * 1000 + 7;

long long a[N];
bool mark[N];


int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mark[(0ll + a[i] + i + 1ll * inf  * n) % n] = true;
		}
		bool ans = true;
		for (int i = 0; i < n; i++) {
			if (!mark[i]) {
				ans = false;
			}
			mark[i] = false;
		}
		if (ans) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}
	
	return 0;
}