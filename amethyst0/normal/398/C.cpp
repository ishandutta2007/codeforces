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

vector <pii> ed[6];
int sum[6];

void change(int l, int r, int w) {
	if (l > r) {
		swap(l, r);
	}

	for (int i = l; i <= r; i++) {
		sum[i] += w;
	}
}

int dfs(int x, int p, int y) {
	if (x == y) {
		return 0;
	}

	for (int i = 0; i < (int)ed[x].size(); i++) {
		int u = ed[x][i].first;

		if (u == p) {
			continue;
		}

		int now = dfs(u, x, y);

		if (now != -1) {
			now += ed[x][i].second;
			return now;
		}
	}

	return -1;
}

vector <pii> ans;

bool gen() {
	ans.clear();
	int n = 5;

	int f[5];

	for (int i = 0; i < 5; i++) {
		f[i] = i + 1;
		ed[i + 1].clear();
	}

	random_shuffle(f, f + n);
	memset(sum, 0, sizeof sum);

	for (int i = 1; i < 5; i++) {
		int x = rand() % i;
		int w = rand() % 4 + 1;

		ed[f[i]].push_back(mp(f[x], w));
		ed[f[x]].push_back(mp(f[i], w));

		change(f[i], f[x], w);
	}

	for (int i = 1; i <= 5; i++) {
		int now = sum[i];
		for (int j = i + 1; j <= 5; j++) {
			now += sum[j];

			if (dfs(i, -1, j) == now) {
				ans.push_back(mp(i, j));
			}
		}
	}

	return ans.size() >= 2;
}

int main() {
	int n;

	cin >> n;

	if (n != 5) {
		for (int i = 1; i <= n / 2; i++) {
			printf("%d %d 1\n", i, i + n / 2);
		}

		for (int i = n / 2 + 1; i < n; i++) {
			printf("%d %d %d\n", i, i + 1, 2 * (i - n / 2) - 1);
		}

		for (int i = 1; i < n / 2; i++) {
			printf("%d %d\n", i, i + 1);
		}

		printf("1 3\n");
	} else {
		while (!gen()) {
			//cout << ans.size() << endl;
		}

		for (int i = 1; i <= 5; i++) {
			for (int j = 0; j < (int)ed[i].size(); j++) {
				if (ed[i][j].first < i) {
					cout << ed[i][j].first << ' ' << i << ' ' << ed[i][j].second << endl;
				}
			}
		}

		for (int i = 0; i < 2; i++) {
			cout << ans[i].first << ' ' << ans[i].second << endl;
		}
	}

	return 0;
}