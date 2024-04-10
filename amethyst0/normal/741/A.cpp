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

const int maxn = (int)1e5 + 10;
int v[maxn];

ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

int getd(int x, int y) {
	if (v[x] == y) {
		return 1;
	}

	return getd(v[x], y) + 1;
}

int main() {
	int n;

	cin >> n;

	set <int> s;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);

		s.insert(v[i]);
	}

	if (s.size() != n) {
		cout << -1 << endl;
		return 0;
	}

	ll ans = 1;

	for (int i = 0; i < n; i++) {
		int d = getd(i, i);

		if (d % 2 == 0) {
			d /= 2;
		}

		ans = lcm(ans, d);
	}

	cout << ans << endl;

	return 0;
}