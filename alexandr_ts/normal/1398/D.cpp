#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const int N = 200 + 10;

int d[N][N][N];
int a[3][N];
int n[3];

void solve() {
	for (int i = 0; i < 3; ++i) cin >> n[i];
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < n[i]; ++j) {
			cin >> a[i][j];
		}
		sort(a[i], a[i] + n[i], greater<int>());
		a[i][n[i]] = 0;
	}
	for (int i = 0; i <= n[0]; ++i) {
		for (int j = 0; j <= n[1]; ++j) {
			for (int k = 0; k <= n[2]; ++k) {
				int x = d[i][j][k];
				d[i + 1][j + 1][k] = max(d[i + 1][j + 1][k], x + a[0][i] * a[1][j]);
				d[i + 1][j][k + 1] = max(d[i + 1][j][k + 1], x + a[0][i] * a[2][k]);
				d[i][j + 1][k + 1] = max(d[i][j + 1][k + 1], x + a[1][j] * a[2][k]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= n[0]; ++i) {
		for (int j = 0; j <= n[1]; ++j) {
			for (int k = 0; k <= n[2]; ++k) {
				ans = max(ans, d[i][j][k]);
			}
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