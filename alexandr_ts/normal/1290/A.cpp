#define _CRT_SECURE_NO_WARNINGS

#include <memory>
#include <cstdio>
#include <type_traits>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <random>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>
#include <tuple>
#include <sstream>
#include <numeric>
#include <chrono>
#include <utility>
#include <functional>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;

const int INF = 1e9 + 10;
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;
const int M = 1e3 + 10;
const int N = 2e6 + 10;

int a[N];

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	m--;
	k = min(k, m);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<int> v;
	for (int i = 0; n - 1 - m + i < n; ++i) {
		v.push_back(max(a[i], a[n - 1 - m + i]));
	}
	
	multiset<int> ms;
	int len = (int)v.size() - k;
	for (int i = 0; i < len; ++i) {
		ms.insert(v[i]);
	}
	int ans = *ms.begin();
	for (int i = len; i < (int)v.size(); ++i) {
		ms.erase(ms.find(v[i - len]));
		ms.insert(v[i]);
		ans = max(ans, *ms.begin());
	}
	cout << ans << "\n";

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//FILE* stream;
	// freopen_s(&stream, "a.in", "r", stdin);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}