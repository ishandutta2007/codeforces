#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int A = 1e6;

int n, x, y, c[2 * A + 1];
ll f[2 * A + 1], ret = 1000000000000000000LL;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> x >> y;
	for(int i = 0; i < n; i++) {
		int u; cin >> u; c[u]++;
	}
	for(int i = A; i; i--) {
		f[i] = f[i + 1] + (ll)y * c[i] * (2 * A - i);
		c[i] += c[i + 1];
	}
	for(int d = 2; d <= A; d++) {
		int ost = n;
		ll s = 0;
		for(int i = 1; (i - 1) * d <= A; i++) {
			int r = i * d;
			int l = max((i - 1) * d + 1, r - x / y);
			ost -= c[l] - c[r + 1];
			s += f[l] - f[r + 1] - (ll)y * (c[l] - c[r + 1]) * (2 * A - r);
		}
		ret = min(ret, s + (ll)ost * x);
	}
	cout << ret;
}