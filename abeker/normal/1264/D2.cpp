#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
const int MOD = 998244353;

int N;
char s[MAXN];
int open[MAXN], cnt[MAXN];
int fact[MAXN], inv[MAXN];

void load() {
	scanf("%s", s + 1);
}

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

int inverse(int x) {
	assert(x);
	return pot(x, MOD - 2);
}

int choose(int n, int k) {
	if (k < 0 || n < k)
		return 0;
	return mul(fact[n], mul(inv[k], inv[n - k]));
}

int calc(int k) {
	int closed = N - open[N] - k;
	return mul(choose(cnt[N], k), add(open[closed], mul(mul(cnt[closed], k), inverse(cnt[N]))));
}

int solve() {
	N = strlen(s + 1);
	
	fact[0] = inv[0] = 1;
	for (int i = 1; i <= N; i++) {
		fact[i] = mul(fact[i - 1], i);
		inv[i] = inverse(fact[i]);
	}
	
	int sol = 0;
	for (int i = 1; i <= N; i++) {
		open[i] = open[i - 1] + (s[i] == '(');
		cnt[i] = cnt[i - 1] + (s[i] == '?');
	}
	
	if (!cnt[N]) {
		for (int i = 1; i < N; i++)
			sol = max(sol, open[i] + min(N - i - open[N], 0));
		return sol;		
	}
	
	for (int i = 0; i <= cnt[N]; i++) 
		sol = add(sol, calc(i));
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}