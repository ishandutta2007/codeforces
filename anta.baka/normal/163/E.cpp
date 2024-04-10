#define CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <random>
#include <functional>
#include <complex>
#include <array>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using ld = long double;

const int ALPHABET = 26;
struct state {
	array<int, ALPHABET> trans = {};
	int link = 0;
	bool term = false;
};
struct aho_corasick {
	vector<state> states = { state() };
	int add_str(const string& s) {
		int cur = 0;
		for (char c : s) {
			c -= 'a';
			int& to = states[cur].trans[c];
			if (to) {
				cur = to;
			}
			else {
				cur = to = sz(states);
				states.emplace_back(state());
			}
		}
		states[cur].term = true;
		return cur;
	}
	void build() {
		deque<int> q = { 0 };
		while (!q.empty()) {
			int v = q.front();
			q.pop_front();
			states[v].term |= states[states[v].link].term;
			for (int c = 0; c < ALPHABET; c++) {
				if (int u = states[v].trans[c]) {
					states[u].link = v ? states[states[v].link].trans[c] : 0;
					q.pb(u);
				}
				else {
					states[v].trans[c] = states[states[v].link].trans[c];
				}
			}
		}
	}
};

struct seg_tree {
	int n;
	vi t;
	seg_tree(int n) : n(n), t(2 * n, 0) {}
	void upd(int l, int r, int x) {
		for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
			if (l & 1) {
				t[l] += x;
			}
			if (!(r & 1)) {
				t[r] += x;
			}
		}
	}
	int get(int v) {
		int ret = 0;
		for (v += n; v; v >>= 1) {
			ret += t[v];
		}
		return ret;
	}
};

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	int q, m;
	cin >> q >> m;
	aho_corasick pipindrik;
	vi where(m);
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		where[i] = pipindrik.add_str(s);
	}
	pipindrik.build();
	int n = sz(pipindrik.states);
	vector<vi> suf_g(n);
	for (int u = 1; u < n; u++) {
		suf_g[pipindrik.states[u].link].pb(u);
	}
	vi in(n), out(n);
	int timer = 0;
	function<void(int)> dfs = [&timer, &suf_g, &in, &out, &dfs](int v) {
		in[v] = timer++;
		for (int to : suf_g[v]) {
			dfs(to);
		}
		out[v] = timer;
	};
	dfs(0);
	seg_tree t(n);
	vector<char> alive(m, true);
	for (int i = 0; i < m; i++) {
		int u = where[i];
		t.upd(in[u], out[u] - 1, 1);
	}
	while (q--) {
		char c;
		cin >> c;
		if (c == '?') {
			string s;
			cin >> s;
			int ans = 0;
			int aho_v = 0;
			for (char c : s) {
				c -= 'a';
				aho_v = pipindrik.states[aho_v].trans[c];
				ans += t.get(in[aho_v]);
			}
			cout << ans << '\n';
		}
		else {
			int i;
			cin >> i;
			--i;
			bool make = (c == '+');
			if (alive[i] == make) {
				continue;
			}
			int aho_v = where[i];
			t.upd(in[aho_v], out[aho_v] - 1, c == '+' ? 1 : -1);
			alive[i] = make;
		}
	}
}