#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e14;
const ll MOD = 1e9 + 7;
const int N = 1e6 + 10;

ll a[N];

void solve() {
	int n;
	cin >> n;
	multiset<int, greater<int>> m;
	for (int i = 1; i <= n; ++i) {
		m.insert(i);
	}
	vector<pair<int, int>> ans;
	for (int i = 0; i < n - 1; ++i) {
		int x = *m.begin();
		m.erase(m.begin());
		int y = *m.begin();
		m.erase(m.begin());
		ans.push_back({x, y});
		m.insert((x + y + 1) / 2);
	}
	cout << (*m.begin()) << "\n";
	for (auto [x, y]: ans) {
		cout << x << " " << y << "\n";
	}
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