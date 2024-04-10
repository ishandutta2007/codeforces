#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

vector<int> g[N];
int ans[N];
bool used[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		g[i].clear();
	}
	fill(used, used + n, false);
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			int x;
			cin >> x;
			g[i].push_back(x - 1);
		}
	}
	fill(ans, ans + n, -1);
	for (int i = 0; i < n; ++i) {
		for (auto u: g[i]) {
			if (!used[u]) {
				used[u] = true;
				ans[i] = u;
				break;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (ans[i] == -1) {
			for (int j = 0; j < n; ++j) {
				if (!used[j]) {
					cout << "IMPROVE\n" << i + 1 << " " << j + 1 << "\n";
					return;
				}
			}
		}
	}
	cout << "OPTIMAL\n";
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