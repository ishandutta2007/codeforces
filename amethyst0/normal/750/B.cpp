/*AMETHYSTS*/
//#pragma comment(linker, "/STACK:1000000000")
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
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

int x, y;
const int mod = 40000;

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int t;

		string s;

		cin >> t >> s;

		int dx = 0;
		int dy = 0;

		if (s[0] == 'S') {
			dx = 1;
		} else if (s[0] == 'N') {
			dx = -1;
		} else if (s[0] == 'W') {
			dy = 1;
		} else {
			dy = -1;
		}

		for (int j = 0; j < t; j++) {
			if (x == 0 && s[0] != 'S') {
				printf("NO\n");
				return 0;
			}

			if (x == mod / 2 && s[0] != 'N') {
				printf("NO\n");
				return 0;
			}

			x += dx;
			y += dy;

			if (x < 0) {
				x += mod;
			} else if (x >= mod) {
				x -= mod;
			}

			if (y < 0) {
				y += mod;
			} else if (y >= mod) {
				y -= mod;
			}
		}
	}

	if (x == 0) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}

	return 0;
}