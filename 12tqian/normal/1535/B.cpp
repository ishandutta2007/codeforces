#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	int n; 
	cin >> n;
	deque<int> a;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (x % 2 == 0) { 
			a.push_front(x);
		} else {
			a.push_back(x);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (__gcd(a[i], 2 * a[j]) > 1) {
				++ans;
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; 
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}