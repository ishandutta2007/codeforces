#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using vi = vector<int>; using pii = pair<int, int>; using ld = long double;

struct Line {
	ld k, b;
	int cnt;
};

ld isec(const Line& l1, const Line& l2) {
	return (l1.b - l2.b) / (l2.k - l1.k);
}

struct HullDebil {
	vector<Line> h;
	int pt;
	ld x;
	ld add_b;
	HullDebil() : h(), pt(0), x(0), add_b(0) {}
	void add(Line l) {
		l.b -= add_b;
		int s;
		while ((s = sz(h)) > 1 && isec(h[s - 2], h[s - 1]) > isec(h[s - 1], l)) h.pop_back();
		h.pb(l);
		pt = min(pt, max(0, s - 1));
	}
	void shift_x(ld d) {
		x += d;
		while (pt < sz(h) - 1 && isec(h[pt], h[pt + 1]) < x) pt++;
	}
	auto get() {
		return make_pair(h[pt].k * x + h[pt].b + add_b, h[pt].cnt + 1);
	}
};

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	int n, k; cin >> n >> k;
	vi a(n);
	for (auto& x : a) cin >> x;
	vector<ll> p(n);
	p[0] = a[0];
	for (int i = 1; i < n; i++) p[i] = p[i - 1] + a[i];
	auto solve = [&](ld x) {
		HullDebil hd;
		vector<pair<ld, int>> dp(n);
		for (int i = 0; i < n; i++) {
			if (!i) hd.add({ 0, x, 0 });
			else hd.add({ (ld)-p[i - 1], x + dp[i - 1].first + p[i - 1] * hd.x, dp[i - 1].second });
			hd.shift_x((ld)1 / a[i]);
			hd.add_b += (ld)p[i] / a[i];
			dp[i] = hd.get();
		}
		return dp[n - 1];
	};
	ld lf = -1e16, rg = 1e16;
	for(int i = 0; i < 100; i++) {
		ld md = (lf + rg) / 2;
		if (solve(md).second >= k) lf = md;
		else rg = md;
	}
	cout << setprecision(10) << fixed << solve(lf).first - lf * k;
}