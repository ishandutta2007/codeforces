#include <algorithm>
#include <iostream>
#include <map>
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

#define debug(x) cout << #x << " is " << x << endl;

using namespace std;

using ll = long long;
using ld = long double;


const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 10;
const int N = 1e6 + 10;

int a[N], b[N];

bool solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];	
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] < b[i]) return false;
	}
	for (int i = 1; i < n; ++i) {
		if (a[i] < a[i - 1]) return false;	
		if (b[i] < b[i - 1]) return false;
		int cnt = a[i] - a[i - 1];
		if (b[i] - b[i - 1] > cnt) return false;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		auto rez = solve();	
		if (rez) {
			cout << "YES\n";	
		} else {
			cout << "NO\n";	
		}
	}
}