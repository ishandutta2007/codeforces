#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		int A, B, C, R;
		cin >> A >> B >> C >> R;

		if (A > B) swap(A, B);
		int mnR = min(B, C + R);
		int mxL = max(A, C - R);
		int res = B - A - max((int)0, mnR - mxL);
		cout << res << "\n";
	}
	return 0;
}