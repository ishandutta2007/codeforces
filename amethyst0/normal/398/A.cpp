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
//#include <unordered_map>
//#include <random>
//#include <unordered_set>

#define ll long long
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)1e5 + 10;

int main() {
	ll a, b;

	cin >> a >> b;

	if (b == 0) {
		cout << a * a << endl;

		for (int i = 0; i < a; i++) {
			printf("o");
		}

		return 0;
	}

	if (a == 0) {
		cout << -b * b << endl;

		for (int i = 0; i < b; i++) {
			printf("x");
		}

		return 0;
	}

	ll ans = -(ll)1e18;
	int cnt = 0;

	for (int i = 2; i <= a + b; i++) {
		int cnta = i / 2;
		int cntb = i - cnta;

		if (cnta > a || cntb > b) {
			break;
		}

		ll now = (cnta - 1) + (a - cnta + 1) * (a - cnta + 1);
		now -= (b % cntb) * (b / cntb + 1) * (b / cntb + 1) + (cntb - b % cntb) * (b / cntb) * (b / cntb);

		if (now > ans) {
			ans = now;
			cnt = i;
		}
	}

	cout << ans << endl;

	int cnta = cnt / 2;
	int cntb = cnt - cnta;

	int o = b % cntb;
	ll num = a - cnta;

	for (int i = 0; i < cnt; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < b / cntb; j++) {
				printf("x");
			}

			if (o != 0) {
				printf("x");
				o--;
			}
		} else {
			printf("o");

			cnta--;

			if (cnta == 0) {
				for (ll j = 0; j < num; j++) {
					printf("o");
				}
			}
		}
	}

	return 0;
}