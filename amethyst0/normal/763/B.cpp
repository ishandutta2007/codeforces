/*AMETHYSTS*/
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
#include <unordered_set>
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
	int n;

	cin >> n;

	cout << "YES" << endl;

	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;

		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		int a = x1 % 2;
		if (a < 0) {
			a += 2;
		}

		int b = y1 % 2;

		if (b < 0) {
			b += 2;
		}

		printf("%d\n", a + b * 2 + 1);
	}

	return 0;
}