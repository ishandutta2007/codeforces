#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 1e9 + 7;
const int N = 1e2 + 10;

int a[N][N];

void solve() {
	int n, m;
	cin >> n >> m;
	map<int, int> cnt;
	map<int, int> cnt1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			int d1 = i + j;
			int d2 = n + m - 2 - i - j;
			if (d1 > d2) swap(d1, d2);
			if (d1 == d2) continue;
			cnt[d1]++;
			if (a[i][j])
				cnt1[d1]++;
		}
	}
	int ans = 0;
	for (int i = 0; i < n + m; ++i) {
		int t = cnt[i];
		int t1 = cnt1[i];
		ans += min(t - t1, t1);	
	}
	cout << ans << "\n";

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}