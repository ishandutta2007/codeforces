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
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<pair<string, string>> ps;
	vector<bool> pared(n, false);
	for (int i = 0; i < n; i++) {
		string t = a[i];
		reverse(all(t));
		for (int j = i + 1; j < n; j++) {
			if (!pared[j] && t == a[j]) {
				pared[i] = pared[j] = true;
				ps.pb({ a[i], a[j] });
				break;
			}
		}
	}
	string mid;
	for (int i = 0; i < n; i++) {
		if (pared[i]) continue;
		bool pal = true;
		for (int j = 0; j < m / 2; j++) {
			pal &= (a[i][j] == a[i][m - 1 - j]);
		}
		if (pal) {
			mid = a[i];
			break;
		}
	}
	cout << 2 * m * sz(ps) + sz(mid) << '\n';
	for (auto p : ps) {
		cout << p.first;
	}
	cout << mid;
	reverse(all(ps));
	for (auto p : ps) {
		cout << p.second;
	}
}