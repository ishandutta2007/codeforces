#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int f() {
	int n, x;
	cin >> n >> x;
	int mxD = 0, mxDiff = 0;
	for (int i = 0; i < n; ++i) {
		int d, h;
		cin >> d >> h;
		mxD = max(mxD, d);
		mxDiff = max(mxDiff, d - h);
	}
	x -= mxD;
	if (x <= 0)
		return 1;
	if (mxDiff == 0)
		return -1;
	return 1 + (x + mxDiff - 1) / mxDiff;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cout << f() << '\n';
	}
	return 0;
}