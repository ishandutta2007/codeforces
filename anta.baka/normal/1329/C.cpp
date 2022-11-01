#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <random>
#include <queue>
#include <numeric>
#include <ctime>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#include <iomanip>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;

const int N = 1 << 21;

int h, g, n, m;
int a[N];
int wh[N];
vi guys;
vi ans;
vi path;

bool can(int v) {
	path.pb(v);
	if (a[v << 1] == 0 && a[v << 1 | 1] == 0) {
		return (v >= m);
	}
	if (a[v << 1] > a[v << 1 | 1]) {
		return can(v << 1);
	}
	return can(v << 1 | 1);
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	guys.reserve(N >> 1);
	ans.reserve(N >> 1);
	path.reserve(21);
	while (T--) {
		int h, g;
		cin >> h >> g;
		n = (1 << h);
		m = (1 << g);
		guys.clear();
		memset(a, 0, 4 * (n << 1));
		ll sum = 0;
		for (int i = 1; i < n; i++) {
			cin >> a[i];
			wh[a[i]] = i;
			guys.pb(a[i]);
			sum += a[i];
		}
		sort(all(guys), greater<int>());
		int rem = n - m;
		for (auto val : guys) {
			if (!rem) break;
			int u = wh[val];
			path.clear();
			if (!can(u)) {
				continue;
			}
			rem--;
			for(int i = 1; i < sz(path); i++) {
				wh[a[path[i]]] = path[i - 1];
				a[path[i - 1]] = a[path[i]];
			}
			sum -= val;
			ans.pb(u);
			a[path.back()] = 0;
		}
		cout << sum << '\n';
		for (auto v : ans) {
			cout << v << ' ';
		}
		cout << '\n';
		for (int i = 1; i < n; i++) {
			wh[a[i]] = 0;
		}
		ans.clear();
	}
}