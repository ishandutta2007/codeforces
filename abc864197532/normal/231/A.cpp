#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, tmp, ans = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int now = 0;
		for (int j = 0; j < 3; ++j) cin >> tmp, now += tmp;
		if (now >= 2) ans++;
	}
	cout << ans << endl;
}