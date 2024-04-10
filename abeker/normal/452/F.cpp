#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 300005;
const int BASE = 10007;
const int MOD = 1000000007;

int pot[MAXN];
int inv[MAXN];

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	else if (x < 0)
		x += MOD;
	return x; 
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

int expo(int x, int y) {
	int res = 1;
	for (; y; y /= 2) {
		if (y % 2)
			res = mul(res, x);
		x = mul(x, x);
	}
	return res;
}

struct fenwick {
	int f[MAXN];
	fenwick() {
		memset(f, 0, sizeof f);
	}
	void update(int x, int val) {
		for (; x < MAXN; x += x & -x)
			f[x] = add(f[x], val);
	}
	int get(int x) {
		int res = 0;
		for (; x; x -= x & -x)
			res = add(res, f[x]);
		return res;
	}
	int query(int lo, int hi) {
		return mul(pot[hi], add(get(hi), -get(lo - 1)));
	}
};

int N;
int p[MAXN];
fenwick hsh, rev;

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", p + i);
}

bool solve() {
	pot[0] = 1;
	for (int i = 1; i <= N; i++) {
		pot[i] = mul(pot[i - 1], BASE);
		inv[i] = expo(pot[i], MOD - 2);
	}
	
	for (int i = 1; i <= N; i++) {
		hsh.update(p[i], inv[p[i]]);
		rev.update(N - p[i] + 1, inv[N - p[i] + 1]);
		int len = min(p[i] - 1, N - p[i]);
		if (hsh.query(p[i] - len, p[i] + len) != rev.query(N - p[i] + 1 - len, N - p[i] + 1 + len)) 
			return true;
	}
	
	return false;
}

int main() {
	load();
	puts(solve() ? "YES": "NO");
	return 0;
}