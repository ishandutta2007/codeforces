#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 1e9 + 7;
const int M = 2e3 + 10;
const int N = 1e6 + 10;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> v(k, 0);
	v[0] = min(m, n / k);
	m -= v[0];
	int cur = 1;
	while (m) {
		v[cur]++;
		m--;
		cur++;
		if (cur == v.size()) cur = 1;
	}
	cout << v[0] - v[1] << endl;
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