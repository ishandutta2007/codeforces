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
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

ll n, L;

void triple(vector<ll> &v) {
	assert(n == v.size());
	for (int i = 0; i < (n << 1); ++i)
		v.push_back(v[i] + L);
}

bool f(const int mid, const vector<ll> a, const vector<ll> b) {
	int maxDiff = -1e9;
	for (int i = n, j = 0; i < (n << 1); ++i) {
		while (j + 1 < b.size() && b[j] < a[i] - mid)
			++j;
		maxDiff = max(maxDiff, j - i);
	}
	for (int i = n; i < (n << 1); ++i)
		if (i + maxDiff >= b.size() || b[i + maxDiff] > a[i] + mid)
			return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> L;
	vector<ll> a(n), b(n);
	for (ll i = 0; i < n; ++i)
		cin >> a[i];
	for (ll i = 0; i < n; ++i)
		cin >> b[i];


	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	triple(a), triple(b);

	ll lo = 0;
	ll hi = L;
	while (lo < hi) {
		ll mid = (lo + hi) >> 1;
		if (f(mid, a, b))
			hi = mid;
		else
			lo = mid + 1;
	}
	cout << lo;
	return 0;
}