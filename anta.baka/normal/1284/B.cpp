#define _CRT_SECURE_NO_WARNINGS

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

const int inf = 1e9;

struct ev {
	int x;
	bool type;
	bool operator < (const ev& o) const {
		return x < o.x || x == o.x && type < o.type;
	}
};

struct Fen {
	int n;
	vi t;
	Fen(int n) : n(n), t(n, 0) {}
	void upd(int v, int x) {
		for (int i = v; i < n; i |= i + 1) {
			t[i] += x;
		}
	}
	int get(int v) {
		int ret = 0;
		for (int i = v; i >= 0; i = (i & (i + 1)) - 1) {
			ret += t[i];
		}
		return ret;
	}
};

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<ev> e;
	int good = 0;
	for (int i = 0; i < n; i++) {
		int len;
		cin >> len;
		int lo = inf, hi = -inf;
		bool dec = true;
		for (int j = 0; j < len; j++) {
			int x;
			cin >> x;
			lo = min(lo, x);
			hi = max(hi, x);
			if (lo < x) {
				dec = false;
			}
		}
		if (dec) {
			e.pb({ lo, false });
			e.pb({ hi, true });
		}
		else {
			good++;
		}
	}
	ll ans = (ll)good * good + (ll)2 * good * (n - good);
	sort(all(e));
	Fen f(1000228);
	for (auto t : e) {
		if (t.type == false) {
			f.upd(t.x, 1);
		}
		else if(t.x > 0) {
			ans += f.get(t.x - 1);
		}
	}
	cout << ans;
}