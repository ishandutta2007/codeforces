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
#include <fstream>
#include <bitset>
#include <cstring>
#include <limits.h>
#include <unordered_map>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>
#define uint int

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int maxlog = 20;
int st[1 << maxlog];

struct Tree {
	vector<ll> v;
	vector<ll> t[maxlog];

	Tree() {}

	Tree(vector<ll> v) {
		int n = (int)v.size();
		t[0] = v;

		for (int it = 1; it < maxlog; it++) {
			for (int i = 0; i <= (int)v.size() - (1 << it); i++) {
				t[it].push_back(max(t[it - 1][i], t[it - 1][i + (1 << (it - 1))]));
			}
		}
	}

	ll go(int l, int r) {
		if (l > r) {
			return -(ll)1e18;
		}
		int d = r - l + 1;
		int it = st[d];
		return max(t[it][l], t[it][r - (1 << it) + 1]);
	}
};

const int maxn = (int)2e5 + 10;

Tree t[3];
int xx[maxn], pp[maxn];

int main() {
	int x = 1;
	int s = 0;

	while (x < (1 << maxlog)) {
		st[x] = s;
		s++;
		x <<= 1;
	}

	for (int i = 3; i < (1 << maxlog); i++) {
		if (st[i] == 0) {
			st[i] = st[i - 1];
		}
	}

	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		scanf("%d %d", &n, &m);
		vector<pii> g;
		vector<int> a;
		vector<ll> b;
		for (int i = 0; i < n; i++) {
			int x, p;
			scanf("%d %d", &x, &p);
			g.push_back(mp(x - p + 1, 1));
			g.push_back(mp(x + 1, -2));
			g.push_back(mp(x + p + 1, 1));
			a.push_back(x);
			xx[i] = x;
			pp[i] = p;
		}

		sort(all(g));
		sort(all(a));

		ll sum = 0;
		ll d = 0;
		ll pr = 0;

		int pos = 0;

		for (int x : a) {
			while (pos < (int)g.size() && g[pos].first <= x) {
				sum += (ll)(g[pos].first - pr) * d;
				pr = g[pos].first;
				d += g[pos].second;
				pos++;
			}

			b.push_back((ll)(x - pr + 1) * d + sum);
		}
		
		t[0] = Tree(b);
		for (int i = 0; i < (int)a.size(); i++) {
			b[i] = b[i] - a[i];
		}
		t[1] = Tree(b);
		for (int i = 0; i < (int)a.size(); i++) {
			b[i] = b[i] + 2ll * a[i];
		}
		t[2] = Tree(b);
		for (int i = 0; i < n; i++) {
			int x = xx[i];
			int p = pp[i];

			int l = lower_bound(all(a), x - p + 1) - a.begin();
			int r = lower_bound(all(a), x + p) - a.begin();

			ll val = max(t[0].go(0, l - 1), t[0].go(r, n - 1));
			if (val > m) {
				printf("0");
				continue;
			}
			int md = lower_bound(all(a), x) - a.begin();
			val = t[2].go(md, r - 1) - x - p;
			if (val > m) {
				printf("0");
				continue;
			}
			val = t[1].go(l, md) + x - p;
			if (val > m) {
				printf("0");
				continue;
			}
			printf("1");
		}

		printf("\n");
	}
}