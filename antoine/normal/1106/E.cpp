#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Env {
	int id, d, w;

	bool operator<(const Env &other) const {
		if (w != other.w)
			return w < other.w;
		if (d != other.d)
			return d < other.d;
		return id < other.id;
	}
};

const int MaxN = (int) 1e5 + 9;
vector<Env> evts1[MaxN + 9];
vector<Env> evts2[MaxN + 9];
ll dp[MaxN + 9][201];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < k; ++i) {
		Env e;
		int s, t;
		e.id = i;
		cin >> s >> t >> e.d >> e.w;
		evts1[t].push_back(e);
		evts2[s].push_back(e);
	}

	set<Env> s;

	for (int i = n; i >= 1; --i) {
		for (auto &&e : evts1[i])
			s.insert(e);

		const Env env = s.empty() ? Env() : *(s.rbegin());

		for (int j = 0; j <= m; ++j) {
			ll &res = dp[i][j] = 1LL << 60;
			if (j > 0)
				res = min(res, dp[i + 1][j - 1]);
			if (s.empty())
				res = dp[i + 1][j];
			else
				res = min(res, env.w + dp[env.d + 1][j]);
		}
		for (auto &&e : evts2[i])
			s.erase(s.find(e));
	}

	cout << dp[1][m];
	return 0;
}