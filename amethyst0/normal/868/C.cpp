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

int cnt[1 << 4];
int o = 0;
int num[4];

void check() {
	if (o == 0) {
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (2 * num[i] > o) {
			return;
		}
	}

	cout << "YES\n";
	exit(0);
}

void build(int pos) {
	if (pos == 16) {
		check();
	} else {
		build(pos + 1);

		if (cnt[pos] != 0) {
			for (int i = 0; i < 4; i++) {
				int x = (pos >> i) & 1;

				if (x) {
					num[x]++;
				}
			}

			o++;

			build(pos + 1);

			o--;

			for (int i = 0; i < 4; i++) {
				int x = (pos >> i) & 1;

				if (x) {
					num[x]--;
				}
			}
		}
	}
}

int main() {
	int n, k;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int now = 0;

		for (int j = 0; j < k; j++) {
			now <<= 1;
			int x;

			scanf("%d", &x);

			now += x;
		}

		cnt[now]++;
	}

	k = 4;

	if (cnt[0] != 0) {
		cout << "YES\n";
		return 0;
	}

	for (int i = 0; i < (1 << k); i++) {
		for (int j = 0; j < (1 << k); j++) {
			if (cnt[i] != 0 && cnt[j] != 0 && (i & j) == 0) {
				cout << "YES\n";
				return 0;
			}
		}
	}

	build(0);

	cout << "NO\n";

	return 0;
}