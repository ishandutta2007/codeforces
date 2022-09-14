#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <fstream>
#include <bitset>
#include <limits.h>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>
#define uint int

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int maxn = 2001;

const int mag = 30;

int ed[2][maxn][maxn / mag + 1];

int n;

void change(int tp, int a, int b) {
	ed[tp][a][b / mag] ^= (1 << (b % mag));
}

void flip(int v) {
	for (int i = 0; i < n; i++) {
		if (v == i) {
			continue;
		}

		for (int j = 0; j < 2; j++) {
			change(j, i, v);
			change(j, v, i);
		}
	}
}

int used[maxn / mag + 1];
int fir[1 << 16];

void clear() {
	for (int i = 0; i < maxn / mag + 1; i++) {
		used[i] = (1 << mag) - 1;
	}
}

int gg = (1 << 16) - 1;

int ctz(int mask) {
	if (mask & gg) {
		return fir[mask & gg];
	}

	return 16 + fir[mask >> 16];
}

int dfs(int tp, int v) {
	used[v / mag] ^= (1 << (v % mag));
	int ans = 1;

	for (int i = 0; i <= n / mag; i++) {
		int mask = used[i] & ed[tp][v][i];
		if (mask == 0) {
			continue;
		}

		int u = i * mag + ctz(mask);

		ans += dfs(tp, u);
		i--;
	}

	return ans;
}

bool check() {
	clear();
	if (dfs(0, 0) == n) {
		clear();
		if (dfs(1, 0) == n) {
			return true;
		}
	}

	return false;
}

int ans, cnt = 0;

void build(int pos, int num) {
	if (num > ans) {
		return;
	}

	if (pos == n) {
		if (check()) {
			if (ans > num) {
				ans = num;
				cnt = 1;
			}
			else {
				cnt++;
			}
		}
	}
	else {
		build(pos + 1, num);
		flip(pos);
		build(pos + 1, num + 1);
		flip(pos);
	}
}

int main() {
	for (int i = 1; i < (1 << 16); i++) {
		if (i & 1) {
			fir[i] = 0;
		}
		else {
			fir[i] = fir[i >> 1] + 1;
		}
	}

	cin >> n;

	for (int i = 0; i < n; i++) {
		char c;

		for (int j = 0; j < n; j++) {
			scanf(" %c", &c);
			if (i != j) {
				if (c == '1') {
					change(0, i, j);
				}
				else {
					change(1, i, j);
				}
			}
		}
	}

	if (check()) {
		cout << "0 1\n";
		return 0;
	}

	ans = n;

	if (n <= 6) {
		build(0, 0);
		if (ans == n) {
			cout << -1 << '\n';
			return 0;
		}

		for (int i = 1; i <= ans; i++) {
			cnt *= i;
		}

		cout << ans << ' ' << cnt << '\n';
		return 0;
	}

	ans = 1;
	cnt = 0;

	for (int i = 0; i < n; i++) {
		flip(i);
		if (check()) {
			cnt++;
		}
		flip(i);
	}

	cout << ans << ' ' << cnt << '\n';
}