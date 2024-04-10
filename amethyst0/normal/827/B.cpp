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
#define uint unsigned int
#define pb push_back
#define sz(a) (int)(a.size())

using namespace std;

const int maxn = (int)2e5 + 10;

int main() {
	int n, k;

	cin >> n >> k;

	int l = 1;

	int r = n;

	while (l != r) {
		int m = (l + r) >> 1;

		ll ans = 0;

		if (m & 1) {
			ans = (m / 2) + (ll)(k - 1) * (m / 2 - 1) + 1;
		} else {
			ans = (ll)(m / 2 - 1) * k + 1;
		}

		if (ans >= n - k) {
			r = m;
		} else {
			l = m + 1;
		}
	}

	int pos = k + 1;

	int d = (l + 1) / 2;

	int rot = pos;

	printf("%d\n", l);

	while (d != 0) {
		printf("%d %d\n", pos - 1, pos);
		d--;
		pos++;
		rot = pos - 1;
	}

	for (int i = k - 1; i >= 1; i--) {
		int d = l / 2;

		int last = i;

		while (d != 1 && pos != n + 1) {
			printf("%d %d\n", last, pos);
			last = pos++;
			d--;
		}

		printf("%d %d\n", last, rot);
	}

	return 0;
}