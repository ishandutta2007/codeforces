#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
// const long long mod = 99;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, m, K;
bool viv = false;

int r[505][505];
int d[505][505];
int mn[505][505];
int ans[505][505];


 inline bool chmin(int &x, const int& y) { return y < x ? x = y, 1 : 0; }

void solve() {
	cin >> n >> m >> K;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 1; j++) {
			cin >> r[i][j];
			// mn[i][j] = min(mn[i][j], r[i][j]);
			// mn[i][j + 1] = min(mn[i][j + 1], r[i][j]);
		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			cin >> d[i][j];
			// mn[i][j] = min(mn[i][j], d[i][j]);
			// mn[i + 1][j] = min(mn[i + 1][j], d[i][j]);
		}
	}


	int sh2[23][23];
	int sh[23][23];
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			for (int i = 0; i < 23; i++)
				for (int j = 0; j < 23; j++)
					sh2[i][j] = mod, sh[i][j] = mod;
			sh2[11][11] = 0;
			for (int k = 1; k <= K / 2; k++) {
				for (int i = -k; i <= k; i++)
					for (int j = -k + abs(i); j <= k - abs(i); j++) {
							int a = x + i, b = y + j;
							int res = mod;
							if (0 <= a && a < n) {
		 						if (0 <= b && b < m - 1)
		 						    chmin(res, sh2[11 + i][j + 12] + r[a][b]);
								// 	res = min(res, sh2[11 + i][j + 12] + r[a][b]);
								if (0 <= b - 1 && b - 1 < m - 1)
		 						    chmin(res, sh2[11 + i][j + 10] + r[a][b - 1]);
								// 	res = min(res, sh2[11 + i][j + 10] + r[a][b - 1]);
							}
							if (0 <= b && b < m) {
								if (0 <= a && a < n - 1)
		 						    chmin(res, sh2[12 + i][j + 11] + d[a][b]);
								// 	res = min(res, sh2[12 + i][j + 11] + d[a][b]);
								if (0 <= a - 1 && a - 1 < n - 1)
		 						    chmin(res, sh2[10 + i][j + 11] + d[a - 1][b]);
								// 	res = min(res, sh2[10 + i][j + 11] + d[a - 1][b]);
							}
							sh[k + i][k + j] = res;
						}
				for (int i = -k; i <= k; i++)
					for (int j = -k + abs(i); j <= k - abs(i); j++) 
							sh2[11 + i][11 + j] = sh[k + i][k + j];
			}
			ans[x][y] = mod;
			for (int i = 0; i < 23; i++) {
				for (int j = 0; j < 23; j++) {
					ans[x][y] = min(ans[x][y], 2 * sh2[i][j]);
				}
			}
			if (ans[x][y] >= mod || (K & 1))
				ans[x][y] = -1;
			cout << ans[x][y] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}