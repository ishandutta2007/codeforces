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
//#include <random>
#include <unordered_set>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)1e5 + 10;

int d[maxn];
int x[maxn];

int main() {
	int n;

	cin >> n;

	set <pii> s;

	int sum = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &d[i], &x[i]);

		s.insert(mp(d[i], i));
		sum += d[i];
	}

	cout << sum / 2 << endl;

	while (!s.empty()) {
		int v = s.begin()->second;
		s.erase(s.begin());

		if (d[v] == 0) {
			continue;
		}

		printf("%d %d\n", v, x[v]);

		int u = x[v];

		x[u] ^= v;
		s.erase(mp(d[u], u));
		d[u]--;
		s.insert(mp(d[u], u));
	}

	return 0;
}