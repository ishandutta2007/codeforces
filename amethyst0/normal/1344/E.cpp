#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <limits.h>
#include <fstream>
#include <unordered_map>
#include <array>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
#define uint unsigned int

const int maxn = (int)1e5 + 10;

vector <pii> ed[maxn];
ll dst[maxn];

void build(int v, ll x = 0) {
	dst[v] = x;

	for (auto[u, w] : ed[v]) {
		build(u, w + x);
	}
}

vector <ll> g[maxn];

set <pair <ll, int> > s[maxn];
ll st[maxn];

int posit = 0;

const ll inf = (ll)1e18;

ll ans = inf;

int lst = 0;

vector <pll> seg;

int dfs(int v) {
	reverse(all(ed[v]));

	vector <int> its;

	for (auto[u, w] : ed[v]) {
		int nit = dfs(u);
		st[nit] -= w;

		its.push_back(nit);
	}

	int it = -1;

	int start = lst;

	if (its.empty()) {
		it = posit++;
	}
	else {
		s[its[0]].insert(mp(-st[its[0]], -1));
		
		int ps = 0;

		for (int i = 1; i < (int)its.size(); i++) {
			if (s[its[i]].size() > s[its[ps]].size()) {
				ps = i;
			}
		}

		it = its[ps];

		vector <set <pair <ll, int> >::iterator> h;

		int fir = -1;

		for (int i = 0; i < (int)its.size(); i++) {
			int nit = its[i];

			if (nit == it) {
				continue;
			}

			if (i == 0) {
				fir = lst + 1;
			}

			lst++;

			for (auto[x, id] : s[nit]) {
				ll y = x + st[nit] - st[it];

				h.push_back(s[it].insert(mp(y, lst)).first);
			}
		}

		for (auto itr : h) {
			if (itr != s[it].begin()) {
				auto pre = prev(itr);

				if (itr->second != pre->second) {
					seg.push_back(mp(pre->first + st[it] + 1, itr->first + st[it]));
				}
			}

			auto nxt = next(itr);

			if (nxt != s[it].end() && nxt->second <= start) {
				if (itr->second != nxt->second) {
					seg.push_back(mp(itr->first + 1 + st[it], nxt->first + st[it]));
				}
			}
		}

		s[it].erase(mp(-st[it], fir));
	}

	for (ll tm : g[v]) {
		s[it].insert(mp(tm - st[it], -1));
	}

	return it;
}

mt19937 rr;

int main() {
	int n, q;

	cin >> n >> q;

	for (int i = 0; i < n - 1; i++) {
		int x, y, d;

		scanf("%d %d %d", &x, &y, &d);
		//x = rr() % (i + 1) + 1;
		//y = i + 2;
		//d = 1000000000;
		x--;
		y--;
		ed[x].push_back(mp(y, d));
	}

	build(0);

	while (q--) {
		int s, t;

		scanf("%d %d", &s, &t);
		//s = rr() % n + 1;
		//t = rr() % 1000000000 + 1;
		s--;
		g[s].push_back(t + dst[s]);
	}

	dfs(0);

	sort(all(seg));

	if (!seg.empty()) {
		assert(seg[0].first > 0);
	}

	int ps = 0;
	ll tm = 1;

	multiset <ll> vals;

	ll tot = 0;

	while (true) {
		while (ps < (int)seg.size() && seg[ps].first == tm) {
			vals.insert(seg[ps].second);
			ps++;
		}

		if (vals.empty()) {
			if (ps == (int)seg.size()) {
				break;
			}

			tm = seg[ps].first;
			continue;
		}

		if ((*vals.begin()) < tm) {
			ans = *vals.begin();
			break;
		}

		vals.erase(vals.begin());
		tm++;
		continue;
	}

	vals.clear();

	if (ans == inf) {
		cout << -1 << ' ' << seg.size() << '\n';
		exit(0);
	}

	cout << ans << ' ';

	for (int i = 0; i < (int)seg.size(); i++) {
		if (seg[i].second >= ans) {
			swap(seg[i], seg.back());
			seg.pop_back();
			i--;
			continue;
		}
	}

	cout << seg.size() << '\n';
}