#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <numeric>
#include <map>
#include <vector>
#include <set>
#include <cassert>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cmath>
#include <string>
#include <queue>
#include <unordered_map>
#include <iomanip>

using namespace std;


typedef long long ll;
typedef long double ld;

const int INF = (int)1e9 + 10;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const ll MOD = (int)1e9 + 7;
const int M = (int)4e4 + 10;
const int N = (int)1e6 + 10;

pair<int, int> a[N];

void go(multiset<pair<int, int>>& s1, multiset<pair<int, int>>& s2, int x) {
	while (!s2.empty() && s2.begin()->first<= x) {
		auto v = *s2.begin();
		s1.insert(make_pair(-v.second, v.first));
		s2.erase(s2.begin());
	}
}

void solve() {
	int n;
	cin >> n;
	multiset<pair<int, int>> s1, s2;
	int x = INF;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		x = min(x, a[i].first);
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i].second;
		s2.insert(a[i]);
	}

	ll ans = 0;
	while (s1.size() || s2.size()) {
		while (s1.size()) {
			auto v = *s1.begin();
			s1.erase(s1.begin());
			ans += (ll)(x - v.second) * -v.first;
			x++;
			go(s1, s2, x);
		}
		if (s2.size()) {
			x = s2.begin()->first;
			go(s1, s2, x);
		}
	}

	cout << ans << endl;
}

int main() {
	//freopen("a.in", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
}