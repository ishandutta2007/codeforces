#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <map>
#include <iomanip>
#include <numeric>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <random>
#include <queue>
#include <cstring>
#include <chrono>
#include <array>
#include <cassert>

#define sz(a) (int)((a).size())
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;
using pll = pair<ll, ll>;

array<vi, 2> manacher(const string& s) {
	// in right half
	int n = sz(s);
	array<vi, 2> res;
	for (auto& v : res) {
		v.assign(n, 0);
	}
	for (int z = 0, l = 0, r = 0;
		z < 2; ++z, l = 0, r = 0) {
		for (int i = 0; i < n; ++i) {
			if (i < r) {
				res[z][i] = min(r - i + !z,
					res[z][l + r - i + !z]);
			}
			int L = i - res[z][i];
			int R = i + res[z][i] - !z;
			while (L - 1 >= 0 && R + 1 < n
				&& s[L - 1] == s[R + 1]) {
				++res[z][i];
				--L;
				++R;
			}
			if (R > r) {
				l = L;
				r = R;
			}
		}
	}
	return res;
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int n = sz(s);
		int com = 0;
		while (com < n / 2 && s[com] == s[n - 1 - com]) {
			com++;
		}
		if (2 * com + (n & 1) == n) {
			cout << s << '\n';
			continue;
		}
		auto p = manacher(s);
		pii opt = mp(0, -1);
		for (int i = 0; i < n; i++) {
			if (i - p[1][i] <= com && n - 1 - (i + p[1][i]) >= i - p[1][i]) {
				opt = max(opt, mp(2 * (i - p[1][i]) + 2 * p[1][i] + 1, i));
			}
			if (i - p[0][i] <= com && n - 1 - (i + p[0][i] - 1) >= i - p[0][i]) {
				opt = max(opt, mp(2 * (i - p[0][i]) + 2 * p[0][i], i));
			}
		}
		int i = opt.second;
		string ans;
		if (i - p[1][i] <= com && opt.first == 2 * (i - p[1][i]) + 2 * p[1][i] + 1) {
			int l = i - p[1][i];
			int r = i + p[1][i];
			string kek;
			if (l > 0) {
				kek = s.substr(0, l);
			}
			ans += kek;
			ans += s.substr(l, r - l + 1);
			reverse(all(kek));
			ans += kek;
		}
		else {
			int l = i - p[1][i];
			int r = i + p[1][i] - 1;
			string kek;
			if (l > 0) {
				kek = s.substr(0, l);
			}
			ans += kek;
			ans += s.substr(l, r - l + 1);
			reverse(all(kek));
			ans += kek;
		}
		reverse(all(s));
		p = manacher(s);
		opt = mp(0, -1);
		for (int i = 0; i < n; i++) {
			if (i - p[1][i] <= com && n - 1 - (i + p[1][i]) >= i - p[1][i]) {
				opt = max(opt, mp(2 * (i - p[1][i]) + 2 * p[1][i] + 1, i));
			}
			if (i - p[0][i] <= com && n - 1 - (i + p[0][i] - 1) >= i - p[0][i]) {
				opt = max(opt, mp(2 * (i - p[0][i]) + 2 * p[0][i], i));
			}
		}
		i = opt.second;
		string ans1;
		if (i - p[1][i] <= com && opt.first == 2 * (i - p[1][i]) + 2 * p[1][i] + 1) {
			int l = i - p[1][i];
			int r = i + p[1][i];
			string kek;
			if (l > 0) {
				kek = s.substr(0, l);
			}
			ans1 += kek;
			ans1 += s.substr(l, r - l + 1);
			reverse(all(kek));
			ans1 += kek;
		}
		else {
			int l = i - p[1][i];
			int r = i + p[1][i] - 1;
			string kek;
			if (l > 0) {
				kek = s.substr(0, l);
			}
			ans1 += kek;
			ans1 += s.substr(l, r - l + 1);
			reverse(all(kek));
			ans1 += kek;
		}
		cout << (sz(ans) > sz(ans1) ? ans : ans1) << '\n';
	}
}