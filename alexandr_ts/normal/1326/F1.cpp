#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <utility>
#include <functional>
#include <set>
#include <algorithm>
#include <ctime>
#include <vector>
#include <memory>
#include <string>
#include <optional>

using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 998244353;
const ll INF = 5e17 + 10;
const int M = 1e6 + 10;
const int N = 14;

int a[N][N];
vector<ll> dp[1 << N][N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < n; ++j) {
			if (s[j] == '1') {
				a[i][j] = 1;	
			}	
		}	
	}

	for (int mask = 0; mask < (1 << n); ++mask) {
		for (int i = 0; i < n; ++i) {
			dp[mask][i].resize(1 << (max(0, __builtin_popcount(mask) - 1)));
		}	
	}

	for (int i = 0; i < n; ++i) {
		dp[(1 << i)][i][0] = 1;	
	}

	for (int mask = 0; mask < (1 << n); ++mask) {
		for (int cur = 0; cur < n; ++cur) {
			if (!(mask & (1 << cur))) continue;
			for (int nxt = 0; nxt < n; ++nxt) {
				if (mask & (1 << nxt)) continue;
				for (int pref_mask = 0; pref_mask < (int)dp[mask][cur].size(); ++pref_mask) {
					dp[mask | (1 << nxt)][nxt][(pref_mask << 1) | a[cur][nxt]] += dp[mask][cur][pref_mask];
				}
			}	
		}	
	}

	vector<ll> ans(1 << (n - 1));
	for (int cur = 0; cur < n; ++cur) {
		for (size_t i = 0; i < dp[(1 << n) - 1][cur].size(); ++i) {
			ans[i] += dp[(1 << n) - 1][cur][i];	
		}	
	}	
	for (auto el: ans) {
		cout << el << " ";
	}
	cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}