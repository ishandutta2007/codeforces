#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
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
#define eb emplace_back
#define endl '\n'
#define mp make_pair

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;

int n, m, k;
vector<vi> a, p, dp;

int get(int i, int l, int r) {
	return (p[i][r] - (l ? p[i][l - 1] : 0));
}

struct segTree {
	struct Node {
		int mx, ad;
	};
	Node merge(const Node& a, const Node& b) {
		return { max(a.mx, b.mx), 0 };
	}
	vector<Node> t;
	segTree(int n) : t(4 * n, { 0, 0 }) {}
	void push(int v) {
		int x = t[v].ad;
		if (x != 0) {
			t[v].ad = 0;
			t[v << 1].ad += x;
			t[v << 1].mx += x;
			t[v << 1 | 1].ad += x;
			t[v << 1 | 1].mx += x;
		}
	}
	void upd(int v, int l, int r, int l1, int r1, int x) {
		if (r < l1 || r1 < l) return;
		if (l1 <= l && r <= r1) {
			t[v].ad += x;
			t[v].mx += x;
			return;
		}
		push(v);
		int m = (l + r) >> 1;
		upd(v << 1, l, m, l1, r1, x);
		upd(v << 1 | 1, m + 1, r, l1, r1, x);
		t[v] = merge(t[v << 1], t[v << 1 | 1]);
	}
};

int isec(int i, int j, int jj) {
	int l = max(j - k + 1, jj - k + 1);
	int r = min(j, jj);
	return (l <= r ? get(i - 1, l, r) : 0);
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	a.resize(n + 1, vi(m));
	p.resize(n + 1, vi(m));
	dp.resize(n + 1, vi(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			p[i][j] = a[i][j] + (j > 0 ? p[i][j - 1] : 0);
		}
	}
	for (int j = k - 1; j < m; j++) {
		dp[1][j] = get(0, j - k + 1, j) + get(1, j - k + 1, j);
	}
	for (int i = 2; i < n + 1; i++) {
		segTree t(m);
		for (int j = k - 1; j < m; j++) {
			t.upd(1, 0, m - 1, j, j, dp[i - 1][j] - isec(i, k - 1, j));
		}
		for (int j = k - 1; j < m; j++) {
			dp[i][j] = t.t[1].mx + get(i - 1, j - k + 1, j) + get(i, j - k + 1, j);
			if (max(0, j - k + 1) <= j) {
				t.upd(1, 0, m - 1, max(0, j - k + 1), j, a[i - 1][j - k + 1]);
			}
			if (j + 1 <= min(m - 1, j + k)) {
				t.upd(1, 0, m - 1, j + 1, min(m - 1, j + k), -a[i - 1][j + 1]);
			}
		}
	}
	cout << *max_element(all(dp[n]));
}