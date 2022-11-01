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
#include <iomanip>
#include <cmath>
#include <numeric>

#define debug(x) cout << #x << " is " << x << endl;

using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e9 + 10;
const ll MOD = 998244353;
const ld PI = acos(-1);
const int N = (1 << 20);

int t[2 * N];
int a[N];

void build(int v, int tl, int tr) {
	if (tl == tr) {
		t[v] += a[tl];
		return;
	}
	int tm = (tl + tr) / 2;
	build(2 * v, tl, tm);
	build(2 * v + 1, tm + 1, tr);
	t[v] = t[2 * v] + t[2 * v + 1];
}

void add(int v, int tl, int tr, int pos) {
	if (tl == tr) {
		t[v]++;
		return;	
	}
	int tm = (tl + tr) / 2;
	if (pos <= tm) {
		add(2 * v, tl, tm, pos);	
	} else {
		add(2 * v + 1, tm + 1, tr, pos);	
	}
	t[v] = t[2 * v] + t[2 * v + 1];
}

void del(int v, int tl, int tr, int k) {
	if (tl == tr) {
		t[v]--;	
		return;
	}
	int tm = (tl + tr) / 2;
	if (t[2 * v] >= k) {
		del(2 * v, tl, tm, k);
	} else {
		del(2 * v + 1, tm + 1, tr, k - t[2 * v]);
	}
	t[v] = t[2 * v] + t[2 * v + 1];
}

int get(int v, int tl, int tr) {
	if (!t[v]) return 0;
	if (tl == tr) return tl;
	int tm = (tl + tr) / 2;
	if (t[2 * v]) return get(2 * v, tl, tm);
	return get(2 * v + 1, tm + 1, tr);
}

void solve() {
	int n, q;
	int x;
	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		a[x]++;
	}
	build(1, 0, N - 1);

	int k;
	while (q--) {
		cin >> k;
		if (k > 0) {
			add(1, 0, N - 1, k);	
		} else {
			del(1, 0, N - 1, -k);
		}
	}
	cout << get(1, 0, N - 1) << "\n";	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
}