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

#define ll long long
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)1e6 + 10;
bool used[maxn];

int main() {
	int n;

	cin >> n;

	int y = 0;

	for (int i = 0; i < n; i++) {
		int x;

		scanf("%d", &x);

		used[x] = true;
	}

	int z = 25 - n;

	int pos = 1;

	while (z > 0) {
		while (used[pos]) {
			pos++;
		}

		used[pos] = true;
		z--;
	}

	int ans = 0;

	for (int i = 0; i < maxn; i++) {
		if (used[i]) {
			ans = i;
		}
	}

	cout << ans - 25 << endl;

	return 0;
}