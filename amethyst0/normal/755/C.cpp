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

const int maxn = (int)1e4 + 10;

int v[maxn];
int p[maxn];

int getp(int x) {
	if (p[x] == x) {
		return x;
	}

	return p[x] = getp(p[x]);
}

int main() {
	int n;

	cin >> n;

	int ans = n;

	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);

		int x = getp(i);
		int y = getp(v[i]);

		if (p[x] != y) {
			ans--;
			p[x] = y;
		}
	}

	cout << ans << endl;

	return 0;
}