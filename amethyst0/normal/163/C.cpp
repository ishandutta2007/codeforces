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

#define ll long long
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)2e5 + 10;

ll v[maxn];

ld ans[maxn];

int main() {
	int n;

	cin >> n;

	ll d, v1, v2;
	cin >> d >> v1 >> v2;

	vector <ld> t;

	ld x = (ld)v2 * d / (v1 + v2);

	for (int i = 0; i < n; i++) {
		scanf("%lld", &v[i]);
	}

	for (int i = 1; i < n; i++) {
		v[i] -= v[0];
	}

	v[0] = 0;

	for (int i = 0; i < n; i++) {
		t.push_back(v[i]);

		ld z = v[i] - x;

		if (z < 0) {
			z += 2 * d;
		}

		t.push_back(z);
	}

	sort(t.begin(), t.end());

	for (int i = n; i < 2 * n; i++) {
		v[i] = v[i - n] + 2 * d;
	}

	int l = 0;
	int r = 0;

	for (int i = 0; i < (int)t.size(); i++) {
		while (l < 2 * n && v[l] <= t[i]) {
			l++;
		}

		while (r < 2 * n && t[i] + x >= v[r]) {
			r++;
		}

		if (i + 1 != (int)t.size()) {
			ans[r - l] += (t[i + 1] - t[i]);
		}
		else {
			ans[r - l] += (2 * d - t[i]);
		}
	}

	for (int i = 0; i <= n; i++) {
		printf("%.20lf\n", (double)(ans[i] / 2 / d));
	}
}