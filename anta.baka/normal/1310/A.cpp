#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <random>
#include <queue>
#include <numeric>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vi a(n);
	for (int& x : a) cin >> x;
	vi b(n);
	for (int& x : b) cin >> x;
	vi ord(n);
	iota(all(ord), 0);
	sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });
	ll sum = 0;
	ll ans = 0;
	multiset<int> ts;
	int pt = 0;
	for (int c = 0; ; c++) {
		if (ts.empty()) {
			if (pt == n) break;
			c = a[ord[pt]];
		}
		while (pt < n && a[ord[pt]] == c) {
			sum += b[ord[pt]];
			ts.insert(b[ord[pt++]]);
		}
		sum -= *(--ts.end());
		ts.erase(--ts.end());
		ans += sum;
	}
	cout << ans;
}