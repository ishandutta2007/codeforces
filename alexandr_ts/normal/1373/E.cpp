#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <type_traits>
#include <queue>
#include <cassert>
#include <utility>
#include <functional>
#include <set>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <vector>
#include <memory>
#include <string>
#include <optional>
#include <ostream>
#include <iterator>
#include <new>
#include <cstdlib>
#include <tuple>
#include <unordered_map>
#include <cstring>
#include <array>

#define debug(x) cout << #x << " is " << x << endl;

using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 10;
const int N = 1e6 + 10;
const int MAX = 1e5 + 1;

inline int f(int x) {
	int ans = 0;
	while (x) {
		ans += x % 10;
		x /= 10;	
	}
	return ans;
}

int numlen(ll x) {
	if (!x) return 1;
	int ans = 0;
	while (x) {
		ans++;
		x /= 10;	
	}
	return ans;
}

ll memo[155][11];

ll solveTL(int n, int k) {
	if (memo[n][k] != -2) return memo[n][k];
	if (n * 2 < k * (k + 1)) return memo[n][k] = -1;
	ll rez = -1;
	ll mx = MAX;
	if (n <= 10) mx = 50;
	if (n <= 20) mx = 999;
	for (ll x = 0; x < mx; ++x) {
		int sum = 0;
		for (int i = 0; i <= k; ++i) {
			sum += f(x + i);	
		}	
		if (sum == n) {
			rez = x;
			break;	
		}
	}
	return memo[n][k] = rez;
}

ll getpref(int x) {
	string res;
	while (x) {
		int d = min(x, 9);
		x -= d;
		res += (char)('0' + d);
	}	
	reverse(res.begin(), res.end());
	ll ret = 0;
	for (auto ch: res) {
		ret *= 10;
		ret += (ch - '0');	
	}
	return ret;
}


void solve() {
	int n, k;
	cin >> n >> k;
	if (memo[n][k] != -2) {
		cout << memo[n][k] << "\n";
		return;
	}
	if (k >= 3 || n <= 25 * (k + 1)) { 
		cout << solveTL(n, k) << "\n";
		return;
	}

	set<ll> cands;
	for (int np = 0; np <= min(n, 30); np++) {
		if ((n - np) % (k + 1)) continue;
		ll x = solveTL(np, k);	
		if (x == -1) continue;
		int len = numlen(x + k);
		int s = (n - np) / (k + 1);
		ll pref = getpref(s);
		for (int i = 0; i < len; ++i)
			pref *= 10;
		cands.insert(pref + x);
	}
	ll rez = -1;
	if (!cands.empty())
		rez = *cands.begin();
	memo[n][k] = rez;
	cout << rez << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i <= 150; i++)
		for (int j = 0; j <= 9; j++)
			memo[i][j] = -2;
	int t = 1;
	cin >> t;
	while (t--) {
		solve();	
	}
}