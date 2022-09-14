#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <limits.h>
#include <fstream>
#include <list>
#include <numeric>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
#define uint unsigned int
#define mp make_pair

vector<pair <pii, int> > ans;

void add(int x, int y, int w) {
	ans.push_back(mp(mp(x, y), w));
}

int solve(int l, int r) {
	if (l != 1) {
		int n = solve(1, r - l + 1);
		add(n - 1, n, l - 1);
		return n + 1;
	}

	for (int i = 2; i < 21; i++) {
		for (int j = 1; j < i; j++) {
			add(j, i, (1 << (j - 1)));
		}
	}

	for (int i = 1; i < 21; i++) {
		add(0, i, 1);
	}

	int n = 22;
	while (r > 1) {
		int x = 1;
		int st = 0;
		while (x < r) {
			x *= 2;
			st++;
		}

		x /= 2;
		st--;

		add(st + 1, n - 1, r - x);
		r -= x;
	}

	assert(r == 1);
	add(0, n - 1, 1);
	return n;
}

int main() {
	int l, r;
	cin >> l >> r;

	int n = solve(l, r);
	cout << "YES\n";
	cout << n << ' ' << ans.size() << '\n';

	for (auto f : ans) {
		cout << f.first.first + 1 << ' ' << f.first.second + 1 << ' ' << f.second << '\n';
	}
}