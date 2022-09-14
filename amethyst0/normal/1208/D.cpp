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
#include <cstring>
#include <memory.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int maxn = (int)2e5 + 10;

int n;
ll v[maxn];

ll t[4 * maxn];

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

		t[it] = t[2 * it] + t[2 * it + 1];
	}
}

int go(int it, int l, int r, ll s) {
	if (l == r) {
		return l;
	}

	int m = (l + r) >> 1;

	if (t[2 * it] > s) {
		return go(2 * it, l, m, s);
	}

	return go(2 * it + 1, m + 1, r, s - t[2 * it]);
}

int ans[maxn];

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%lld", &v[i]);
	}

	for (int i = 1; i <= n; i++) {
		change(1, 1, n, i, i);
	}

	for (int i = n - 1; i >= 0; i--) {
		int x = go(1, 1, n, v[i]);
		change(1, 1, n, x, 0);
		ans[i] = x;
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}

	//system("pause");
	return 0;
}