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

int ask(vector <int> a, vector <int> b) {
	cout << "? " << a.size() << ' ' << b.size() << endl;
	for (int x : a) {
		cout << x + 1 << ' ';
	}

	cout << endl;
	for (int x : b) {
		cout << x + 1 << ' ';
	}
	cout << endl;
	int f;
	cin >> f;
	return f;
}

pii go(int l, int r) {
	if (l == r) {
		return mp(-1, -1);
	}

	int m = (l + r) >> 1;
	pii a = go(l, m);
	if (a.first != -1) {
		return a;
	}
	pii b = go(m + 1, r);
	if (b.first != -1) {
		return b;
	}

	vector <int> x, y;
	for (int i = l; i <= r; i++) {
		if (i <= m) {
			x.push_back(i);
		}
		else {
			y.push_back(i);
		}
	}

	if (ask(x, y)) {
		return mp(l, r);
	}

	return mp(-1, -1);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		
		vector <int> a = { 0 };

		vector <int> ans;

		for (int i = 1; i < n; i++) {
			if (ask(a, { i })) {
				for (int j = i + 1; j < n; j++) {
					if (!ask({ i }, { j })) {
						ans.push_back(j);
					}
				}

				int l = 0;
				int r = i - 1;

				while (l != r) {
					int m = (l + r) >> 1;
					vector <int> b;

					for (int j = l; j <= m; j++) {
						b.push_back(j);
					}

					if (ask(b, { i })) {
						r = m;
					}
					else {
						l = m + 1;
					}
				}

				for (int j = 0; j < i; j++) {
					if (j != l) {
						ans.push_back(j);
					}
				}
				break;
			}

			a.push_back(i);
		}

		cout << "! " << ans.size() << ' ';
		for (int x : ans) {
			cout << x + 1 << ' ';
		}

		cout << endl;
	}
}