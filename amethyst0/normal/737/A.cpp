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
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)2e5 + 10;

pii v[maxn];
int pos[maxn];
int n, k, s, t;

bool check(int sp) {
	int now = 0;

	ll tm = 0;

	for (int i = 0; i < k; i++) {
		int x = pos[i] - now;

		int b = sp - x;

		int a = 0;

		if (sp < x) {
			return false;
		}

		if (b < 0) {
			b = 0;
			a = x;
		} else if (b > x) {
			b = x;
		} else {
			a = x - b;
		}

		tm += 2 * a + b;

		now = pos[i];
	}

	return tm <= t;
}

int main() {
	cin >> n >> k >> s >> t;

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &v[i].second, &v[i].first);
	}

	sort(v, v + n);

	for (int i = 0; i < k; i++) {
		scanf("%d", &pos[i]);
	}

	sort(pos, pos + k);

	pos[k] = s;
	k++;

	int l = 0;
	int r = n;

	while (l != r) {
		int m = (l + r) / 2;

		if (check(v[m].first)) {
			r = m;
		} else {
			l = m + 1;
		}
	}

	if (l == n) {
		cout << -1 << endl;
		return 0;
	}

	int ans = v[l].second;

	for (int i = l + 1; i < n; i++) {
		ans = min(ans, v[i].second);
	}

	cout << ans << endl;

	return 0;
}