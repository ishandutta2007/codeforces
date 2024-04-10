#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 14;
const int N = 5e2 + 10;

int a[N];
bool ok[N][N];

void check(int l, int n) {
	vector<int> v;
	for (int i = l; i < n; ++i) {
		v.push_back(a[i]);
		while (v.size() >= 2 && v.back() == v[(int)v.size() - 2]) {
			v.pop_back();
			v.back()++;	
		}
		if (v.size() == 1) {
			ok[l][i] = true;
		}
	}
}

int d[N][N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int l = 0; l < n; ++l) {
		check(l, n);
	}

	for (int len = 1; len <= n; ++len) {
		for (int l = 0; l + len - 1 < n; ++l) {
			int r = l + len - 1;
			if (len == 1 || ok[l][r]) {
				d[l][r] = 1;
				continue;
			}
			d[l][r] = r - l + 1;
			for (int m = l; m < r; ++m) {
				d[l][r] = min(d[l][r], d[l][m] + d[m + 1][r]);
			}
		}
	}
	cout << d[0][n - 1] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
}