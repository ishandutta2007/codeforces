#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int B = 600;
const int L = N / B + 5;

const long long INF = 1e18;

int check[(N + 1) * (B + 1)];

void solve_case(int tc = 0) {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int ans = n - 1;
	for (int d = -B; d <= B; ++d) {
		long long mn = INF;
		for (int i = 0; i < n; ++i) {
			mn = min(mn, a[i] - 1ll * d * i);
		}
		for (int i = 0; i < n; ++i) {
			++check[a[i] - 1ll * d * i - mn];
		}
		for (int i = 0; i < n; ++i) {
			ans = min(ans, n - check[a[i] - 1ll * d * i - mn]);
			check[a[i] - 1ll * d * i - mn] = 0;	
		}
	}
	for (int i = 0; i < n; ++i) {
		vector<int> use;
		int len = min(n - i, L);
		for (int j = i + 1; j < i + len; ++j) {
			if ((a[j] - a[i]) % (j - i) == 0) {
				use.push_back((a[j] - a[i]) / (j - i));
			}
		}
		if (use.empty()) {
			continue;
		}
		int mn = *min_element(use.begin(), use.end());
		int cnt = 0;
		for (int x : use) {
			++check[x - mn];
		}
		for (int x : use) {
			cnt = max(cnt, check[x - mn]);
			check[x - mn] = 0;
		}
		++cnt;
		ans = min(ans, n - cnt);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1;
	// cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}