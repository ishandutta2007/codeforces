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

struct Line {
	ld k, b;
};

ld isec(Line& a, Line& b) {
	return (b.b - a.b) / (a.k - b.k);
}

deque<Line> h;

void add(Line l) {
	while (sz(h) > 1 && isec(l, h[0]) > isec(h[0], h[1])) {
		h.pop_front();
	}
	h.push_front(l);
}

const ld eps = 1e-8;

bool eq(ld a, ld b) {
	return abs(a - b) < eps;
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n; vector<ld> a(n), p(n);
	for (int i = 0; i < n; i++) {
		int x; cin >> x; a[i] = x; p[i] = (i > 0 ? p[i - 1] : 0) + a[i];
	}
	vector<ld> kek(n);
	kek.back() = a.back();
	add({ (ld)-(n - 1), p[n - 1] });
	for (int i = n - 1; i >= 0; i--) {
		add({ (ld)-(i - 1), i > 0 ? p[i - 1] : (ld)0 });
		if (i < n - 1) {
			assert(sz(h) > 1);
			kek[i] = isec(h[0], h[1]);
		}
	}
	cout.precision(10);
	cout << fixed;
	for (int i = 0; i < n; i++) {
		ld opt = kek[i];
		ld sum = a[i];
		int j = i;
		cout << opt << ' ';
		while (!eq(sum, opt * (j - i + 1))) {
			cout << opt << ' ';
			j++;
			sum += a[j];
		}
		i = j;
	}
}