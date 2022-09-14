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
#include <bitset>
#include <limits.h>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const int maxn = (int)3e5 + 10;
int p[maxn];
int ds[maxn];
int st[maxn][2];
char s[maxn];
vector <int> a[maxn];

int getp(int x) {
	if (x == p[x]) {
		return x;
	}

	int px = p[x];
	int res = getp(px);
	ds[x] ^= ds[px];
	p[x] = res;
	return res;
}

int ans = 0;

void merg(int x, int y, int tp) {
	int px = getp(x);
	int py = getp(y);

	if (px == py) {
		return;
	}

	tp ^= ds[x] ^ ds[y];

	ans -= min(st[px][0], st[px][1]);
	ans -= min(st[py][0], st[py][1]);

	if (tp == 0) {
		st[py][0] += st[px][0];
		st[py][1] += st[px][1];
	}
	else {
		st[py][0] += st[px][1];
		st[py][1] += st[px][0];
	}

	ans += min(st[py][0], st[py][1]);

	p[px] = py;
	ds[px] = tp;
}

const int inf = (int)1e9;

int main() {
	int n, k;

	cin >> n >> k;

	scanf("%s", s);

	for (int i = 0; i < k; i++) {
		int c;

		scanf("%d", &c);

		for (int j = 0; j < c; j++) {
			int x;

			scanf("%d", &x);
			x--;

			a[x].push_back(i);
		}
	}

	for (int i = 0; i < k; i++) {
		p[i] = i;
		st[i][1] = 1;
		st[i][0] = 0;
	}

	p[k] = k;
	st[k][0] = inf;

	for (int i = 0; i < n; i++) {
		if ((int)a[i].size() != 2) {
			if ((int)a[i].size() == 1) {
				int x = a[i][0];
				if (s[i] == '0') {
					merg(x, k, 0);
				}
				else {
					merg(x, k, 1);
				}
			}
			printf("%d\n", ans);
			continue;
		}

		if (s[i] == '0') {
			merg(a[i][0], a[i][1], 1);
		}
		else {
			merg(a[i][0], a[i][1], 0);
		}

		printf("%d\n", ans);
	}
}