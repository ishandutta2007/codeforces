#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <type_traits>
#include <queue>
#include <cassert>
#include <utility>
#include <functional>
#include <typeinfo>
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
#include <unordered_set>
#include <cstring>
#include <array>
#include <variant>
#include <any>
#include <experimental/filesystem>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <numeric>
#include <string_view>
#include <exception>
 
#define debug(x) cout << #x << " is " << (x) << endl;
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int N = 1e6 + 10;
const ld EPS = 1e-4;
const ll MOD = 1e9 + 7;
const ll P = 29;
 
struct S {
	ll x, y, a;
} a[N];
 
ll d[N];
 
ld calc(ld y, int line_id) {
	return d[line_id] - y * a[line_id].x;
}
 
void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].x >> a[i].y >> a[i].a;
	}
 
	sort(a, a + n, [](S& a, S&b) {return a.x < b.x;});
 
	vector<int> lines;
	vector<ld> ys;
 
	for (int i = 0; i < n; ++i) {
		d[i] = a[i].x * a[i].y - a[i].a;		
		if (lines.size() > 0) {
			int id = lower_bound(ys.begin(), ys.end(), a[i].y, greater<ld>()) - ys.begin();
			d[i] = max(d[i], d[lines[id]] - a[i].y * a[lines[id]].x - a[i].a + a[i].x * a[i].y);
		}
 
		while (ys.size()) {
			int j = lines.back();
			ld newy = ((ld)d[i] - d[j]) / ((ld)a[i].x - a[j].x);
			if (newy > ys.back()) {
				ys.pop_back();
				lines.pop_back();
			} else {
				break;
			}
		}
 
		if (i) {
			int j = lines.back();
			ld newy = ((ld)d[i] - d[j]) / ((ld)a[i].x - a[j].x);
			//if (!ys.empty()) assert(newy <= ys.back());
			ys.push_back(newy);
			//cout << calc(newy, i) << endl;
			//if (lines.size()) assert(abs(calc(newy, i) - calc(newy, lines.back())) < EPS);
		}
		lines.push_back(i);
	}
 
	cout << *max_element(d, d + n) << endl;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	for (int i = 1; i <= t; ++i) {
		solve();
	}
}