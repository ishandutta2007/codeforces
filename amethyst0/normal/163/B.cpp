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

const int maxn = (int)1e5 + 10;

int m[maxn];
int v[maxn];
int id[maxn];

bool cmp(int a, int b) {
	if (m[a] == m[b]) {
		return v[a] < v[b];
	}

	return m[a] < m[b];
}

int main() {
	int n, k, h;

	cin >> n >> k >> h;

	for (int i = 0; i < n; i++) {
		scanf("%d", &m[i]);
		id[i] = i;
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	sort(id, id + n, cmp);

	ld l = 0;
	ld r = 1e9;

	for (int itt = 0; itt < 1000; itt++) {
		ld m = (l + r) / 2;

		int pos = 1;

		for (int it = 0; it < n; it++) {
			int i = id[it];

			if (pos == k + 1) {
				break;
			}

			if (v[i] * m >= pos * h) {
				pos++;
			}
		}

		if (pos == k + 1) {
			r = m;
		}
		else {
			l = m;
		}
	}

	vector <int> ans;

	int pos = 1;

	for (int it = 0; it < n; it++) {
		int i = id[it];

		if (pos == k + 1) {
			break;
		}

		if (v[i] * r >= pos * h) {
			ans.push_back(i);
			pos++;
		}
	}

	for (int i = 0; i < (int)ans.size(); i++) {
		printf("%d ", ans[i] + 1);
	}

	return 0;
}