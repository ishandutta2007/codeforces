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

int a[N];

ll calc(vector<ll>& v) {
	ll mn = 0;	
	ll ans = 0;
	ll sum = 0;
	for (auto x: v) {
		sum += x;
		ans = max(ans, sum - mn);	
		mn = min(mn, sum);
	}
	return ans;
}

void solve() {
	int n;
	cin >> n;
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];	
		if (i % 2 == 0) sum += a[i];
	}
	vector<ll> v1, v2;
	for (int i = 2; i < n; i += 2) {
		v1.push_back(a[i - 1] - a[i]);	
	}
	for (int i = 0; i + 1 < n; i += 2) {
		v2.push_back(a[i + 1] - a[i]);	
	}
	/*
	cout << sum << " " << calc(v1) << " " << calc(v2) << endl;
	for (auto x: v1) cout << x << " ";cout << endl;
	for (auto x: v2) cout << x << " ";cout << endl;
	*/
	cout << sum + max(calc(v1), calc(v2)) << "\n";
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