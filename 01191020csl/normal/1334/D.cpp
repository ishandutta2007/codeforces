#include<bits/stdc++.h>
using namespace std;
void solve(int k, int mv, int l, int r) {
	if (k == 0) {
		cout << 1 << ' ';
		return;
	}
	int p = 0;
	for (int i = 2; i <= k; i++) {
		if (p + 1 >= l && p + 1 <= r) cout << mv + 1 << ' ';
		if (p + 2 >= l && p + 2 <= r) cout << mv + i << ' ';
		p += 2;
	}
	if (r > p) solve(k - 1, mv + 1, 1, r - p);
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		long long l, r;
		cin >> n >> l >> r;
		int l0 = 0, r0 = n;
		while (l0 < r0) {
			int mid = (l0 + r0) / 2;
			if (1ll*(n-1+mid)*(n-mid) >= l) l0 = mid + 1;
			else r0 = mid;
		}
		int k = l0;
		l -= 1ll*(n-1+k)*(n-k), r -= 1ll*(n-1+k)*(n-k);
		solve(k, n - k, l, r);
		cout << endl;
	}
}