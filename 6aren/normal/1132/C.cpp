#include <bits/stdc++.h>

using namespace std;

int cnt[5005], bit1[5005], bit2[5005], n, q, l[5005], r[5005];

void update1(int u) {
	for ( ; u <= n; u += (u & (-u))) {
		bit1[u]++;
	}
}

void update2(int u) {
	for ( ; u <= n; u += (u & (-u))) {
		bit2[u]++;
	}
}

int get1(int u) {
	int res = 0;
	for ( ; u >= 1; u -= (u & (-u))) {
		res += bit1[u];
	}
	return res;
}

int get2(int u) {
	int res = 0;
	for ( ; u >= 1; u -= (u & (-u))) {
		res += bit2[u];
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n >> q;
	for (int i = 1; i <= q; i++) {
		cin >> l[i] >> r[i];
		for (int j = l[i]; j <= r[i]; j++) {
			cnt[j]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 1) {
			update1(i);
		}
		if (cnt[i] == 2) {
			update2(i);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt[i]) ans++;
	}
	int mx = 0;
	for (int i = 1; i <= q; i++) {
		for (int j = i + 1; j <= q; j++) {
			int res = ans;
			int li = min(l[i], l[j]), ri = max(r[i], r[j]);
			int lj = max(l[i], l[j]), rj = min(r[i], r[j]);
			if (rj < lj) {
				res -= get1(r[i]) - get1(l[i] - 1);
				res -= get1(r[j]) - get1(l[j] - 1);
				mx = max(mx, res);
				continue;
			}
			res -= get1(ri) - get1(li - 1);
			res -= get2(rj) - get2(lj - 1);
			mx = max(mx, res);
		}
	}
	cout << mx;
	return 0;
}