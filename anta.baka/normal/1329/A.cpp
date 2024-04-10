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

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<pii> a(m);
	ll sum = 0;
	for (int i = 0; i < m; i++) {
		cin >> a[i].first;
		sum += a[i].first;
		a[i].second = i;
	}
	if (sum < n) {
		cout << -1;
		return 0;
	}
	vector<pii> ans;
	int ff = 0;
	int ff1 = 0;
	for (auto s : a) {
		if (ff + s.first - 1 >= n) {
			cout << -1;
			return 0;
		}
		if (n - ff > sum) {
			assert(n - ff1 <= sum);
			int x = n - sum;
			assert(x >= ff);
			assert(x <= ff1);
			ans.pb(mp(s.second, x));
			ff1 = max(ff1, x + s.first);
			ff = x + 1;
		}
		else {
			ans.pb(mp(s.second, ff));
			ff1 = max(ff1, ff + s.first);
			ff++;
		}
		sum -= s.first;
	}
	sort(all(ans));
	for (auto s : ans) {
		cout << s.second + 1 << ' ';
	}
}