#include <bits/stdc++.h>

using namespace std;

const long double EPS = 1e-9;
const long double Z = 0;

void solve_case(int tc = 0) {
	long double c, m, p, v;
	cin >> c >> m >> p >> v;
	map<array<long double, 2>, long double> dp;
	function<long double(array<long double, 2>)> solve = [&](array<long double, 2> state) {
		if (dp.find(state) != dp.end()) {
			return dp[state];
		}
		long double res = 1;
		long double p = state[0], q = state[1];
		if (abs(p) < EPS && abs(q) < EPS) {
			return res;
		}
		if (abs(p) >= EPS) {
			long double amt = min(v, p);
			if (abs(q) < EPS) {
				res += p * solve({p - amt, q});
			} else {
				res += p * solve({p - amt, q + amt / 2});
			}
		}
		if (abs(q) >= EPS) {
			long double amt = min(v, q);
			if (abs(p) < EPS) {
				res += q * solve({p, q - amt});
			} else {
				res += q * solve({p + amt / 2, q - amt});
			}
		}
		dp[state] = res;
		return res;
	};
	cout << fixed << setprecision(15) << solve({c, m}) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1;
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}