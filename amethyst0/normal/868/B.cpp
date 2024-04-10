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
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

bool ed[12];

bool us[12];

void dfs(int t) {
	if (us[t]) {
		return;
	}

	us[t] = true;

	if (!ed[t]) {
		int x = t + 1;

		if (x == 12) {
			x = 0;
		}

		dfs(x);
	}

	int x = t - 1;

	if (x < 0) {
		x = 11;
	}

	if (!ed[x]) {
		dfs(x);
	}
}

int main() {
	int h, m, s, t1, t2;

	cin >> h >> m >> s >> t1 >> t2;

	if (h == 12) {
		h = 0;
	}

	if (t1 == 12) {
		t1 = 0;
	}

	if (t2 == 12) {
		t2 = 0;
	}

	ed[h] = true;

	if (s == 0 && m == 0) {
		if (h != 0) {
			ed[h - 1] = true;
		} else {
			ed[11] = true;
		}
	}

	int p = m / 5;

	ed[p] = true;

	if (s == 0) {
		if (m % 5 == 0) {
			int x = p - 1;

			if (x < 0) {
				x = 11;
			}

			ed[x] = true;
		}
	}

	p = s / 5;

	ed[p] = true;

	if (s % 5 == 0) {
		int x = p - 1;

		if (x < 0) {
			x = 11;
		}

		ed[x] = true;
	}

	dfs(t1);

	if (us[t2] ){
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

	return 0;
}