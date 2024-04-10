#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <ctime>

#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>
#define ld long double

using namespace std;

int color(int x, int y) {
	cout << x << ' ' << y << endl;
	string s;

	cin >> s;

	if (s[0] == 'w') {
		return 0;
	}

	return 1;
}

int main() {
	int n;

	cin >> n;

	int l = 0, r = (int)1e9 + 1;

	int cl = color(0, 1);

	for (int i = 2; i <= n; i++) {
		int m = (l + r) >> 1;

		if (m == l) {
			throw 1;
		}

		int cur = color(m, 1);

		if (cur == cl) {
			l = m;
		}
		else {
			r = m;
		}
	}

	cout << l << ' ' << 0 << ' ' << l + 1 << ' ' << 2 << endl;

	//system("pause");
}