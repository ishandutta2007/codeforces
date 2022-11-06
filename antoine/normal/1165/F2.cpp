#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int Mx = (int) 4e5 + 9;

int n;
vector<int> offers[Mx + 9];
int need[Mx + 9];

bool f(const int mid) {
	vector<vector<int>> dp(mid);
	for (int t = 0; t < n; ++t) {
		auto it = lower_bound(offers[t].begin(), offers[t].end(), mid);
		if (it != offers[t].begin()) {
			dp[*--it].push_back(t);
		}
	}
	int curr = 0;
	vector<int> bought(n, 0);
	for (int d = 0; d < mid; ++d) {
		curr++;
		for (int t : dp[d])
			while (curr && bought[t] < need[t]) {
				curr--;
				bought[t]++;
			}
	}
	for (int t = 0; t < n; ++t) {
		assert(need[t] >= bought[t]);

		curr -= 2 * (need[t] - bought[t]);
		if (curr < 0)
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> need[i];

	for (int i = 0; i < m; ++i) {
		int d, t;
		cin >> d >> t;
		--d, --t;
		offers[t].push_back(d);
	}
	for (int t = 0; t < n; ++t)
		sort(offers[t].begin(), offers[t].end());

	int lo = 0;
	int hi = Mx - 1;
	while (lo < hi) {
		const int mid = (lo + hi) / 2;
		if (f(mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	cout << lo;
	return 0;
}