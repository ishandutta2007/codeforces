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

const int maxn = (int)1e5 + 10;

ll golen(ll x) {
	if (x == 1 || x == 0) {
		return 1;
	}

	return 1 + 2 * golen(x / 2);
}

ll gocnt(ll x) {
	if (x == 1) {
		return 1;
	}

	if (x == 0) {
		return 0;
	}

	return (x & 1) + 2 * gocnt(x / 2);
}

ll go(ll n, ll l, ll r) {
	if (n == 1) {
		return 1;
	}

	if (n == 0) {
		return 0;
	}

	ll cnt = golen(n);

	if (cnt == r - l + 1) {
		return gocnt(n);
	}

	if (r < cnt / 2) {
		return go(n / 2, l, r);
	} else if (l > cnt / 2) {
		return go(n / 2, l - cnt / 2 - 1, r - cnt / 2 - 1);
	} else if (l == cnt / 2 && r == cnt / 2) {
		return (n & 1);
	} else if (l == cnt / 2) {
		return go(n / 2, 0, r - cnt / 2 - 1) + (n & 1);
	} else if (r == cnt / 2) {
		return go(n / 2, l, cnt / 2 - 1) + (n & 1);
	} else {
		return go(n / 2, l, cnt / 2 - 1) + (n & 1) + go(n / 2, 0, r - cnt/ 2 - 1);
	}
}

int main() {
	ll n, l, r;

	cin >> n >> l >> r;

	l--;
	r--;

	cout << go(n, l, r) << endl;

	return 0;
}