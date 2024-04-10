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

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int q;
	cin >> q;
	while (q--) {
		int n, m;
		cin >> n >> m;
		pii base = { m, m };
		int ct = 0;
		bool ok = true;
		for (int i = 0; i < n; i++) {
			int t, l, h;
			cin >> t >> l >> h;
			base.first -= (t - ct);
			base.second += (t - ct);
			ct = t;
			base.first = max(base.first, l);
			base.second = min(base.second, h);
			if (base.first > base.second) {
				ok = false;
			}
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
}