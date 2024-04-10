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

int main() {
	int n;

	cin >> n;

	int l = -(int)1e9;
	int r = (int)1e9;
	int mid = 1900;

	for (int i = 0; i < n; i++) {
		int c, d;

		scanf("%d %d", &c, &d);

		if (d == 1) {
			l = max(l, mid);
		} else {
			r = min(r, mid - 1);
		}

		l += c;
		r += c;
	}

	if (l > r) {
		printf("Impossible");
	} else if (r >= (int)1e8) {
		printf("Infinity");
	} else {
		printf("%d\n", r);
	}

	return 0;
}