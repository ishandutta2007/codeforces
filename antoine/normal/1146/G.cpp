#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

struct Constr {
	int l, r, x, c;
	bool operator<(const Constr &other) const {
		return x > other.x;
	}
};

const int Mx = 59;
ll dp[Mx][Mx][Mx];
ll cost[Mx];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int N, H, M;
	cin >> N >> H >> M;

	vector<Constr> constraints(M);
	for (Constr &constr : constraints)
		cin >> constr.l >> constr.r >> constr.x >> constr.c;
	sort(constraints.begin(), constraints.end());

	for (int len = 0; len <= N; ++len) {
		for (int i = 1; i + len - 1 <= N; ++i) {
			const int j = i + len - 1;

			vector<Constr> active = constraints;
			active.erase(remove_if(active.begin(), active.end(), [&](const Constr &constr) {
				return constr.l < i || constr.r > j;
			}), active.end());
			memset(cost, 0, sizeof cost);

			for (int h = 0; h <= H; ++h) {
				while (!active.empty() && active.back().x < h) {
					for (int k = active.back().l; k <= active.back().r; ++k)
						cost[k] += active.back().c;
					active.pop_back();
				}
				ll &res = dp[i][j][h] = 0;
				if (!len || !h)
					continue;
				res = dp[i][j][h - 1];
				for (int k = i; k <= j; ++k)
					res = max(res, h * h - cost[k] + dp[i][k - 1][h] + dp[k + 1][j][h]);
				assert(res >= 0);
			}
		}
	}

	cout << dp[1][N][H] << endl;
	assert((int )constraints.size() == M);
	return 0;
}