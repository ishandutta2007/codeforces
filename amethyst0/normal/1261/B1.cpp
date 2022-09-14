//#pragma comment(linker, "/STACK:1000000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
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
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = (int)2e5 + 10;
int v[maxn];

int k[maxn], pos[maxn];
int num[maxn];

bool cmp(int a, int b) {
	return k[a] < k[b];
}

int t[4 * maxn];

void change(int it, int l, int r, int pos) {
	t[it]++;
	if (l != r) {
		int m = (l + r) >> 1;

		if (pos <= m) {
			change(2 * it, l, m, pos);
		}
		else {
			change(2 * it + 1, m + 1, r, pos);
		}
	}
}

int go(int it, int l, int r, int cnt) {
	if (l == r) {
		return l;
	}
	else {
		int m = (l + r) >> 1;

		if (t[2 * it] > cnt) {
			return go(2 * it, l, m, cnt);
		}
		else {
			return go(2 * it + 1, m + 1, r, cnt - t[2 * it]);
		}
	}
}

int res[maxn];

int main() {
	int n, m;

	cin >> n;

	vector <pii> g;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		g.push_back(mp(v[i], -i));
	}

	sort(g.rbegin(), g.rend());

	cin >> m;

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &k[i], &pos[i]);
		pos[i]--;
		num[i] = i;
	}

	sort(num, num + m, cmp);

	int itr = 0;

	for (int ii = 0; ii < m; ii++) {
		int i = num[ii];

		while (itr < k[i]) {
			int p = -g[itr].second;
			change(1, 0, n - 1, p);
			itr++;
		}

		int ans = go(1, 0, n - 1, pos[i]);

		res[i] = v[ans];
	}

	for (int i = 0; i < m; i++) {
		printf("%d\n", res[i]);
	}

	//system("pause");
}