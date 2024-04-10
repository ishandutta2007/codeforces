//#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <memory.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = 25;

bool used[maxn][maxn];

int n, m;

pii nxt(int x, int y) {
	if (x == 0) {
		y++;
		if (y == m) {
			y--;
			x++;
		}
	}
	else if (x == n - 1) {
		y--;
		if (y == -1) {
			y++;
			x--;
		}
	}
	else if (y == 0) {
		x--;
		if (x == -1) {
			x++;
			y++;
		}
	}
	else if (y == m - 1) {
		x++;
		if (x == n) {
			x--;
			y--;
		}
	}
	return mp(x, y);
}

int go(int x, int y) {
	memset(used, 0, sizeof used);
	used[x][y] = 1;
	int ans = 1;

	pii cur = nxt(x, y);
	pii st = mp(x, y);
	while (cur != st) {
		bool bad = false;
		for (int dx = -1; dx <= 1; dx++) {
			for (int dy = -1; dy <= 1; dy++) {
				int nx = cur.first + dx;
				int ny = cur.second + dy;
				if (0 <= nx && nx < n && 0 <= ny && ny < m && used[nx][ny]) {
					bad = true;
				}
			}
		}

		if (!bad) {
			ans++;
			used[cur.first][cur.second] = true;
		}

		cur = nxt(cur.first, cur.second);
	}

	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		scanf("%d %d", &n, &m);

		pii cur = mp(0, 0);

		int ans = 0;

		pii best = mp(0, 0);

		while (true) {
			int res = go(cur.first, cur.second);
			ans = max(ans, res);
			if (res == ans) {
				best = cur;
			}
			cur = nxt(cur.first, cur.second);
			if (cur == mp(0, 0)) {
				break;
			}
		}

		go(best.first, best.second);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (used[i][j]) {
					printf("1");
				}
				else {
					printf("0");
				}
			}

			printf("\n");
		}
	}
}