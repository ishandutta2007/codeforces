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
	int z;
	cin >> z;
	while (z--) {
		int n, x;
		cin >> n >> x;
		vi a(n);
		for (int& x : a) cin >> x;
		int y = *max_element(all(a));
		int cnt = x / y;
		if (cnt >= 1) {
			cout << (x + y - 1) / y << '\n';
		}
		else {
			bool one = false;
			for (int y : a) {
				if (x == y) {
					one = true;
				}
			}
			cout << (one ? 1 : 2) << '\n';
		}
	}
}