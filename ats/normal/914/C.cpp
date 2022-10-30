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
int MOD = 1000000007;
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

using comb = comb_util<long long, 1000000007, 100000>;
int bitc(int a) {
	int res = 0;
	while (a > 0) {
		res += a % 2;
		a /= 2;
	}
	return res;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string N;
	cin >> N;
	int k;
	cin >> k;
	if (k == 0) {
		cout << 1 << endl;
		return 0;
	}
	set<int> st;
	set<int> st2;
	st.insert(1);
	for (int i = 0; i < k - 1; i++) {
		st2.clear();
		for (int j = 1; j <= (int)N.size(); j++) {
			if (st.count(bitc(j)) == 1) {
				st2.insert(j);
			}
		}
		st2.erase(1);
		swap(st, st2);
	}
	int res = 0;
	comb cb;
	for (auto s : st) {
		//cerr << s << endl;
		int c = 0;
		for (int i = 0; i < N.size(); i++) {
			if (N[i] == '1') {
				res = (res + cb.binom((int)N.size() - 1 - i, s - c)) % MOD;
				c++;
			}
			else {

			}
		}

	}

	int c = 0;
	for (int i = 0; i < N.size(); i++) {
		if (N[i] == '1') {
			c++;
		}
	}
	if (st.count(c) == 1) {
		res = (res + 1) % MOD;
	}
	if (k == 1) {
		res = (res - 1 + MOD) % MOD;
	}
	cout << res << endl;
}