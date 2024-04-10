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
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <fstream>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <map>
#include <unordered_map>

#define ll long long
#define ld double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair

using namespace std;

const int maxn = 200;
int v[maxn][5];
int cnt[5];

ll getr(int pos, ll cn, ll n, int i) {
	if (v[i][pos] == -1) {
		return 0;
	}

	if (2 * cn > n) {
		return (ll)500 * (250 - v[i][pos]);
	}

	if (4 * cn > n) {
		return (ll)1000 * (250 - v[i][pos]);
	}

	if (8 * cn > n) {
		return (ll)1500 * (250 - v[i][pos]);
	}

	if (16 * cn > n) {
		return (ll)2000 * (250 - v[i][pos]);
	}

	if (32 * cn > n) {
		return (ll)2500 * (250 - v[i][pos]);
	}

	return (ll)3000 * (250 - v[i][pos]);
}

ll go(int pos, ll cn, ll n) {
	return getr(pos, cn, n, 0) - getr(pos, cn, n, 1);
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &v[i][j]);

			if (v[i][j] != -1) {
				cnt[j]++;
			}
		}
	}

	for (int m = 0; m <= (int)1e5 + 10; m++) {
		ll del = 0;

		for (int i = 0; i < 5; i++) {
			ll cn = cnt[i];

			ll z = go(i, cn, n + m);

			if (v[0][i] != -1) {
				z = max(z, go(i, cn + m, n + m));
			}

			del += z;
		}

		if (del > 0) {
			cout << m << endl;
			return 0;
		}
	}

	cout << -1 << endl;

	return 0;
}