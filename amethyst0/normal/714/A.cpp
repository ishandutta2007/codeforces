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
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (ll)n; i++)
#define mp make_pair
#define ui unsigned ll

using namespace std;

int main() {
	ll a, b, k, c, d;

	cin >> a >> b >> c >> d >> k;

	ll l = max(a, c);
	ll r = min(b, d);

	if (l > r) {
		cout << 0 << endl;
		return 0;
	}

	if (l <= k && k <= r && a <= k && k <= b) {
		cout << r - l << endl;
	} else {
		cout << r - l + 1 << endl;
	}

	return 0;
}