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
#include <unordered_map>
#include <random>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int mod = (int)1e9 + 7;

ll x = 128371;
ll b = 12873189;
ll a = 1283719;

ll rnd() {
	return x = (a * x + b) % mod;
}

int main() {
	int n, s, x;

	cin >> n >> s >> x;

	int now = s;
	int lastx = -1;

	int cnt = 1000;

	for (int i = 0; i < 1000; i++) {
		int ps = rnd() % n + 1;

		cout << "? " << ps << endl;

		int y, nx;

		cin >> y >> nx;

		if (y < x && lastx < y) {
			now = ps;
			lastx = y;
		}
	}

	int ans = -1;

	while (true) {
		cnt++;
		if (cnt == 2001) {
			throw 1;
		}
		cout << "? " << now << endl;

		int y, nx;

		cin >> y >> nx;

		if (y == -1) {
			throw 1;
		}

		if (y < x) {
			if (nx == -1) {
				ans = -1;
				break;
			}

			now = nx;
		} else {
			ans = y;
			break;
		}
	}

	cout << "! " << ans << endl;

	return 0;
}