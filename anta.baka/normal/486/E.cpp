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

const int M1 = 1e9 + 7;
const int M2 = 998244353;

struct Node {
	int mx;
	int r1;
	int r2;
};

int add(int a, int b, int M) {
	if ((a += b) >= M) {
		a -= M;
	}
	return a;
}

Node merge(const Node& a, const Node& b) {
	if (a.mx != b.mx) {
		return (a.mx < b.mx ? b : a);
	}
	return { a.mx, add(a.r1, b.r1, M1), add(a.r2, b.r2, M2) };
}

const int N = 1e5 + 228;

Node t[4 * N];

void upd(int v, int l, int r, int pos, const Node& u) {
	if (l == r) {
		if (u.mx == t[v].mx) {
			t[v].r1 = add(t[v].r1, u.r1, M1);
			t[v].r2 = add(t[v].r2, u.r2, M2);
		}
		else if(t[v].mx < u.mx) {
			t[v] = u;
		}
		return;
	}
	int m = (l + r) >> 1;
	if (pos <= m) {
		upd(v << 1, l, m, pos, u);
	}
	else {
		upd(v << 1 | 1, m + 1, r, pos, u);
	}
	t[v] = merge(t[v << 1], t[v << 1 | 1]);
}

Node get(int v, int l, int r, int l1, int r1) {
	if (r < l1 || r1 < l) return { 0, 0, 0 };
	if (l1 <= l && r <= r1) return t[v];
	int m = (l + r) >> 1;
	return merge(get(v << 1, l, m, l1, r1), get(v << 1 | 1, m + 1, r, l1, r1));
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vi a(n);
	for (auto& x : a) cin >> x;
	vector<Node> pref;
	int hi = 0;
	for (int i = 0; i < n; i++) {
		auto x = get(1, 0, N - 1, 0, a[i] - 1);
		x.mx++;
		if (x.mx == 1) {
			x.r1 = add(x.r1, 1, M1);
			x.r2 = add(x.r2, 1, M2);
		}
		pref.pb(x);
		upd(1, 0, N - 1, a[i], x);
		hi = max(hi, x.mx);
	}
	int r1 = 0, r2 = 0;
	for (auto u : pref) {
		if (u.mx == hi) {
			r1 = add(r1, u.r1, M1);
			r2 = add(r2, u.r2, M2);
		}
	}
	memset(t, 0, sizeof(t));
	vector<Node> suff;
	for (int i = n - 1; i >= 0; i--) {
		auto x = get(1, 0, N - 1, a[i] + 1, N - 1);
		x.mx++;
		if (x.mx == 1) {
			x.r1 = add(x.r1, 1, M1);
			x.r2 = add(x.r2, 1, M2);
		}
		suff.pb(x);
		upd(1, 0, N - 1, a[i], x);
	}
	reverse(all(suff));
	for (int i = 0; i < n; i++) {
		auto u = pref[i], v = suff[i];
		if (u.mx + v.mx - 1 != hi) {
			cout << 1;
			continue;
		}
		if (1LL * u.r1 * v.r1 % M1 != r1 || 1LL * u.r2 * v.r2 % M2 != r2) {
			cout << 2;
		}
		else {
			cout << 3;
		}
	}
}