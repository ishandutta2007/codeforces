#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1LL * 1009 * 1000000007;

ll bit[2505][2505], a[2505][2505], n, m, q, t, r1, c1, r2, c2, p[100005];

void update(int x, int y, int val, int type) {
	if (type == -1) {
		val = -p[val];
	} else {
		val = p[val];
	}
	for (int i = x; i <= n; i += (i & (-i))) {
		for (int j = y; j <= m; j += (j & (-j))) {
			bit[i][j] = (bit[i][j] + val) % MOD;
		}
	}
}

ll get(ll x, ll y) {
	ll res = 0;
	for (int i = x; i >= 1; i -= (i & (-i))) {
		for (int j = y; j >= 1; j-= (j & (-j))) {
			res = (res + bit[i][j]) % MOD;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie();
	//freopen("in", "r", stdin);
	cin >> n >> m >> q;	
	p[0] = 1;
	for (int i = 1; i <= q; i++) {
		p[i] = (p[i - 1] * 100000) % MOD;
	}
	for (int i = 1; i <= q; i++) {
		cin >> t >> r1 >> c1 >> r2 >> c2;
		if (t == 1) {
			a[r1][c1] = i;
			update(r1, c1, i, 1);
			update(r1, c2 + 1, i, -1);
			update(r2 + 1, c1, i, -1);
			update(r2 + 1, c2 + 1, i, 1);
		} else if (t == 2) {
			int u = a[r1][c1];
			update(r1, c1, u, -1);
			update(r1, c2 + 1, u, 1);
			update(r2 + 1, c1, u, 1);
			update(r2 + 1, c2 + 1, u, -1);
		} else {
			if (get(r1, c1) == get(r2, c2)) {
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
			}
		}
	} 
	return 0;
}