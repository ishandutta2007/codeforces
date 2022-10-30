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

using comb = comb_util<long long, 1000000007, 2000000>;
comb cb;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, Pa, Pb;
	cin >> N >> Pa >> Pb;

	int a = (Pa * cb.inv(Pa + Pb)) % MOD;
	int b = (Pb * cb.inv(Pa + Pb)) % MOD;
	vector<vector<int> > dp(1015, vector<int>(1010, 0));
	vector<vector<int> > dp2(1015, vector<int>(1010, 0));
	dp[1][0] = 1;
	int res = 0;
	int t;
	int t1, t2 ,t3;
	for (int i = 1; i <= N + 5; i++) {
		for (int j = 0; j <= N + 5; j++) {
			if (j + i >= N) {
				//if(dp[i][j] > 0)cerr << i + j << endl;
				//res = (res + ((i+j) *  ((dp[i][j] * b) % MOD) % MOD)) % MOD;
				t = (dp[i][j] * b) % MOD;
				t1 = (i + j) * cb.inv(1 - a + MOD) % MOD;
				t2 = a * cb.inv((a - 1)*(a - 1) % MOD) % MOD;
				res = (res + (t * ((t1 + t2) % MOD) % MOD)) % MOD;
			}
			else {
				dp[i][j + i] = (dp[i][j + i] + ((dp[i][j] * b) % MOD)) % MOD;
				dp[i + 1][j] = (dp[i + 1][j] + ((dp[i][j] * a) % MOD)) % MOD;
			}
		}
	}

	cout << res << endl;
}
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int N, Pa, Pb;
//	cin >> N >> Pa >> Pb;
//
//	double a = Pa / (double)(Pa + Pb);
//	double b = Pb / (double)(Pa + Pb);
//	vector<vector<double> > dp(1005, vector<double>(1010, 0));
//	vector<vector<double> > dp2(1005, vector<double>(1010, 0));
//	dp[1][0] = 1;
//	dp2[1][0] = 1;
//	double res = 0;
//	double t;
//	for (int i = 1; i <= N + 5; i++) {
//		for (int j = 0; j <= N + 5; j++) {
//			if (j + i >= N) {
//				t = (dp[i][j] * b);
//
//				if (dp[i][j] > 0)cerr << i + j << endl;
//				if (dp[i][j] > 0)cerr << dp[i][j] << endl;
//				res = res + t * (((i + j) / (1 - a)) + (a / ((1 - a)*(1 - a))));
//				//res = res + t * (i + j);
//				//res = res + t * (i + j + 1) * a;
//				//res = res + t * (i + j + 2) * a * a;
//			}
//			else {
//				//if (dp[i][j] > 0) {
//					dp[i][j + i] = (dp[i][j + i] + dp[i][j] * b);
//					dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * a);
//					//dp2[i][j + i] = dp2[i][j + i] + (dp2[i][j] + 1) * dp[i][j];
//					//dp2[i + 1][j] = dp2[i + 1][j] + (dp2[i][j] + 1) * dp[i][j];
//				//}
//			}
//		}
//	}
//	//cout << res << endl;
//	//res = res + (1 / a) - 1;
//	//res = res + (1 / b) - 1;
//	cout << res << endl;
//}