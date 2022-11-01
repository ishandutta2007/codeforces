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
		int n, d;
		cin >> n >> d;
		vi a(n);
		for (int& x : a) cin >> x;
		for (int i = 1; i < n && d > 0; i++) {
			if (d >= i * a[i]) {
				d -= i * a[i];
				a[0] += a[i];
			}
			else {
				int c = d / i;
				a[0] += c;
				d = 0;
			}
		}
		cout << a[0] << '\n';
	}
}