#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <limits.h>
#include <fstream>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
#define uint unsigned int
#define mp make_pair

const int maxn = 5010;
int v[maxn];
int lnk[maxn];

int main() {
	int t;

	cin >> t;

	while (t--) {
		int n;
		scanf("%d", &n);

		for (int i = 0; i < 2 * n; i++) {
			scanf("%d", &v[i]);
			v[i]--;
		}

		v[2 * n] = (int)1e9;

		vector <int> g;

		g.push_back(2 * n);

		for (int i = 2 * n - 1; i >= 0; i--) {
			while (v[g.back()] < v[i]) {
				g.pop_back();
			}

			lnk[i] = g.back();
			g.push_back(i);
		}

		vector <int> x;

		int p = 0;

		while (p != 2 * n) {
			x.push_back(lnk[p] - p);
			p = lnk[p];
		}

		bitset <maxn> b;
		b.reset();
		b[0] = 1;

		for (int y : x) {
			b |= b << y;
		}

		if (b[n]) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}