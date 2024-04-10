#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;


void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < k; ++i) {
		int x, y;
		cin >> x >> y;
	}
	for (int i = 0; i < k; ++i) {
		int x, y;
		cin >> x >> y;
	}

	string s;
	for (int i = 0; i < m - 1; ++i) {
		s += "L";
	}
	for (int i = 0; i < n - 1; ++i) {
		s += "U";
	}

	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) {
			for (int j = 0; j < m - 1; ++j) {
				s += 'R';
			}
		} else {
			for (int j = 0; j < m - 1; ++j) {
				s += 'L';
			}
		}
		if (i + 1 < n) s += 'D';
	}
	cout << s.size() << endl;
	cout << s << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
}