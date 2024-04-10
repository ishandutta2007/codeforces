#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

int a[N];
int l[N], r[N];
int pref[N];

int prefl[N];
int prefr[N];

int solve2(int l, int r, int n, int mx) {
	if (l == r) return 0;
	if (l > r) return -INF;

	int bestsum = 0;
	for (int i = l; i <= r; ++i) {
		bestsum = a[i] + max(0, bestsum);
		prefl[i] = bestsum;
	}

	bestsum = 0;
	for (int i = r; i >= l; --i) {
		bestsum = a[i] + max(0, bestsum);
		prefr[i] = bestsum;	
	}

	int ans = -INF;
	for (int i = l; i <= r; ++i) {
		ans = max(ans, prefl[i] + prefr[i] - a[i]);
	}
	return ans - mx;
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		pref[i + 1] = pref[i] + a[i];
	}


	int ans = 0;
	for (int mx = -31; mx <= 31; ++mx) {
		vector<int> ids;
		for (int i = 0; i < n; ++i) {
			if (a[i] > mx) {
				if (ids.empty()) continue;
				ans = max(ans, solve2(ids[0], ids.back(), n, mx));
				ids.clear();
			} else {
				ids.push_back(i);
			}
		}
		if (ids.size()) {
			ans = max(ans, solve2(ids[0], ids.back(), n, mx));
		}
	}	
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
}