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

struct Point {
	int x, y;
	int cnt;
	
	ll len() const {
		return (ll)x * x + (ll)y * y;
	}

	bool operator < (const Point& o) const {
		return len() < o.len();
	}
};

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, s;
	cin >> n >> s;
	vector<Point> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y >> a[i].cnt;
	}
	sort(all(a));

	for (int i = 0; i < n; i++) {

		s += a[i].cnt;

		if (s >= 1000 * 1000) {

			cout.precision(7);
			cout << fixed << sqrt(a[i].len()) << endl;
			return 0;
		}
	}
	
	cout << -1;
}