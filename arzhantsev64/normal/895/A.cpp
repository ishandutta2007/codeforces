#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	int s = 0;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		s += v[i];
	}
	int ans = s;
	for (int i = 0; i < n; ++i) {
		int c = 0;
		for (int j = i; j < n; ++j) {
			c += v[j];
			ans = min(ans, abs(s - 2 * c));
		}
	}
	cout << ans << endl;
}