#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
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

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
#define uint unsigned int

const int p = (int)1e9 + 7, q = (int)1e9 + 9;

int add(int x, int y, int mod) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}
	return x;
}

int sub(int x, int y, int mod) {
	x -= y;
	if (x < 0) {
		x += mod;
	}
	return x;
}

int mul(int x, int y, int mod) {
	return (ll)x * y % mod;
}

pii operator +(pii a, pii b) {
	a.first = add(a.first, b.first, p);
	a.second = add(a.second, b.second, q);
	return a;
}

pii operator -(pii a, pii b) {
	a.first = sub(a.first, b.first, p);
	a.second = sub(a.second, b.second, q);
	return a;
}

pii operator *(pii a, pii b) {
	a.first = mul(a.first, b.first, p);
	a.second = mul(a.second, b.second, q);
	return a;
}

const int maxn = (int)1e6 + 10;

char s[maxn];
int z[2 * maxn];

int main() {
	//freopen("input.txt", "r", stdin);

	int t;

	cin >> t;

	while (t--) {
		scanf("%s", s);
		int n = 0;

		while (s[n]) {
			n++;
		}

		int l = 0;
		int r = n - 1;

		while (l < r && s[l] == s[r]) {
			l++;
			r--;
		}

		string f;

		for (int i = l; i <= r; i++) {
			f.push_back(s[i]);
			f.push_back('#');
		}

		int pos = -1;
		int best = 0;
		int res = 0;

		for (int l = -1, r = -1, i = 0; i < (int)f.size(); i++) {
			if (i <= r) {
				z[i] = min(r - i + 1, z[l + r - i]);
			}
			else {
				z[i] = 0;
			}

			while (i - z[i] >= 0 && i + z[i] < (int)f.size() && f[i - z[i]] == f[i + z[i]]) {
				z[i]++;
			}

			if (i + z[i] > r) {
				l = i - z[i] + 1;
				r = i + z[i] - 1;
			}

			if (i % 2 == 0) {
				int cur = (z[i] + 1) / 2;
				if (2 * cur - 1 > res && (i - z[i] == -1 || i + z[i] == (int)f.size())) {
					pos = i / 2;
					best = cur;
					res = 2 * cur - 1;
				}
			}
			else {
				int cur = (z[i] / 2);

				if (2 * cur > res && (i - z[i] == -1 || i + z[i] == (int)f.size())) {
					pos = i / 2;
					best = cur;
					res = 2 * cur;
				}
			}
		}

		for (int i = 0; i < l; i++) {
			printf("%c", s[i]);
		}

		if (res > 0) {
			if (pos - best == -1) {
				for (int i = l; i < l + res; i++) {
					printf("%c", s[i]);
				}
			}
			else {
				for (int i = r - res + 1; i <= r; i++) {
					printf("%c", s[i]);
				}
			}
		}

		for (int i = r + 1; i < n; i++) {
			printf("%c", s[i]);
		}

		printf("\n");
	}
}