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

#define debug(x) cout << #x << " is " << x << endl;

using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e9 + 10;
const ll MOD = 998244353;
const ld PI = acos(-1);
const int N = 2e5 + 10;

int a[2 * N];
int t[8 * N];
int ad[8 * N];

void build(int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = a[tl];
		return;	
	}
	int tm = (tl + tr) / 2;
	build(2 * v, tl, tm);
	build(2 * v + 1, tm + 1, tr);
	t[v] = max(t[2 * v], t[2 * v + 1]);
}

void push(int v, int tl, int tr) {
	if (!ad[v]) return;
	if (tl != tr) {
		ad[2 * v] += ad[v];	
		ad[2 * v + 1] += ad[v];	
	}
	t[v] += ad[v];
	ad[v] = 0;
}

void add(int v, int tl, int tr, int l, int r, int val) {
	push(v, tl, tr);
	if (tl > r || tr < l) {
		return;	
	}
	if (l <= tl && tr <= r) {
		ad[v] += val;
		push(v, tl, tr);
		return;		
	}
	int tm = (tl + tr) / 2;
	add(2 * v, tl, tm, l, r, val);
	add(2 * v + 1, tm + 1, tr, l, r, val);
	t[v] = max(t[2 * v], t[2 * v + 1]);
}

int get(int v, int tl, int tr, int l, int r) {
	push(v, tl, tr);
	if (tl > r || tr < l) {
		return -INF;
	}
	if (l <= tl && tr <= r) {
		return t[v];	
	}
	int tm = (tl + tr) / 2;
	return max(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

struct cmp {
	bool operator()(const pair<int, int>& l, const pair<int, int>& r) const {
		if (l.second != r.second)
			return l.second > r.second;	
		return l.first > r.first;	
	}
};

void solve() {
	int n, k, m;
	cin >> n >> k >> m;
	for (int i = 1; i <= 2 * n; ++i) {
		a[i] = i - 1;
	}
	build(1, 1, 2 * n);

	set<pair<int, int>, cmp> pts;
	multiset<int> ms;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		int j = y + abs(x - k);
		if (pts.count({x, y})) {
			pts.erase({x, y});
			ms.erase(ms.find(-j));
			add(1, 1, 2 * n, 1, j, -1);	
		} else {
			pts.insert({x, y});
			ms.insert(-j);
			add(1, 1, 2 * n, 1, j, 1);	
		}
		int tr = n;
		if (!ms.empty()) {
			tr = max(tr, -*ms.begin());	
		}
		cout << max(0, get(1, 1, 2 * n, 1, tr) - n) << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
}