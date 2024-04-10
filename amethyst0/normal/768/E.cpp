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
#define mp make_pair

using namespace std;

const int maxn = 70;

map <pair <int, ll>, int> dp;

int go(int x, ll mask) {
	if (mask < 0) {
		throw 1;
	}

	mask &= ((ll)1 << x) - 1;

	auto it = dp.find(mp(x, mask));

	if (it != dp.end()) {
		return it->second;
	}

	int z[maxn];
	memset(z, 0, sizeof z);

	for (int i = 0; i < x; i++) {
		int j = i + 1;
		if (!(mask >> (ll)i)) {
			z[go(x - j, mask ^ ((ll)1 << i))]++;
		}
	}

	for (int i = 0; i < maxn; i++) {
		if (z[i] == 0) {
			return dp[mp(x, mask)] = i;
		}
	}

	throw 1;
}

int main() {
	int n;

	cin >> n;

	int ans = 0;

	for (int i = 0; i < n; i++) {
		int x;

		scanf("%d", &x);

		ans ^= go(x, 0);
	}

	if (ans == 0) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}