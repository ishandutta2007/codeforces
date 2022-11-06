#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

void f() {
	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	multiset<ll> ms;
	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> a[i] >> x;
		ms.insert(a[i] - x);
	}
	ll sum = accumulate(a.begin(), a.end(), 0LL);
	int ans = 0;
	for (; sum > m && !ms.empty(); ++ans) {
		auto it = --ms.end();
		sum -= *it;
		ms.erase(it);
	}
	cout << (sum > m ? -1 : ans);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	f();
	return 0;
}