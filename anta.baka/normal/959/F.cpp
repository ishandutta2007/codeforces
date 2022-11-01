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

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	vi a(n);
	for (int& x : a) cin >> x;
	vi ans(q);
	vector<vector<pii>> qs(n);
	for (int i = 0; i < q; i++) {
		int l, x;
		cin >> l >> x;
		qs[l - 1].pb(mp(x, i));
	}
	vi pw(n + 1, 1);
	const int mod = 1e9 + 7;
	for (int i = 1; i < n + 1; i++) pw[i] = 2 * pw[i - 1] % mod;
	vi basis(20, 0);
	int s = 0;
	for (int i = 0; i < n; i++) {
		int x = a[i];
		for (int b = 0; b < 20; b++) {
			if (!(x >> b & 1)) continue;
			if (!basis[b]) {
				basis[b] = x;
				s++;
				break;
			}
			x ^= basis[b];
		}
		for (auto q : qs[i]) {
			int x = q.first;
			bool ok = true;
			for (int b = 0; b < 20; b++) {
				if (!(x >> b & 1)) continue;
				if (!basis[b]) {
					ok = false;
					break;
				}
				x ^= basis[b];
			}
			ans[q.second] = (!ok ? 0 : pw[i + 1 - s]);
		}
	}
	for (int x : ans) cout << x << '\n';
}