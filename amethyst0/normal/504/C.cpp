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
//#include <random>
#include <unordered_set>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)1e5 + 10;
int v[maxn];
ll ans = 0;

int check(int l, int r) {
	int lm = l;
	int rm = r + 1;

	while (lm != rm) {
		int m = (lm + rm) >> 1;

		bool st = true;

		for (int i = m + 1; i <= (l + r) / 2; i++) {
			if (v[i] != v[r + l - i]) {
				st = false;
				break;
			}
		}

		if (!st) {
			lm = m + 1;
			continue;
		}

		unordered_map <int, int> s;

		for (int i = l; i <= m; i++) {
			s[v[i]]++;
		}

		int pos = r + l - m;

		pos = max(pos, m + 1);

		for (int i = pos; i <= r; i++) {
			if (s[v[i]] == 0) {
				st = false;
				break;
			}

			s[v[i]]--;
		}

		if (!st) {
			lm = m + 1;
			continue;
		}

		int cnt = 0;

		for (auto it = s.begin(); it != s.end(); it++) {
			cnt += it->second & 1;
		}

		if (cnt > 1) {
			lm = m + 1;
		} else {
			rm = m;
		}
	}

	return r - lm + 1;
}

pii go(int l, int r) {
	if (l == r) {
		ans++;
		return mp(1, 1);
	} else if (l + 1 == r) {
		if (v[l] == v[r]) {
			ans += 3;
			return mp(2, 2);
		} else {
			return mp(0, 0);
		}
	} else {
		if (v[l] == v[r]) {
			pii f = go(l + 1, r - 1);
			ans += f.first + f.second;

			if (f.first != 0) {
				ans++;
				f.first++;
				f.second++;
			}

			return f;
		}

		int a = check(l, r);

		reverse(v + l, v + r + 1);

		int b = check(l, r);

		reverse(v + l, v + r + 1);

		ans += a + b;

		if (!(a == 0 && b == 0)) {
			ans--;
		}

		return mp(a, b);
	}
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	bool st = true;

	for (int i = 0; i < n; i++) {
		if (v[i] == v[n - 1 - i]) {

		} else {
			st = false;
		}
	}

	if (st) {
		cout << (ll)n * (n + 1) / 2 << endl;
		return 0;
	}

	go(0, n - 1);

	cout << ans << endl;

	return 0;
}