#pragma comment(linker, "/STACK:1000000000")
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

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int maxn = (int)1e6 + 10;
int a[maxn];
int b[maxn];

pii t[4 * maxn];

void change(int it, int l, int r, int pos, int x) {
	if (l == r) {
		t[it].first += x;
		t[it].second = max(0, t[it].first);
	}
	else {
		int m = (l + r) >> 1;

		if (pos <= m) {
			change(2 * it, l, m, pos, x);
		}
		else {
			change(2 * it + 1, m + 1, r, pos, x);
		}

		t[it].first += x;
		t[it].second = max(t[2 * it + 1].second, t[2 * it + 1].first + t[2 * it].second);
	}
}

int go(int it, int l, int r, int x) {
	if (t[it].second + x <= 0) {
		return -1;
	}

	if (l == r) {
		return l;
	}

	int m = (l + r) >> 1;

	if (t[2 * it + 1].second + x > 0) {
		return go(2 * it + 1, m + 1, r, x);
	}

	return go(2 * it, l, m, x + t[2 * it + 1].first);
}

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);

		change(1, 0, maxn - 1, a[i], 1);
	}

	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);

		change(1, 0, maxn - 1, b[i], -1);
	}

	int q;

	cin >> q;

	while (q--) {
		int tp, pos, x;

		scanf("%d %d %d", &tp, &pos, &x);
		pos--;

		if (tp == 1) {
			change(1, 0, maxn - 1, a[pos], -1);
			a[pos] = x;
			change(1, 0, maxn - 1, a[pos], 1);
		}
		else {
			change(1, 0, maxn - 1, b[pos], 1);
			b[pos] = x;
			change(1, 0, maxn - 1, b[pos], -1);
		}

		printf("%d\n", go(1, 0, maxn - 1, 0));
	}

	//system("pause");

	return 0;
}