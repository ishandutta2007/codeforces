#pragma comment(linker, "/STACK:1000000000")
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
#include <cstdio>
#include <cassert>
#include <cstring>
#include <unordered_set>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = (int)3e5 + 10, maxlog = 20;
int v[maxn];
pii tr[2][maxlog][maxn];

int solve(int l, int r) {
	if (l == r) {
		return 0;
	}
	int d = 0;
	while ((1 << d) <= r - l + 1) {
		d++;
	}

	d--;

	int pos = min(tr[0][d][l], tr[0][d][r - (1 << d) + 1]).second;

	if (l != pos && r != pos) {
		return solve(l, pos) + solve(pos, r);
	}

	pos = max(tr[1][d][l], tr[1][d][r - (1 << d) + 1]).second;
	if (l != pos && r != pos) {
		return solve(l, pos) + solve(pos, r);
	}
	return 1;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
			tr[0][0][i] = tr[1][0][i] = mp(v[i], i);
		}

		for (int it = 1; it < maxlog; it++) {
			for (int i = 0; i <= n - (1 << it); i++) {
				tr[0][it][i] = min(tr[0][it - 1][i], tr[0][it - 1][i + (1 << (it - 1))]);
			}
		}

		for (int it = 1; it < maxlog; it++) {
			for (int i = 0; i <= n - (1 << it); i++) {
				tr[1][it][i] = max(tr[1][it - 1][i], tr[1][it - 1][i + (1 << (it - 1))]);
			}
		}

		printf("%d\n", solve(0, n - 1));
	}
}