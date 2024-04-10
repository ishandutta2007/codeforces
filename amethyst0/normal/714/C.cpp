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

map <ll, int> s;
int res[20];

ll make(ll x) {
	for (int i = 0; i < 18; i++) {
		res[i] = x % 10;
		res[i] &= 1;
		x /= 10;
	}

	ll y = 0;

	for (int i = 17; i >= 0; i--) {
		y *= 10;
		y += res[i];
	}

	return y;
}

int main() {
	int t;

	scanf("%d", &t);

	while (t--) {
		char c;

		scanf(" %c", &c);

		ll x;

		scanf("%I64d", &x);

		if (c == '?') {
			if (s.count(x)) {
				printf("%d\n", s[x]);
			} else {
				printf("0\n");
			}
		} else if (c == '+') {
			x = make(x);
			s[x]++;
		} else {
			x = make(x);
			s[x]--;
		}
	}

	return 0;
}