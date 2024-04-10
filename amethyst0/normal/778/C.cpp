/*AMETHYSTS*/
//#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <fstream>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <map>
#include <unordered_map>

#define ll long long
#define ld double
#define pii pair <int, int>
#define mp make_pair

using namespace std;

const int maxn = (int)3e5 + 10;
vector <pii> ed[maxn];
int ans[maxn];

pii t[maxn];
pii rt[maxn];
const int p = (int)1e9 + 7, q = 1073676287;

int my_pow(int a, int b, int mod) {
	if (b == 0) {
		return 1;
	}

	if (b & 1) {
		return ((ll)a * my_pow(a, b - 1, mod)) % mod;
	}

	int t = my_pow(a, b >> 1, mod);

	return ((ll)t * t) % mod;
}

pii operator +(pii a, pii b) {
	a.first += b.first;
	a.second += b.second;

	if (a.first >= p) {
		a.first -= p;
	}

	if (a.second >= q) {
		a.second -= q;
	}

	return a;
}

pii operator -(pii a, pii b) {
	a.first -= b.first;
	a.second -= b.second;

	if (a.first < 0) {
		a.first += p;
	}

	if (a.second < 0) {
		a.second += q;
	}

	return a;
}

pii operator *(pii a, int x) {
	a.first = ((ll)a.first * x) % p;
	a.second = ((ll)a.second * x) % q;

	return a;
}

pii operator *(pii a, pii x) {
	a.first = ((ll)a.first * x.first) % p;
	a.second = ((ll)a.second * x.second) % q;

	return a;
}

pair <set <pii>, pair <pii, int> > g[maxn];
int pos = 0;

bool cmp(pii a, pii b) {
	return g[a.first].first.size() < g[b.first].first.size();
}

void slive(int a, int b, int h, bool st = true) {
	for (auto it = g[a].first.begin(); it != g[a].first.end(); it++) {
		pii now = *it;

		now = now + g[a].second.first;
		now = now * t[g[a].second.second];

		now = now * rt[g[b].second.second];
		now = now - g[b].second.first;

		if (g[b].first.count(now)) {
			if (st) {
				ans[h]++;
			} else {
				throw 1;
			}
		} else {
			g[b].first.insert(now);
		}
	}
}

void check(int a, int b, int h) {
	for (auto it = g[a].first.begin(); it != g[a].first.end(); it++) {
		pii now = *it;

		now = now + g[a].second.first;
		now = now * t[g[a].second.second];

		now = now * rt[g[b].second.second];
		now = now - g[b].second.first;

		if (g[b].first.count(now)) {
			ans[h]++;
		}
	}
}

int dfs(int v, int h) {
	if (!ed[v].empty())
		ans[h]++;
	int it = pos++;
	g[it].second = mp(mp(0, 0), 0);
	g[it].first.insert(mp(0, 0));

	vector <pii> f;
	
	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i].first;

		int nit = dfs(u, h + 1);

		f.push_back(mp(nit, ed[v][i].second));
	}

	sort(f.begin(), f.end(), cmp);

	g[maxn - 1].first.clear();
	g[maxn - 1].second = mp(mp(0, 0), 0);

	for (int i = 0; i < (int)f.size() - 1; i++) {
		slive(f[i].first, maxn - 1, h);
	}

	if (!f.empty()) {
		check(maxn - 1, f.back().first, h);
	}

	for (int i = 0; i < (int)f.size(); i++) {
		int nit = f[i].first;
		int c = f[i].second;

		g[nit].second.second++;
		g[nit].second.first = g[nit].second.first + rt[g[nit].second.second] * (c + 1);

		if (g[it].first.size() < g[nit].first.size()) {
			swap(it, nit);
		}

		slive(nit, it, h, false);
	}

	return it;
}

int main() {
	t[0] = mp(1, 1);
	rt[0] = mp(1, 1);
	rt[1] = mp(my_pow(1234567, p - 2, p), my_pow(1234567, q - 2, q));

	for (int i = 1; i < maxn; i++) {
		t[i] = t[i - 1] * 1234567;
		if (i >= 2) {
			rt[i] = rt[i - 1] * rt[1];
		}
	}

	int n;

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		char c;

		scanf("%d %d %c", &a, &b, &c);

		ed[a].push_back(mp(b, c - 'a'));
	}

	dfs(1, 1);

	pos = 1;

	for (int i = 2; i < maxn; i++) {
		if (ans[i] > ans[pos]) {
			pos = i;
		}
	}

	cout << n - ans[pos] << endl;
	cout << pos << endl;

	return 0;
}