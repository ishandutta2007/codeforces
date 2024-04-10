#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 200005;
const int BASE = 3137;
const int MOD = 1000000007;

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
		int ret = 0;
		for (; x; x -= x & -x)
			ret = add(ret, f[x]);
		return ret;
	}
};

int N, M;
int a[MAXN], b[MAXN];
int pot[MAXN];
fenwick F1, F2;
int hsh;

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		int x;
		scanf("%d", &x);
		a[x] = i;
	}
	for (int i = 1; i <= M; i++) {
		int x;
		scanf("%d", &x);
		b[x] = i;
	}
}

void out(int x) {
	hsh = add(hsh, -mul(pot[M - x], F1.get(b[x])));
	hsh = add(hsh, -add(F2.get(M), -F2.get(b[x])));
	F1.update(b[x], -1);
	F2.update(b[x], -pot[M - x]);
}

void in(int x) {
	F1.update(b[x], 1);
	hsh = add(hsh, mul(pot[M - x], F1.get(b[x])));
	hsh = add(hsh, add(F2.get(M), -F2.get(b[x])));
	F2.update(b[x], pot[M - x]);
}

int solve() {
	pot[0] = 1;
	for (int i = 1; i <= M; i++)
		pot[i] = mul(pot[i - 1], BASE);
		
	int all = 0;
	for (int i = 1; i <= N; i++)
		all = add(mul(all, BASE), a[i]);
	
	int sol = 0;
	for (int i = 1; i <= M; i++) {
		in(i);
		if (i > N) 
			out(i - N);
		sol += hsh == mul(all, pot[M - i]);
	}
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}