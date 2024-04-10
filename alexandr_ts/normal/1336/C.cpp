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
#include <variant>
#include <any>
#include <experimental/filesystem>
#include <fstream>
#include <numeric>

#define debug(x) cout << #x << " is " << x << endl;

using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e9 + 10;
const ll MOD = 998244353;
const int N = 3010;

void add(int& x, int val) {
	x += val;
	if (x >= MOD) x -= MOD;
}

bool eq(char c1, char c2) {
	if (c1 == '*') return true;
	if (c2 == '*') return true;
	return c1 == c2;
}

int d[N][N];

void solve() {
	string s, t;
	cin >> s >> t;
	int n = (int)s.size();
	int m = (int)t.size();
	while (t.size() < s.size()) {
		t += '*';	
	}
	for (int i = 0; i < n; ++i) {
		if (eq(s[0], t[i])) {
			d[0][i] = 2;	
		}	
	}

	for (int i = 0; i + 1 < n; ++i) {
		for (int l = 0; l < n; ++l) {
			if (!d[i][l]) continue;	
			int r = l + i;	
			if (l && eq(s[i + 1], t[l - 1])) {
				add(d[i + 1][l - 1], d[i][l]);	
			}
			if (r + 1 < n && eq(s[i + 1], t[r + 1])) {
				add(d[i + 1][l], d[i][l]);	
			}
		}	
	}
	int ans = 0;
	for (int i = m - 1; i < n; ++i) {
		add(ans, d[i][0]);	
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();	
	}
}