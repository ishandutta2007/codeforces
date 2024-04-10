#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 998244353;
template <typename Int, Int MOD, int N>
struct comb_util {
	std::array<Int, N + 1> fc, ifc;

	comb_util() {
		fc[0] = 1;
		for (int i = 1; i <= N; i++) fc[i] = fc[i - 1] * i % MOD;
		ifc[N] = inv(fc[N]);
		for (int i = N - 1; i >= 0; i--) ifc[i] = ifc[i + 1] * (i + 1) % MOD;
	}

	Int fact(Int n) { return fc[n]; }

	Int inv_fact(Int n) { return ifc[n]; }

	Int inv(Int n) { return pow(n, MOD - 2); }

	Int pow(Int n, Int a) {
		Int res = 1, exp = n;
		for (; a; a /= 2) {
			if (a & 1) res = res * exp % MOD;
			exp = exp * exp % MOD;
		}
		return res;
	}

	Int perm(Int n, Int r) {
		if (r < 0 || n < r)
			return 0;
		else
			return fc[n] * ifc[n - r] % MOD;
	}

	Int binom(Int n, Int r) {
		if (n < 0 || r < 0 || n < r) return 0;
		return fc[n] * ifc[r] % MOD * ifc[n - r] % MOD;
	}

	Int homo(Int n, Int r) {
		if (n < 0 || r < 0) return 0;
		return r == 0 ? 1 : binom(n + r - 1, r);
	}
};

using comb = comb_util<long long, 998244353, 1000010>;
comb cb;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	int res = 0;
	for (int i = 1; i <= N; i++) {
		int t = (2 * cb.pow(3, i)*cb.binom(N, i)) % MOD;
		t = (t * cb.pow(3, (N - i)*N)) % MOD;
		if (i % 2 == 1) {
			res = (res + t) % MOD;
		}
		else {
			res = (res + MOD - t) % MOD;
		}
	}
	/*
	for (int i = 0; i < N; i++) {
		int t = (cb.binom(N, i) * cb.pow(3, i)) % MOD;
		if (i % 2 == 0) {
			t = MOD - t;
		}
		tmp = (tmp + t) % MOD;
	}
	tmp = (tmp * tmp) % MOD;
	tmp = MOD - tmp;
	res = (res + tmp) % MOD; */
	int tmp = 0;
	

	for (int i = 0; i < N; i++) {
		int t = (cb.pow(3, i) + MOD - 1) % MOD;
		t = cb.pow(t, N);
		t = (t * cb.binom(N, i)) % MOD;
		t = (t * 3) % MOD;
		if ((i + N - 1) % 2 == 1) {
			t = MOD - t;
		}
		tmp = (tmp + t) % MOD;
	}
	for (int i = 0; i < N; i++) {
		//for (int j = 0; j < N; j++) {
			int j = N;
			int t = (cb.binom(N, i) * cb.binom(N, j)) % MOD;
			t = (t * cb.pow(3, i * j)) % MOD;
			t = (t * 3) % MOD;
			if ((i + j) % 2 == 1) {
				t = MOD - t;
			}
			tmp = (tmp + t) % MOD;
		//}

	}
	res = (res + tmp) % MOD;
	cout << res << endl;
}