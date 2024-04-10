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

using namespace std;

const int maxn = (int)5e5 + 10;
int dx[4] = {-1, 1, -1, 1};
int dy[4] = {-1, -1, 1, 1};
int n, m;

int get_dst(int x, int y, int it) {
	int ans = (int)1e9;
	if (dx[it] == 1) {
		ans = min(ans, n - x);
	} else {
		ans = min(ans, x);
	}

	if (dy[it] == 1) {
		ans = min(ans, m - y);
	} else {
		ans = min(ans, y);
	}

	return ans;
}

int change(int x, int y, int it) {
	if (x == 0 && y == 0) {
		return -1;
	}

	if (x == n && y == m) {
		return -1;
	}

	if (x == 0 && y == m) {
		return -1;
	}

	if (x == n && y == 0) {
		return -1;
	}

	if (x == 0 || x == n) {
		return it ^ 1;
	}

	return it ^ 2;
}

vector <int> a[maxn], b[maxn];
int xx[maxn], yy[maxn];
ll ans[maxn];

int main() {
	cin >> n >> m;
	int k;

	cin >> k;

	for (int i = 0; i < k; i++) {
		int x, y;
		scanf("%d %d", &x, &y);

		a[x - y + m].push_back(i);
		b[x + y].push_back(i);
		xx[i] = x;
		yy[i] = y;
	}

	int x = 0;
	int y = 0;
	int it = 3;
	ll dst = 0;

	memset(ans, -1, sizeof ans);

	while (it != -1) {
		//cout << x << ' ' << y << ' ' << dx[it] << ' ' << dy[it] << endl;
		if (dx[it] == dy[it]) {
			int num = x - y + m;

			for (int i = 0; i < (int)a[num].size(); i++) {
				int pos = a[num][i];

				if (ans[pos] == -1) {
					ans[pos] = dst + abs(xx[pos] - x);
				}
			}
		} else {
			int num = x + y;

			for (int i = 0; i < (int)b[num].size(); i++) {
				int pos = b[num][i];

				if (ans[pos] == -1) {
					ans[pos] = dst + abs(xx[pos] - x);
				}
			}
		}

		int now = get_dst(x, y, it);
		dst += now;
		x += dx[it] * now;
		y += dy[it] * now;
		it = change(x, y, it);
	}

	for (int i = 0; i < k; i++) {
		printf("%I64d\n", ans[i]);
	}

	return 0;
}