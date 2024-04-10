#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 500 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m, L[MAXN][MAXN];
char G[MAXN][MAXN];
bool B[MAXN][MAXN];

int solve() {
	cin >> n >> m;

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> G[i][j];
			B[i][j] = false;
			if (G[i][j] == '*') ans++, B[i][j] = true;
		}
	}
	
	for (int i = 0; i < n; i++) {
		L[i][m - 1] = 0;
		if (G[i][m - 1] == '*') L[i][m - 1] = 1;
		for (int j = m - 2; j >= 0; j--) {
			if (G[i][j] == '*') L[i][j] = L[i][j + 1] + 1;
			else L[i][j] = 0;
		}
	}

	for (int l = 3; l <= m; l += 2) {
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < m; j++) {
				B[i][j] = false;
				if (i > 0 && j < m - 1 && B[i - 1][j + 1] && L[i][j] >= l) ans++, B[i][j] = true;
			}
		}
	}

	cout << ans << endl;

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}