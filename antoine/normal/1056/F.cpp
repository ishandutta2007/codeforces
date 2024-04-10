#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

inline void minimize(double &x, const double y) {
	x = min(x, y);
}

struct Prob {
	int diff, score;
	bool operator<(const Prob &other) const {
		return diff > other.diff;
	}
};

Prob probs[109];
double dp[102][1002];
const double Inf = 1e100;
double pp9[109];

int f() {
	int n;
	double C, T;
	cin >> n >> C >> T;

	for (int i = 0; i < n; ++i)
		cin >> probs[i].diff >> probs[i].score;

	sort(probs, probs + n);

	for (int j = 0; j <= n; ++j)
		for (int k = 0; k <= 1000; ++k)
			dp[j][k] = Inf;

	dp[0][0] = 0;
	for (int i = 0; i < n; ++i)
		for (int j = n - 1; j >= 0; --j)
			for (int k = 1000 - probs[i].score; k >= 0; --k)
				minimize(dp[j + 1][k + probs[i].score], dp[j][k] + probs[i].diff / pp9[j + 1]);

	int ans = 0;
	for (int j = n; j > 0; --j)
		for (int k = 1000; k > 0; --k) {
			if (dp[j][k] >= Inf)
				continue;

			double lo = 0;
			double hi = T;

			auto g = [&](const double &t) {
				return t + 10 * j + dp[j][k] / (1.0 + C * t);
			};

			for (int rep = 0; rep < 50; ++rep) {
				const double t1 = lo + (hi - lo) * 1.0 / 3.0;
				const double t2 = lo + (hi - lo) * 2.0 / 3.0;
				if (g(t1) < g(t2))
					hi = t2;
				else
					lo = t1;
			}
			if (g(lo) <= T)
				ans = max(ans, k);
		}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	pp9[0] = 1.0;
	for (int i = 1; i <= 100; ++i)
		pp9[i] = pp9[i - 1] * .9;

	int T;
	cin >> T;
	while (T--)
		cout << f() << '\n';
	return 0;
}