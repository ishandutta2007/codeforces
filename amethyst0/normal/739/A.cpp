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
#include <unordered_set>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

int main() {
	int n, m;

	cin >> n >> m;

	int d = n;

	for (int i = 0; i < m; i++) {
		int l, r;

		scanf("%d %d", &l, &r);

		d = min(d, r - l + 1);
	}

	printf("%d\n", d);

	for (int i = 0; i < n; i++) {
		printf("%d ", i % d);
	}

	return 0;
}