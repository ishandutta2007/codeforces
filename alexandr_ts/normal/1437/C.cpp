#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 210;

int a[N];
int d[N][N * 2];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i <= n; ++i) {
		fill(d[i], d[i] + 2 * N, INF);
	}
	fill(d[0], d[0] + 2 * N, 0);

	for (int i = 0; i < n; ++i) {
		for (int t = 0; t < 2 * N; ++t) {
			for (int t2 = t + 1; t2 < 2 * N; ++t2) {
				d[i + 1][t2] = min(d[i + 1][t2], d[i][t] + abs(a[i] - t2));
			}	
		}
	}

	cout << *min_element(d[n], d[n] + 2 * N) << "\n";
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