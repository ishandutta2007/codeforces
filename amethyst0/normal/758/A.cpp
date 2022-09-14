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

int v[1000];

int main() {
	int n;

	cin >> n;

	ll ans = 0;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v, v + n);

	for (int i = 0; i < n - 1; i++) {
		ans += v[n - 1] - v[i];
	}

	cout << ans << endl;

	return 0;
}