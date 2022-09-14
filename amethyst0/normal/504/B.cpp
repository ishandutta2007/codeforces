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

const int maxn = (int)2e5 + 10;
int v[2][maxn];
int t[maxn];
int sum[2][maxn];
int n;

void change(int x) {
	for ( ; x < n; x |= (x + 1)) {
		t[x]++;
	}
}

int getsum(int x) {
	int ans = 0;

	for ( ; x >= 0; x = (x & (x + 1)) - 1) {
		ans += t[x];
	}

	return ans;
}

void make(int it, int pos) {
	if (pos == n) {
		return;
	}

	int x = v[it][pos] - getsum(v[it][pos]);
	change(v[it][pos]);

	sum[it][pos] += x;

	make(it, pos + 1);
}

int tr[4 * maxn];

void change(int it, int l, int r, int pos, int x) {
	if (l == r) {
		tr[it] += x;
	} else {
		int m = (l + r) >> 1;

		if (pos <= m) {
			change(2 * it, l, m, pos, x);
		} else {
			change(2 * it + 1, m + 1, r, pos, x);
		}

		tr[it] += x;
	}
}

int kth(int it, int l, int r, int k) {
	if (l == r) {
		tr[it]--;
		return l;
	} else {
		tr[it]--;
		int m = (l + r) / 2;
		if (tr[2 * it] > k) {
			return kth(2 * it, l, m, k);
		} else {
			return kth(2 * it + 1, m + 1, r, k - tr[2 * it]);
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[0][i]);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[1][i]);
	}

	make(0, 0);

	memset(t, 0, sizeof t);

	make(1, 0);

	for (int i = 0; i < n; i++) {
		sum[0][i] += sum[1][i];
	}

	for (int i = n - 1; i >= 0; i--) {
		int x = n - i;
		if (sum[0][i] >= x) {
			if (i != 0) {
				sum[0][i - 1] += sum[0][i] / x;
			}

			sum[0][i] %= x;
		}
	}

	for (int i = 0; i < n; i++) {
		change(1, 0, n - 1, i, 1);
	}

	for (int i = 0; i < n; i++) {
		int x = kth(1, 0, n - 1, sum[0][i]);

		printf("%d ", x);
	}

	return 0;
}