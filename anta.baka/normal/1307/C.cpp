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

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	int n = sz(s);
	vector<vector<ll>> cnt(26, vector<ll>(26, 0));
	vector<ll> pref(26, 0);
	for (char c : s) {
		c -= 'a';
		for (int p = 0; p < 26; p++) {
			cnt[p][c] += pref[p];
		}
		pref[c]++;
	}
	ll ans = *max_element(all(pref));
	for (int i = 0; i < 26; i++) {
		ans = max(ans, *max_element(all(cnt[i])));
	}
	cout << ans;
}