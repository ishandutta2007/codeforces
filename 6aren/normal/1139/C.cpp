#include<bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 100005, MOD = 1000000007;

int p[N], cnt[N], n, k;

int find(int u) {
	if (p[u] == u) {
		return u;
	}
	return (p[u] = find(p[u]));
}

void unit(int u, int v) {
	u = find(u);
	v = find(v);
	p[u] = v;
	return;
}

ll muli(ll x, ll y) {
	return (x * y) % MOD;
}

ll power(ll x, ll y) {
	if (y == 0) return 1;
	ll tmp = power(x, y / 2);
	if (y % 2) {
		return muli(tmp, muli(tmp, x));
	} else {
		return muli(tmp, tmp);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}
	for (int i = 1; i < n; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		if (!c) {
			unit(u, v);
		}
	}
	for (int i = 1; i <= n; i++) {
		cnt[find(i)]++;
	}
	ll ans = power(n, k);
	for (int i = 1; i <= n; i++) {
		ans = (ans - power(cnt[i], k) + MOD) % MOD;
	}
	cout << ans;
	return 0;
}