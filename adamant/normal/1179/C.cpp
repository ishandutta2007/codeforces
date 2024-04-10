#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

const int maxn = 1e6 + 42;

int open[4 * maxn];
int clos[4 * maxn];

void change(int p, int c, int v = 1, int l = 0, int r = maxn) {
	if(r - l == 1) {
		if(c == 1) {
			if(clos[v] > 0) {
				clos[v]--;
			} else {
				open[v]++;
			}
		} else {
			if(open[v] > 0) {
				open[v]--;
			} else {
				clos[v]++;
			}
		}
	} else {
		int m = (l + r) / 2;
		if(p < m) {
			change(p, c, 2 * v, l, m);
		} else {
			change(p, c, 2 * v + 1, m, r);
		}
		open[v] = open[2 * v + 1] + max<int>(0, open[2 * v] - clos[2 * v + 1]);
		clos[v] = clos[2 * v] + max<int>(0, clos[2 * v + 1] - open[2 * v]);
	}
}

int get_mx(int v = 1, int l = 0, int r = maxn, int cl = 0) {
	if(r - l == 1) {
		return l;
	} else {
		int m = (l + r) / 2;
		if(open[2 * v + 1] > cl) {
			return get_mx(2 * v + 1, m, r, cl);
		} else {
			return get_mx(2 * v, l, m, clos[2 * v + 1] + max<int>(0, cl - open[2 * v + 1]));
		}
	}
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		change(a[i], 1);
	}
	int b[m];
	for(int i = 0; i < m; i++) {
		cin >> b[i];
		change(b[i], -1);
	}
	int q;
	cin >> q;
	for(int z = 0; z < q; z++) {
		int t, i, x;
		cin >> t >> i >> x;
		i--;
		if(t == 1) {
			change(a[i], -1);
			a[i] = x;
			change(a[i], 1);
		} else {
			change(b[i], 1);
			b[i] = x;
			change(b[i], -1);
		}
		if(open[1] == 0) {
			cout << -1 << "\n";
		} else {
			cout << get_mx() << "\n";
		}
	}
	return 0;
}