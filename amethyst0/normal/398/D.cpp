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
//#include <unordered_map>
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

const int maxn = (int)5e5 + 10;
const int f = 620;
bool on[maxn];
int cnt[maxn];
unordered_set <int> s[maxn], all[maxn];

void change1(int x) {
	for (auto it = all[x].begin(); it != all[x].end(); it++) {
		int y = *it;

		if (on[x]) {
			cnt[y]--;
		}

		s[y].insert(x);
	}
}

void change2(int x) {
	for (auto it = all[x].begin(); it != all[x].end(); it++) {
		int y = *it;

		if (on[x]) {
			cnt[y]++;
		}

		s[y].erase(x);
	}
}

void del(int x, int y) {
	all[x].erase(y);
	all[y].erase(x);

	if (on[x] && all[x].size() <= f - 2) {
		cnt[y]--;
	}

	if (on[y] && all[y].size() <= f - 2) {
		cnt[x]--;
	}

	if (all[x].size() >= f - 1) {
		s[y].erase(x);
	}

	if (all[y].size() >= f - 1) {
		s[x].erase(y);
	}

	if (all[x].size() == f - 1) {
		change2(x);
	}

	if (all[y].size() == f - 1) {
		change2(y);
	}
}

void add(int x, int y) {
	all[x].insert(y);
	all[y].insert(x);

	if (on[x] && all[x].size() <= f) {
		cnt[y]++;
	}

	if (on[y] && all[y].size() <= f) {
		cnt[x]++;
	}

	if (all[x].size() > f) {
		s[y].insert(x);
	}

	if (all[y].size() > f) {
		s[x].insert(y);
	}

	if (all[x].size() == f) {
		change1(x);
	}

	if (all[y].size() == f) {
		change1(y);
	}
}

int main() {
	int n, m, q;

	cin >> n >> m >> q;

	int o;

	cin >> o;

	for (int i = 0; i < o; i++) {
		int x;

		scanf("%d", &x);

		on[x] = true;
	}

	for (int i = 0; i < m; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		add(x, y);
	}

	while (q--) {
		char c;
		int u;

		scanf(" %c %d", &c, &u);

		if (c == 'O') {
			on[u] = true;

			if (all[u].size() < f) {
				for (auto it = all[u].begin(); it != all[u].end(); it++) {
					int y = *it;

					cnt[y]++;
				}
			}
		} else if (c == 'F') {
			on[u] = false;

			if (all[u].size() < f) {
				for (auto it = all[u].begin(); it != all[u].end(); it++) {
					int y = *it;

					cnt[y]--;
				}
			}
		} else if (c == 'A') {
			int v;

			scanf("%d", &v);

			add(u, v);
		} else if (c == 'D') {
			int v;

			scanf("%d", &v);

			del(u, v);
		} else {
			int sum = 0;

			for (auto it = s[u].begin(); it != s[u].end(); it++) {
				int y = *it;

				sum += on[y];
			}

			printf("%d\n", sum + cnt[u]);
		}
	}

	return 0;
}