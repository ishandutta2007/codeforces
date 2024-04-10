#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

int N, K;
int prime[MAXN];
vector <pii> rad[MAXN];
ll cnt[MAXN];

void load() {
	scanf("%d%d", &N, &K);
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

int calc(int x, int y) {
	if (y <= 0)
		return 0;
	int res = 0;
	for (auto it : rad[x])
		res += y / it.first * it.second;
	return res;
}

void add(int g) {
	int n = (N - 1) / g;
	int a = N % g;
	int b = g - a;
	for (int i = 3; i <= 2 * n; i++) 
		cnt[a * max(i - N / g - 1, 1) + b * max(i - N / g, 1)] += calc(i, min(i, n)) - calc(i, i - n - 1);
}

int solve() {
	for (int i = 2; i <= 2 * N; i++) 
		if (!prime[i])
			for (int j = i; j <= 2 * N; j += i)
				if (!prime[j])
					prime[j] = i;
	
	for (int i = 1; i <= 2 * N; i++) {
		int x = i;
		vector <int> p;
		while (x > 1) {
			int tmp = prime[x];
			p.push_back(tmp);
			while (!(x % tmp))
				x /= tmp;
		}
		int sz = p.size();
		for (int j = 0; j < 1 << sz; j++) {
			int prod = 1;
			for (int k = 0; k < sz; k++)
				if (j >> k & 1)
					prod *= p[k];
			rad[i].push_back({prod, __builtin_popcount(j) % 2 ? -1 : 1});
		}
	}
	
	for (int i = 1; i < N; i++) {
		cnt[i]++;
		add(i);
	}
	
	int sol = 0;
	for (int i = 1; i <= N; i++)
		sol = add(sol, mul(cnt[i] % MOD, pot(K, i)));
	
	return mul(sol, pot(K, MOD - 1 - N));
}

int main() {
	load();
	printf("%d\n", solve());	
	return 0;
}