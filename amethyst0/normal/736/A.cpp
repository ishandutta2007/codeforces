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

ll f[maxn];

int main() {
	ll n;

	cin >> n;
	
	f[1] = 2;
	f[2] = 3;

	if (n == 2) {
		cout << 1 << endl;
		return 0;
	}

	for (int i = 3; i < maxn; i++) {
		f[i] = f[i - 1] + f[i - 2];
		
		if (f[i] > n) {
			cout << i - 1 << endl;
			return 0;
		}
	}

	return 0;
}