#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <cmath>
#include <string>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define pb push_back

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	string t = s;
	reverse(all(t));
	t = s + string(1, '#') + t;
	vi p(sz(t));
	for (int i = 1; i < sz(t); i++) {
		int k = p[i - 1];
		while (k > 0 && t[i] != t[k]) {
			k = p[k - 1];
		}
		k += (t[i] == t[k]);
		p[i] = k;
	}
	int pos = p[sz(t) - 1] - 1;
	vi pal(sz(s));
	while (pos >= 0) {
		pal[pos] = 1;
		pos = p[pos] - 1;
	}
	ll ans = 1;
	pal[0] = 1;
	for (int i = 1; i < sz(s); i++) {
		if (pal[i]) {
			pal[i] += pal[(i - 1) / 2];
		}
		ans += pal[i];
	}
	cout << ans;
}