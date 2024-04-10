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

using comb = comb_util<long long, 1000000007, 300000>;
comb X;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int H, W, N;
	cin >> H >> W >> N;
	vector<pair<int, int> > A(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i].first >> A[i].second;
	}
	A.emplace_back(1, 1);
	A.emplace_back(H, W);
	sort(A.begin(), A.end());
	vector<int> dp(A.size(), 0);
	dp[0] = 1;
	for (int i = 1; i < dp.size(); i++) {
		dp[i] = X.binom(A[i].first + A[i].second - 2, A[i].first - 1);
		for (int j = 1; j < i; j++) {
			if (A[i].first >= A[j].first && A[i].second >= A[j].second) {
				dp[i] -= (dp[j] * X.binom(A[i].first - A[j].first + A[i].second - A[j].second, A[i].first - A[j].first)) % MOD;
			}
		}
		dp[i] %= MOD;
		if (dp[i] < 0)dp[i] += MOD;
		//cerr << A[i].first << " " << A[i].second << " " << dp[i] << endl;
	}
	cout << dp.back() << endl;
}