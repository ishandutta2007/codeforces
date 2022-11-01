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
	int n; cin >> n;
	vi a(n);
	for (int& x : a) cin >> x;
	vi pref(n), suf(n);
	pref[0] = a[0]; suf.back() = a.back();
	for (int i = 1; i < n; i++) {
		pref[i] = pref[i - 1] | a[i];
	}
	for (int i = n - 2; i >= 0; i--) {
		suf[i] = suf[i + 1] | a[i];
	}
	int mx = 0, id = 0;
	for (int i = 0; i < n; i++) {
		int rest = (i > 0 ? pref[i - 1] : 0) | (i < n - 1 ? suf[i + 1] : 0);
		int cur = (a[i] | rest) - rest;
		if (cur > mx) {
			mx = cur;
			id = i;
		}
	}
	cout << a[id] << ' ';
	for (int i = 0; i < n; i++) {
		if (i != id) {
			cout << a[i] << ' ';
		}
	}
}