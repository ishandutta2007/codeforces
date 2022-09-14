/*AMETHYSTS*/
//#pragma comment(linker, "/STACK:1000000000")
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
#define pll pair <ll, ll>
#define mp make_pair

using namespace std;

const int maxn = (int)1e5 + 10;
int v[maxn];

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	for (int i = 0; i < n - 1; i++) {
		v[i] = abs(v[i] - v[i + 1]);
	}

	n--;

	ll now = 0;
	ll ans = 0;

	for (int i = 0; i < n; i += 2) {
		now = max(now, (ll)v[i]);

		ans = max(ans, now);

		now += -v[i + 1] + v[i + 2];
	}

	now = 0;

	for (int i = 1; i < n; i += 2) {
		now = max(now, (ll)v[i]);

		ans = max(ans, now);

		now += -v[i + 1] + v[i + 2];
	}

	cout << ans << endl;

	return 0;
}