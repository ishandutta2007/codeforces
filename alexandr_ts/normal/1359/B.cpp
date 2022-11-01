#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 1e9 + 7;
const int M = 2e3 + 10;
const int N = 1e6 + 10;

string s[N];

void solve() {
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	y = min(y, 2 * x);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < s[i].size(); j++) {
			if (s[i][j] == '.' && j + 1 < s[i].size() && s[i][j + 1] == '.') {
				j++;
				ans += y;
			} else if (s[i][j] == '.') {
				ans += x;
			}
		}
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin>> t;
	while (t--) {
		solve();
	}
}