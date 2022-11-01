#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int N = 200 * 1000 + 5, M = 1000 * 1000 + 5, mod = 1000 * 1000 * 1000 + 7;
int n, q;

int a[N];
int last[N];
vector <int> d[M];
long long fi[M];
long long seg[N * 4];
vector <pair<int, int> > t[N];
long long ans[N];
int lt[M];

int po(int x, int y) {
	if (y == 0) {
		return 1;
	}
	long long ans = po(x, y / 2);
	ans *= ans;
	ans %= mod;
	if (y % 2) {
		ans *= x;
		ans %= mod;
	}
	return ans;
}

void update(int p, int val, int id = 1, int s = 0, int e = n) {
//	cout << "73 " << p << " " << val << endl;
	if (e <= p || p < s) {
		return;
	}
	if (e - s == 1) {
		seg[id] *= val;
		seg[id] %= mod;
		return;
	}
	int md = (s + e) / 2;
	update(p, val, id * 2, s, md);
	update(p, val, id * 2 + 1, md, e);
	seg[id] = 1ll * seg[id * 2] * seg[id * 2 + 1] % mod;
}

int get(int l, int r, int id = 1, int s = 0, int e = n) {
	if (r <= s || e <= l) {
		return 1;
	}
	if (l <= s && e <= r) {
		return seg[id];
	}
	int md = (s + e) / 2;
	long long ans = 1ll * get(l, r, id * 2, s, md) * get(l, r, id * 2 + 1, md, e);
	ans %= mod;
	return ans;
}

int main() {
	ios :: sync_with_stdio(false);
	iota(fi + 1, fi + M, 1);
	for (int i = 2; i < M; i++) {
		if (fi[i] == i) {
			for (int j = i; j < M; j += i) {
				d[j].push_back(i);
				fi[j] = fi[j] * (i - 1) / i;
			}
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	fill(seg, seg + n * 4, 1);
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		t[r].push_back({l, i});
	}
	fill(lt, lt + M, -1);
	for (int i = 0; i < n; i++) {
		for (auto x : d[a[i]]) {
			if (lt[x] != -1) {
				long long k = 1ll * x * po(x - 1, mod - 2) % mod;
				update(lt[x], k);
			}
			lt[x] = i;
		}
		update(i, fi[a[i]]);
		for (auto p : t[i]) {
			ans[p.second] = get(p.first, i + 1);
		//	cout << "74 " << p.second << " " << p.first << " " << ans[p.second] << endl;
		}
	}
	for (int i = 0; i < q; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}