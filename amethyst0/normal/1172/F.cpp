//#pragma comment(linker, "/STACK:1000000000")
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
#include <cassert>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define ld double

using namespace std;

const int maxn = (int)1e6 + 10;

vector <ll> t[4 * maxn];

int p;
int v[maxn];
ll sum[4 * maxn];

const ll inf = (ll)1e18;

ll calc(int it, int p1, int p2) {
	ll x = -inf;

	if (p1 != 0) {
		x = max(x, t[2 * it][p1 - 1]);
	}

	if (p2 != 0) {
		x = max(x, t[2 * it + 1][p2 - 1] - sum[2 * it] + (ll)p * p1);
	}

	return x;
}

void build(int it, int l, int r) {
	if (l != r) {
		int m = (l + r) >> 1;

		build(2 * it, l, m);
		build(2 * it + 1, m + 1, r);
	}

	if (l == r) {
		t[it].push_back(p - v[l]);
		sum[it] = v[l];
		return;
	}

	sum[it] = sum[2 * it] + sum[2 * it + 1];

	int p1 = 0;
	int p2 = 0;

	while (!(p1 == (int)t[2 * it].size() && p2 == (int)t[2 * it + 1].size())) {
		if (p2 == (int)t[2 * it + 1].size()) {
			t[it].push_back(calc(it, p1 + 1, p2));
			p1++;
		}
		else if (p1 == (int)t[2 * it].size()) {
			t[it].push_back(calc(it, p1, p2 + 1));
			p2++;
		}
		else {
			ll x = calc(it, p1 + 1, p2);
			ll y = calc(it, p1, p2 + 1);

			if (x <= y) {
				t[it].push_back(x);
				p1++;
			}
			else {
				t[it].push_back(y);
				p2++;
			}
		}
	}
}

ll solve(int it, int l, int r, int lm, int rm, ll x) {
	if (l == lm && r == rm) {
		int pos = upper_bound(t[it].begin(), t[it].end(), x) - t[it].begin();
		return x + sum[it] - (ll)pos * p;
	}
	else {
		int m = (l + r) >> 1;

		if (rm <= m) {
			return solve(2 * it, l, m, lm, rm, x);
		}
		else if (lm > m) {
			return solve(2 * it + 1, m + 1, r, lm, rm, x);
		}
		else {
			x = solve(2 * it, l, m, lm, m, x);
			x = solve(2 * it + 1, m + 1, r, m + 1, rm, x);
			return x;
		}
	}
}

int main() {
	int n, m;

	cin >> n >> m >> p;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	build(1, 0, n - 1);

	while (m--) {
		int l, r;

		scanf("%d %d", &l, &r);
		l--;
		r--;

		printf("%lld\n", solve(1, 0, n - 1, l, r, 0));
	}

	//system("pause");
	return 0;
}