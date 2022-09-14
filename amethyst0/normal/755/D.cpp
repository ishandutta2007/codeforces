/*AMETHYSTS*/
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
#include <unordered_set>
#include <random>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

int main() {
	int n, k;

	cin >> n >> k;

	if (k > n / 2) {
		k = n - k;
	}

	ll ans = 1;
	ll sum = 1;
	int pos = 1;

	for (int i = 1; i <= n; i++) {
		int x = pos + k;

		if (x <= n) {
			ans += sum;
		} else {
			ans += sum + 1;
			sum += 2;
			x -= n;
		}

		pos = x;

		if (i == n) {
			ans--;
		}

		printf("%I64d ", ans);
	}

	return 0;
}