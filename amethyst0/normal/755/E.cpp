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
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

int main() {
	int n, k;

	cin >> n >> k;

	if (n < 4) {
		cout << -1 << endl;
		return 0;
	}

	if (k == 1 || k > 3) {
		cout << -1 << endl;
		return 0;
	}

	if (k == 3) {
		cout << n - 2 + n - 3 << endl;

		for (int i = 3; i <= n; i++) {
			cout << 1 << ' ' << i << endl;
		}

		for (int i = 4; i <= n; i++) {
			cout << 2 << ' ' << i << endl;
		}

		return 0;
	}

	if (n == 4) {
		cout << -1 << endl;
		return 0;
	}

	cout << n - 1 << endl;

	for (int i = 1; i < n; i++) {
		cout << i << ' ' << i + 1 << endl;
	}

	return 0;
}