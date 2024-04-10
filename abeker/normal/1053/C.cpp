#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

struct mint {
	int x;
	mint(ll arg) {
		x = arg % MOD;
		if (x < 0)
			x += MOD;
	}
	mint() : x(0) {}
	void operator +=(const mint &rhs) {
		x += rhs.x;
		if (x >= MOD)	
			x -= MOD;
	}
	void operator -=(const mint &rhs) {
		x -= rhs.x;
		if (x < 0)
			x += MOD;
	}
	mint operator +(const mint &rhs) const {
		mint tmp = *this;
		tmp += rhs;
		return tmp;
	}
	mint operator -(const mint &rhs) const {
		mint tmp = *this;
		tmp -= rhs;
		return tmp;
	}
	mint operator *(const mint &rhs) const {
		return (ll)x * rhs.x % MOD;
	}
};

template <typename T>
struct fenwick {
	T f[MAXN];
	fenwick() {
		for (int i = 0; i < MAXN; i++)
			f[i] = 0;
	}
	void update(int x, T val) {
		for (; x < MAXN; x += x & -x)
			f[x] += val;
	}
	T get(int x) {
		T res = 0;
		for (; x; x -= x & -x)
			res += f[x];
		return res;
	}
};

int N, Q;
int a[MAXN], w[MAXN];
fenwick <ll> sum;
fenwick <mint> weight;

void load() {
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= N; i++)
		scanf("%d", w + i);	
}

mint query(int l, int r) {
	int lo = l, hi = r + 1;
	ll pref = sum.get(l - 1);
	ll tot = sum.get(r) - pref;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (2 * (sum.get(mid) - pref) >= tot)
			hi = mid;
		else
			lo = mid + 1;
	}
	return mint(a[lo]) * mint(2 * sum.get(lo) - sum.get(l - 1) - sum.get(r)) + weight.get(l - 1) + weight.get(r) - mint(2) * weight.get(lo);
}

void solve() {
	for (int i = 1; i <= N; i++) {
		a[i] -= i;
		sum.update(i, w[i]);
		weight.update(i, mint(a[i]) * mint(w[i]));
	}
	
	while (Q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x < 0) {
			x = -x;
			sum.update(x, y - w[x]);
			weight.update(x, mint(a[x]) * mint(y - w[x]));
			w[x] = y;
		}
		else
			printf("%d\n", query(x, y).x);
	}
}

int main() {
	load();
	solve();
	return 0;
}