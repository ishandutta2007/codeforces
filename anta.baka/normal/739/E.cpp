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

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	int n, a, b;
	cin >> n >> a >> b;
	vector<ld> p(n), u(n);
	for (auto& x : p) cin >> x;
	for (auto& x : u) cin >> x;
	auto solve = [&](ld x, ld y) {
		tuple<ld, int, int> res{ 0, 0, 0 };
		for (int i = 0; i < n; i++) {
			auto a = res, b = res, c = res;
			get<0>(a) += p[i] + x;
			get<1>(a)++;
			get<0>(b) += u[i] + y;
			get<2>(b)++;
			get<0>(c) += p[i] + u[i] - p[i] * u[i] + x + y;
			get<1>(c)++;
			get<2>(c)++;
			res = max({ res, a, b, c });
		}
		return res;
	};
	auto solve1 = [&](ld x) {
		ld lf = -1, rg = 1;
		for (int i = 0; i < 25; i++) {
			ld md = (lf + rg) / 2;
			if (get<2>(solve(x, md)) <= b) lf = md;
			else rg = md;
		}
		auto res = solve(x, lf);
		return make_pair(get<0>(res) - lf * b, get<1>(res));
	};
	ld lf = -1, rg = 1;
	for (int i = 0; i < 25; i++) {
		ld md = (lf + rg) / 2;
		if (solve1(md).second <= a) lf = md;
		else rg = md;
	}
	auto res = solve1(lf);
	cout << setprecision(10) << fixed << res.first - lf * a;
}