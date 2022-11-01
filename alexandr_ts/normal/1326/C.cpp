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
const int N = 2e6 + 10;


void solve() {
	int n, k;
	cin >> n >> k;
	set<int> s;
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (x > n - k) {
			sum += x;
			s.insert(i);	
		}	
	}

	vector<int> v{s.begin(), s.end()};
	ll ans = 1;
	for (int i = 1; i < (int)v.size(); ++i) {
		ll k = (v[i] - v[i - 1]);
		ans = (ans * k) % MOD;	
	}
	cout << sum << " "<< ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}