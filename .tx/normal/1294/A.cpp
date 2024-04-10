#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a, b, c, n;
	cin >> a >> b >> c >> n;
	int s = a + b + c + n;
	if (s % 3) {
		cout << "NO\n";
		return;
	}
	int o = s / 3;
	if (a > o || b > o || c > o) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	for (int it = 0; it < t; it++) {
		solve();
	}


	return 0;
}