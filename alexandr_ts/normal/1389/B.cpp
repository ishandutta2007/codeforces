#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const int M = 21;
const int N = 1e6 + 10;

int a[N];
int d[N][7][2];


void solve() {
	int n, k, z;
	cin >> n >> k >> z;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= z; ++j) {
			d[i][j][0] = d[i][j][1] = -1;
		}
	}

	d[0][0][0] = a[0];

	for (int i = 0; i <= k; ++i) {
		for (int j = 0; j <= z; ++j) {
			int p = i - 2 * j;
			if (p < 0) continue;
			if (d[i][j][0] != -1) {
				d[i + 1][j][1] = max(d[i + 1][j][1], d[i][j][0] + a[p + 1]);
			}
			if (d[i][j][1] != -1) {
				if (p + 1 < n) {
					d[i + 1][j][1] = max(d[i + 1][j][1], d[i][j][1] + a[p + 1]);
				}
				if (p - 1 >= 0) {
					d[i + 1][j + 1][0] = max(d[i + 1][j + 1][0], d[i][j][1] + a[p - 1]);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= z; ++i) {
		ans = max(ans, d[k][i][0]);
		ans = max(ans, d[k][i][1]);
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