#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int sp[N], n;

int main() {
	for (int i = 2; i * i < N; ++i) {
		if (sp[i]) continue;
		sp[i] = i;
		for (int j = i * i; j < N; j += i) {
			if (sp[j]) continue;
			sp[j] = i;
		}
	}
	for (int i = 2; i < N; ++i) {
		if (sp[i]) continue;
		sp[i] = i;
	}
	cin >> n;
	int _n = n, mx = 1;
	while (_n > 1) {
		int p = sp[_n];
		mx = max(mx, p);
		while (_n % p == 0) _n /= p;
	}
	// cout << mx << endl;
	int l = n - mx + 1, r = n;
	int ans = n;
	for (int i = l; i <= r; ++i) {
		int _i = i, mxp = 1;
		while (_i > 1) {
			int p = sp[_i];
			mxp = max(mxp, p);
			while (_i % p == 0) _i /= p;
		}
		if (i - mxp + 1 >= 3) {
			ans = min(ans, i - mxp + 1);
		}
	}
	cout << ans << '\n';
	return 0;
}