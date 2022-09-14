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

const int maxn = (int)1e6 + 10;

bool p[maxn];

int main() {
	p[1] = false;
	for (int i = 2; i < maxn; i++) {
		if (!p[i]) {
			for (int j = i; (ll)i * j < maxn; j++) {
				p[i * j] = true;
			}
		}
	}

	int n;

	cin >> n;

	for (int i = 1; i <= 1000; i++) {
		if (p[n * i + 1]) {
			cout << i << endl;
			return 0;
		}
	}

	return 0;
}