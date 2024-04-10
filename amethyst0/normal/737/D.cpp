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
#include <random>
#include <unordered_set>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = 3300;
/*
set <pair <pii, pii> > m;

void go(int l, int r, int k, int tp) {
	if (l > r) {
		return;
	}

	if (m.count(mp(mp(l, r), mp(k, tp)))) {
		return;
	}

	m.insert(mp(mp(l, r), mp(k, tp)));

	if (tp == 0) {
		go(l + k, r, k, tp ^ 1);
		go(l + k + 1, r, k + 1, tp ^ 1);
	} else {
		go(l, r - k, k, tp ^ 1);
		go(l, r - k - 1, k + 1, tp ^ 1);
	}
}
*/

int v[4010];
int sums = 0;

pii res[1 << 24];
int g = (1 << 24) - 1;

int get_sum(int l, int r) {
	if (l == 0) {
		return v[r];
	}

	return v[r] - v[l - 1];
}

int getr(int pos, int hsh) {
	pos &= g;

	if (res[pos].first == 0) {
		return -1;
	}

	if (res[pos].first == hsh) {
		return res[pos].second;
	}

	return getr(pos + 1, hsh);
}

void add(int pos, int hsh, int z) {
	pos &= g;

	if (res[pos].first == 0) {
		res[pos] = mp(hsh, z);
		return;
	}

	add(pos + 1, hsh, z);
}

int n;

int go(int l, int r, int k, int tp) {
	int hsh = ((l * n + r) * n + k) * 2 + tp;
	hsh = abs(hsh);

	int it = getr(hsh, hsh);

	if (it != -1) {
		return it;
	}

	sums++;

	if (r - l + 1 < k) {
		add(hsh, hsh, 0);
		return 0;
	}

	int ans = 0;

	if (tp == 0) {
		ans = go(l + k, r, k, 1) + get_sum(l, l + k - 1);
		if (r - l + 1 > k) {
			ans = max(ans, go(l + k + 1, r, k + 1, 1) + get_sum(l, l + k));
		}
	} else {
		ans = go(l, r - k, k, 0) - get_sum(r - k + 1, r);
		if (r - l + 1 > k) {
			ans = ans = min(ans, go(l, r - k - 1, k + 1, 0) - get_sum(r - k, r));
		}
	}

	add(hsh, hsh, ans);

	return  ans;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		//v[i] = i;
		if (i != 0) {
			v[i] += v[i - 1];
		}
	}

	cout << go(0, n - 1, 1, 0) << endl;
	//cout << sums << endl;

	return 0;
}