#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MOD = 998244353;

int N, Q;
set <int> active;
int prob[MAXN], sum[MAXN];
int ans;

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		return x - MOD;
	if (x < 0)
		return x + MOD;
	return x;
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

int pot(int x, int y) {
	int res = 1;
	for (; y; y /= 2) {
		if (y % 2)
			res = mul(res, x);
		x = mul(x, x);
	}
	return res;
}

int divide(int x, int y) {
	assert(y);
	return mul(x, pot(y, MOD - 2));
}

void load() {
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; i++) {
		scanf("%d", prob + i);
		prob[i] = divide(prob[i], 100);
	}
}

int get(int l, int r) {
	return divide(add(sum[r - 2], l == 1 ? 0 : -sum[l - 2]), prob[r - 1]);
}

void update(int x) {
	bool remove = true;
	if (!active.count(x)) {
		active.insert(x);
		remove = false;
	}
	int prv = *(--active.find(x));
	int nxt = *(++active.find(x));
	int delta = add(add(get(prv, x), get(x, nxt)), -get(prv, nxt));
	if (remove) {
		ans = add(ans, -delta);
		active.erase(x);
	}
	else
		ans = add(ans, delta);
}

void solve() {
	prob[0] = sum[0] = 1;
	for (int i = 1; i <= N; i++) {
		prob[i] = mul(prob[i], prob[i - 1]);
		sum[i] = add(sum[i - 1], prob[i]);
	}
		
	active.insert(1);
	active.insert(N + 1);
	ans = get(1, N + 1);
	while (Q--) {
		int u;
		scanf("%d", &u);
		update(u);
		printf("%d\n", ans);
	}
}

int main() {
	load();
	solve();
	return 0;
}