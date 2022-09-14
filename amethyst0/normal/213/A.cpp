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

#define ll long long
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = 210;
int c[maxn];
vector <int> ed[maxn];
bool used[maxn];

int n;

int go(int pos) {
	memset(used, 0, sizeof used);

	int cnt = 0;

	int ans = 0;

	while (cnt != n) {
		bool yes = false;

		for (int i = 0; i < n; i++) {
			if (c[i] != pos || used[i]) {
				continue;
			}
			bool fl = true;
			for (int j = 0; j < (int)ed[i].size(); j++) {
				int u = ed[i][j];

				if (!used[u]) {
					fl = false;
					break;
				}
			}

			if (fl) {
				ans++;
				cnt++;
				yes = true;
				used[i] = true;
			}
		}

		if (cnt == n) {
			break;
		}

		if (!yes) {
			ans++;
			pos++;
			if (pos == 3) {
				pos = 0;
			}
		}
	}

	return ans;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
		c[i]--;
	}

	for (int i = 0; i < n; i++) {
		int k;

		scanf("%d", &k);

		for (int j = 0; j < k; j++) {
			int x;

			scanf("%d", &x);
			x--;

			ed[i].push_back(x);
		}
	}

	int ans = (int)1e9;

	for (int i = 0; i < 3; i++) {
		ans = min(ans, go(i));
	}

	cout << ans << endl;
}