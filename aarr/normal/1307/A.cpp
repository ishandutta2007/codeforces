#include <bits/stdc++.h>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, d, ans = 0;
		cin >> n >> d;
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			while (x > 0) {
				if (d >= j) {
					d -= j;
					x--;
					ans++;
				}
				else {
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}