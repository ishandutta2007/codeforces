#include <bits/stdc++.h>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (c > a) {
			swap(a, c);
		}
		if (c > b) {
			swap(b, c);
		}
		int ans = 0;
		if (a) {
			a--;
			ans++;
		}
		if (b) {
			b--;
			ans++;
		}
		if (c) {
			c--;
			ans++;
		}
		if (a && b) {
			a--;
			b--;
			ans++;
		}
		if (a && c) {
			a--;
			c--;
			ans++;
		}
		if (b && c) {
			b--;
			c--;
			ans++;
		}
		if (a && b && c) {
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}