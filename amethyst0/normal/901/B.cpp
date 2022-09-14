/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ull unsigned ll
#define pll pair <ll, ll>

using namespace std;

int main() {
	int n;

	cin >> n;

	vector <int> a, b;

	a.push_back(0);
	a.push_back(1);
	b.push_back(1);

	while (b.size() != n) {
		vector <int> c;
		c.push_back(0);

		for (int i = 0; i < (int)a.size(); i++) {
			c.push_back(a[i]);
		}

		bool fl = true;

		for (int i = 0; i < (int)b.size(); i++) {
			if (-1 <= c[i] + b[i] && c[i] + b[i] <= 1) {

			}
			else {
				fl = false;
				break;
			}
		}

		if (!fl) {
			fl = true;

			for (int i = 0; i < (int)b.size(); i++) {
				if (-1 <= c[i] - b[i] && c[i] - b[i] <= 1) {

				}
				else {
					fl = false;
					break;
				}
			}

			if (!fl) {
				cout << b.size() << endl;
				return 0;
			}

			for (int i = 0; i < (int)b.size(); i++) {
				c[i] -= b[i];
			}
		}
		else {
			for (int i = 0; i < (int)b.size(); i++) {
				c[i] += b[i];
			}
		}

		b = a;
		a = c;
	}

	if (a.back() < 0) {
		for (int i = 0; i < (int)a.size(); i++) {
			a[i] *= -1;
		}
	}

	if (b.back() < 0) {
		for (int i = 0; i < (int)b.size(); i++) {
			b[i] *= -1;
		}
	}

	cout << (int)a.size() - 1 << endl;

	for (int i = 0; i < (int)a.size(); i++) {
		cout << a[i] << ' ';
	}

	cout << endl;
	cout << (int)b.size() - 1 << endl;

	for (int i = 0; i < (int)b.size(); i++) {
		cout << b[i] << ' ';
	}

	return 0;
}