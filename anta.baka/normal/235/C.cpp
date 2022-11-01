#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <array>
#include <random>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define pb push_back

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using ld = long double;

struct Node {
	vi to;
	int mxln;
	int lk;
	Node() : to(27, -1), mxln(0), lk(-1) {}
	Node(int mxln) : to(27, -1), mxln(mxln), lk(-1) {}
	Node(const vi& to, int mxln, int lk) : to(to), mxln(mxln), lk(lk) {}
};

vector<Node> au(1);
int lst;

void append(char ch) {
	ch -= 'a';
	int cur = sz(au);
	au.emplace_back(au[lst].mxln + 1);
	int pv = lst;
	for (; pv != -1 && au[pv].to[ch] == -1; pv = au[pv].lk) {
		au[pv].to[ch] = cur;
	}
	if (pv == -1) {
		au[cur].lk = 0;
	}
	else {
		int nxt = au[pv].to[ch];
		if (au[nxt].mxln == au[pv].mxln + 1) {
			au[cur].lk = nxt;
		}
		else {
			int cl = sz(au);
			au.emplace_back(au[nxt].to, au[pv].mxln + 1, au[nxt].lk);
			au[cur].lk = au[nxt].lk = cl;
			for (; pv != -1 && au[pv].to[ch] == nxt; pv = au[pv].lk) {
				au[pv].to[ch] = cl;
			}
		}
	}
	lst = cur;
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	s.insert(s.begin(), 'z' + 1);
	int n = sz(s);
	for (auto ch : s) {
		append(ch);
	}
	vector<pii> ord(sz(au));
	for (int i = 0; i < sz(au); i++) {
		ord[i] = mp(au[i].mxln, i);
	}
	sort(all(ord));
	reverse(all(ord));
	ord.pop_back();
	vi lfs(sz(au));
	for (auto v : ord) {
		if (!lfs[v.second]) lfs[v.second] = 1;
		lfs[au[v.second].lk] += lfs[v.second];
	}
	int q;
	cin >> q;
	vi lt(sz(au));
	int ct = 0;
	while (q--) {
		string t;
		cin >> t;
		int len = sz(t);
		t += t;
		ct++;
		int ans = 0;
		int v = 0;
		for (int i = 0, r = -1; i < len; i++) {
			while (r - i + 1 < len && au[v].to[t[r + 1] - 'a'] != -1) {
				r++;
				v = au[v].to[t[r] - 'a'];
			}
			if (r - i + 1 == len) {
				if (lt[v] != ct) {
					ans += lfs[v];
					lt[v] = ct;
				}
			}
			if (au[au[v].lk].mxln == r - i) {
				v = au[v].lk;
			}
		}
		cout << ans << '\n';
	}
}