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

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define pb push_back

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int n, k;
vi x, y;
vector<vi> d;
vi ad;
vector<vi> g;
vector<bool> cov;
bool ok;
vector<bool> ans_cov;

void Kopeliovich(int v, int rem) {
	if (ok) {
		return;
	}
	if (v == n) {
		ok = true;
		ans_cov = cov;
		for (int i = 0; i < n && rem; i++) {
			if (!ans_cov[i]) {
				ans_cov[i] = true;
				rem--;
			}
		}
		return;
	}
	if (cov[v]) {
		Kopeliovich(v + 1, rem);
		return;
	}
	vi nei;
	for (int to : g[v]) {
		if (cov[to]) continue;
		nei.pb(to);
		cov[to] = true;
	}
	if (sz(nei) <= rem) {
		Kopeliovich(v + 1, rem - sz(nei));
	}
	for (auto to : nei) {
		cov[to] = false;
	}
	if (1 <= rem && sz(nei) > 1) {
		cov[v] = true;
		Kopeliovich(v + 1, rem - 1);
		cov[v] = false;
	}
}

bool check(int x) {
	for (int i = 0; i < n; i++) {
		g[i].clear();
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (d[i][j] > x) {
				g[i].pb(j);
				g[j].pb(i);
			}
		}
	}
	cov.assign(n, false);
	ok = false;
	Kopeliovich(0, k);
	return ok;
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	x.resize(n);
	y.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	d.resize(n, vi(n));
	ad.reserve(n * (n - 1) / 2 + 1);
	ad.pb(0);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			d[i][j] = d[j][i] = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
			ad.pb(d[i][j]);
		}
	}
	sort(all(ad));
	ad.erase(unique(all(ad)), ad.end());
	g.resize(n);
	int lf = 0, rg = sz(ad) - 1;
	while (lf < rg) {
		int md = (lf + rg) >> 1;
		if (check(ad[md])) {
			rg = md;
		}
		else {
			lf = md + 1;
		}
	}
	check(ad[lf]);
	for (int i = 0; i < n; i++) {
		if (ans_cov[i]) {
			cout << i + 1 << ' ';
		}
	}
}