#pragma GCC optimize("O3")

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cstring>
#include <numeric>
#include <set>
#include <queue>
#include <deque>
#include <array>
#include <string>
#include <cmath>
#include <random>
#include <ctime>
#include <map>
#include <functional>
#include <bitset>
#include <complex>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;

const ll inf = 1e18;

int n, m;
vector<ll> a;
vector<pair<ll, int>> p, s;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	p.resize(n);
	p[0] = { a[0], 1 };
	for (int i = 1; i < n; i++) {
		p[i] = p[i - 1];
		if (p[i].second++ == m) {
			p[i].first += a[i];
			p[i].second -= m;
		}
	}
	s.resize(n);
	s.back() = { a.back(), 1 };
	for (int i = n - 2; i >= 0; i--) {
		s[i] = s[i + 1];
		if (s[i].second++ == m) {
			s[i].first += a[i];
			s[i].second -= m;
		}
	}
	ll ans = inf;
	for (int i = 0; i < n; i++) {
		ans = min(ans, 2 * (a[i] * ((i + 1 + m - 1) / m) - p[i].first) + 2 * (s[i].first - a[i] * ((n - i + m - 1) / m)));
	}
	cout << ans;
}