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

const int N = 1e6 + 10;
const ll MOD = 1e9 + 7;

int a[N];

void del(set<int>& s, multiset<int, greater<int>>& m, int x) {
	if (s.size() == 1) {
		s.erase(x);
		return;	
	}
	auto it = s.find(x);
	assert(it != s.end());
	if (it == s.begin()) {
		int x2 = *next(s.begin());
		m.erase(m.find(x2 - x));
		s.erase(x);
		return;
	}
	if (next(it) == s.end()) {
		int x1 = *prev(it);	
		m.erase(m.find(x - x1));
		s.erase(x);
		return;
	}
	int x1 = *prev(it);
	int x2 = *next(it);
	m.erase(m.find(x2 - x));
	m.erase(m.find(x - x1));
	m.insert(x2 - x1);
	s.erase(x);
}

void add(set<int>& s, multiset<int, greater<int>>& m, int x) {
	if (s.empty()) {
		s.insert(x);
		return;	
	}
	int mn = *s.begin();
	if (x < mn) {
		m.insert(mn - x);
		s.insert(x);
		return;
	}
	int mx = *prev(s.end());
	if (x > mx) {
		m.insert(x - mx);	
		s.insert(x);
		return;
	}	
	auto it2 = s.lower_bound(x);
	auto it1 = prev(it2);
	int x2 = *it2;
	int x1 = *it1;
	m.erase(m.find(x2 - x1));
	m.insert(x2 - x);
	m.insert(x - x1);
	s.insert(x);
}

void solve() {
	int n, q;
	cin >> n >> q;
	set<int> s;
	multiset<int, greater<int>> m;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		add(s, m, x);
	}
	if (s.size() <= 1) {
		cout << "0\n";	
	} else {
		int mx = *prev(s.end());
		int mn = *s.begin();
		cout << mx - mn - *m.begin() << "\n";
	}
	for (int i = 0; i < q; ++i) {
		int t, x;
		cin >> t >> x;
		if (t == 1) {
			add(s, m, x);
		} else {
			del(s, m, x);	
		}
		if (s.size() <= 1) {
			cout << "0\n";	
		} else {
			int mx = *prev(s.end());
			int mn = *s.begin();
			cout << mx - mn - *m.begin() << "\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	for (int i = 1; i <= t; ++i) {
		solve();
	}
}