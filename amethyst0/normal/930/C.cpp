#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <ctime>

#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>
#define ld long double

using namespace std;

const int maxn = (int)1e5 + 10;
int t[4 * maxn];
int v[maxn];
int cnt[2][maxn];

int n, m;

void change(int it, int l, int r, int pos, int x) {
	if (l == r) {
		t[it] = x;
	}
	else {
		int m = (l + r) >> 1;

		if (pos <= m) {
			change(2 * it, l, m, pos, x);
		}
		else {
			change(2 * it + 1, m + 1, r, pos, x);
		}

		t[it] = max(t[2 * it], t[2 * it + 1]);
	}
}

int go(int it, int l, int r, int lm, int rm) {
	if (l == lm && r == rm) {
		return t[it];
	}
	else {
		int m = (l + r) >> 1;

		if (rm <= m) {
			return go(2 * it, l, m, lm, rm);
		}
		else if (lm > m) {
			return go(2 * it + 1, m + 1, r, lm, rm);
		}
		else {
			return max(go(2 * it, l, m, lm, m), go(2 * it + 1, m + 1, r, m + 1, rm));
		}
	}
}

void go(int it) {
	memset(t, 0, sizeof t);

	for (int i = 0; i < m; i++) {
		int ans = go(1, 0, n - 1, 0, v[i]) + 1;

		cnt[it][i] = ans;

		change(1, 0, n - 1, v[i], ans);
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int l, r;

		scanf("%d %d", &l, &r);
		l--;
		r--;

		v[l]++;
		v[r + 1]--;
	}

	for (int i = 1; i < m; i++) {
		v[i] += v[i - 1];
	}

	go(0);
	reverse(v, v + m);
	go(1);
	reverse(cnt[1], cnt[1] + m);

	int ans = 0;

	for (int i = 0; i < m; i++) {
		ans = max(ans, cnt[0][i] + cnt[1][i] - 1);
	}

	cout << ans << endl;

	//system("pause");
}