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

struct Node {
	int cnt;
	ll sum;
	int apw;
};

vector<Node> t;

Node merge(const Node& a, const Node& b) {
	return { a.cnt + b.cnt, a.sum + b.sum, -1 };
}

void push(int v) {
	int x = t[v].apw;
	if (x != -1) {
		t[v].apw = -1;
		t[v << 1].apw = t[v << 1 | 1].apw = x;
		t[v << 1].sum = t[v << 1].cnt * (ll)x;
		t[v << 1 | 1].sum = t[v << 1 | 1].cnt * (ll)x;
	}
}

void Set(int v, int l, int r, int pos, int x) {
	if (l == r) {
		t[v].cnt = x;
		t[v].sum = x * t[v].apw;
		return;
	}
	push(v);
	int m = (l + r) >> 1;
	if (pos <= m) {
		Set(v << 1, l, m, pos, x);
	}
	else {
		Set(v << 1 | 1, m + 1, r, pos, x);
	}
	t[v] = merge(t[v << 1], t[v << 1 | 1]);
}

void SetSeg(int v, int l, int r, int l1, int r1, int x) {
	if (r < l1 || r1 < l) return;
	if (l1 <= l && r <= r1) {
		t[v].apw = x;
		t[v].sum = t[v].cnt * (ll)x;
		return;
	}
	push(v);
	int m = (l + r) >> 1;
	SetSeg(v << 1, l, m, l1, r1, x);
	SetSeg(v << 1 | 1, m + 1, r, l1, r1, x);
	t[v] = merge(t[v << 1], t[v << 1 | 1]);
}

const int MASK = (1 << 30) - 1;

int n;
unsigned long long ans(0); // BigInt
int ans26;
int ans230;
vi pi;
string s;
vector<pii> st;
vector<vi> kill_me_plz;
set<int> setik;

void Add(int i) {
	assert(!setik.count(i));
	Set(1, 0, n - 1, i, 1);
	setik.insert(i);
}

void Kill(int i) {
	assert(setik.count(i));
	Set(1, 0, n - 1, i, 0);
	setik.erase(i);
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;
	pi.resize(n, 0);
	kill_me_plz.resize(n);
	t.resize(4 * n, { 0, 0, -1 });
	for (int i = 0; i < n; i++) {
		char c;
		int w;
		cin >> c >> w;
		c = char((c - 'a' + ans26) % 26 + 'a');
		w = w ^ (ans230 & MASK);
		s.pb(c);

		if (i == 0) {
			Set(1, 0, n - 1, 0, 1);
		}

		while (!st.empty() && w <= st.back().first) {
			st.pop_back();
		}
		SetSeg(1, 0, n - 1, st.empty() ? 0 : st.back().second + 1, i, w);
		st.pb({ w, i });

		if (i) {

			int k = pi[i - 1];
			while (k > 0 && s[i] != s[k]) {
				k = pi[k - 1];
			}
			pi[i] = k + (s[i] == s[k]);

			if (s[0] == s[i]) {
				Add(i);
			}

			if (pi[i] > 0) {
				kill_me_plz[i] = kill_me_plz[pi[i] - 1];
			}

			for (int len : kill_me_plz[i]) {
				Kill(i - len + 1);
			}

			int tmp;
			while (!setik.empty() && (tmp = *setik.begin()) < i - pi[i] + 1) {
				Kill(tmp);
				kill_me_plz[i].pb(i - tmp + 1);
			}
		}

		{
			ll x = t[1].sum;
			ans += x;
			ans26 = (ans26 + x) % 26;
			ans230 = (ans230 + x) % (MASK + 1);
			cout << ans << '\n';
		}
	}
}