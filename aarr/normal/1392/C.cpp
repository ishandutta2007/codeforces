#include <bits/stdc++.h>
using namespace std;

const int N = 200 * 1000 + 5;

int a[N];


int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int mini = 1000 * 1000 * 1000 + 7;
		long long ans = 0;
		for (int i = n - 1; i > 0; i--) {
			ans += max(0, a[i - 1] - a[i]);
		}
		cout << ans << '\n';
	}
	
	return 0;
}