#include <iostream>
using namespace std;

const int N = 100 * 1000 + 5, A = 1000 * 1000 + 5;
const int mod = 1000 * 1000 * 1000 + 7;

int a[N];
long long seg[4 * A];

void update(int p, int x, int v = 1, int s = 0, int e = A) {
	if (e <= p || p < s) {
		return;
	}
	if (e - s == 1) {
		seg[v] = x;
		return;
	}
	int md = (s + e) / 2;
	update(p, x, v * 2, s, md);
	update(p, x, v * 2 + 1, md, e);
	seg[v] = seg[v * 2] + seg[v * 2 + 1];
}
long long get(int l, int r, int v = 1, int s = 0, int e = A) {
	if (r <= s || e <= l) {
		return 0;
	}
	if (l <= s && e <= r) {
		return seg[v];
	}
	int md = (s + e) / 2;
	long long ans = 0;
	ans += get(l, r, v * 2, s, md);
	ans += get(l, r, v * 2 + 1, md, e);
	ans %= mod;
	return ans;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		long long x = 1ll * get(0, a[i] + 1) * a[i] + a[i];
		//cout << i << " " << a[i] << " " << x << endl;
		x %= mod;
		update(a[i], x);
	}
	long long ans = 0;
	for (int i = 1; i < A; i++) {
		ans += get(i, i + 1);
		ans %= mod;
		//cout << "73 " << i << " " << get(i, i + 1) << endl;
	}
	cout << ans << endl;
	return 0;
}