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
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll

using namespace std;

int main() {
	ll x;
	char c;

	scanf("%I64d%c", &x, &c);

	x--;

	ll ans = x / 4;

	ans *= 16;

	x %= 4;

	if (x == 1 || x == 3) {
		ans += 6;
		ans++;
	}

	if (c == 'f') {
		ans++;
	} else if (c == 'e') {
		ans += 2;
	} else if (c == 'd') {
		ans += 3;
	} else if (c == 'a') {
		ans += 4;
	} else if (c == 'b') {
		ans += 5;
	} else {
		ans += 6;
	}

	cout << ans << endl;

	return 0;
}