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

const int maxn = (int)1e5 + 10;

char s[10];

int solve(int l, int r, int md) {
	while (l != r) {
		if (md == 0) {
			int m = ((l + r + 1) >> 1) - 1;
			cout << "1 " << m << ' ' << m + 1 << endl;
			cout.flush();

			scanf("%s", s);

			if (s[0] == 'T') {
				r = m;
			} else {
				l = m + 1;
			}
		} else {
			int m = (l + r) >> 1;
			cout << "1 " << m + 1 << ' ' << m << endl;
			cout.flush();

			scanf("%s", s);

			if (s[0] == 'T') {
				l = m + 1;
			} else {
				r = m;
			}
		}
	}

	return l;
}


int main() {
	int n, k;

	cin >> n >> k;

	int x = solve(1, n, 0);

	int y = solve(x, n, 1);

	if (y == x) {
		y = solve(1, x, 0);
	}

	cout << "2 " << x << ' ' << y << endl;
	cout.flush();

	return 0;
}