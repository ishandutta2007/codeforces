#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <iostream>
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

const int inf = 1e9;

int gcd(int a, int b) {
	return (b ? gcd(b, a % b) : a);
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<string> a(n), b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	int lcm = n * m / gcd(n, m);
	vector<string> c(lcm);
	int i1 = 0, j1 = 0;
	for (int i = 0; i < lcm; i++) {
		c[i] = a[i1] + b[j1];
		i1 = (i1 + 1) % n;
		j1 = (j1 + 1) % m;
	}
	int q;
	cin >> q;
	while (q--) {
		int y;
		cin >> y;
		y--;
		y %= lcm;
		cout << c[y] << '\n';
	}
}