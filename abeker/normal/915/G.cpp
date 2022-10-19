#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e6 + 5;
const int MOD = 1e9 + 7;

int N, K;
int p[MAXN];
int sol[MAXN];
int pre[MAXN];

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

int pot(int x, int y) {
	int res = 1;
	for (; y; y /= 2) {
		if (y % 2)
			res = mul(res, x);
		x = mul(x, x);
	}
	return res;
}

void load() {
	scanf("%d%d", &N, &K);
}

void inc(int lo, int hi, int val) {
	sol[lo] = add(sol[lo], val);
	sol[hi] = add(sol[hi], -val);
}

void work(int x) {
	int cnt = 0;
	for (int y = x; y > 1; y /= p[y]) {
		if (!(y / p[y] % p[y]))
			return;
		cnt ^= 1;
	}
	for (int i = x; i <= K; i += x)
		inc(i, i + x, cnt ? -pre[i / x] : pre[i / x]);
}

int solve() {
	for (int i = 2; i <= K; i++)
		if (!p[i])
			for (int j = i; j <= K; j += i)
				if (!p[j])
					p[j] = i;
	
	for (int i = 1; i <= K; i++) 
		pre[i] = pot(i, N);
	
	for (int i = 1; i <= K; i++)
		work(i);
	
	int ans = 0;
	for (int i = 1; i <= K; i++) {
		sol[i] = add(sol[i], sol[i - 1]);
		ans = add(ans, sol[i] ^ i);
	}
	
	return ans;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}