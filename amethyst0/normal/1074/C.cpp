#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <random>
//#include <priority_queue>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ld long double
#define pii pair <int, int>
#define ll long long

using namespace std;

const int maxn = (int)3e5 + 10;

pii v[maxn];

int dst(int x, int y) {
	return abs(v[x].first - v[y].first) + abs(v[x].second - v[y].second);
}

ll go(vector <int> g) {
	sort(g.begin(), g.end());

	ll ans = 0;

	int x = g[0];

	g.push_back(x);

	for (int i = 0; i < (int)g.size() - 1; i++) {
		ans += dst(g[i], g[i + 1]);
	}

	return ans;
}

int dx[maxn], dy[maxn];

int main() {
	int a = 0, b = 0, c = 0, d = 0;

	int n;

	cin >> n;

	cin >> v[0].first >> v[0].second;

	for (int i = 1; i < n; i++) {
		scanf("%d %d", &v[i].first, &v[i].second);

		if (v[i].first < v[a].first) {
			a = i;
		}

		if (v[i].first > v[b].first) {
			b = i;
		}

		if (v[i].second < v[c].second) {
			c = i;
		}

		if (v[i].second > v[d].second) {
			d = i;
		}
	}

	vector <pii> x, y;

	for (int i = 0; i < n; i++) {
		x.push_back(mp(v[i].first, i));
		y.push_back(mp(v[i].second, i));
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	for (int i = 0; i < (int)x.size(); i++) {
		dx[x[i].second] = max(x[i].first - x[0].first, x.back().first - x[i].first);
	}

	for (int i = 0; i < (int)y.size(); i++) {
		dy[y[i].second] = max(y[i].first - y[0].first, y.back().first - y[i].first);
	}

	ll ans = 0;

	for (int i = 0; i < n; i++) {
		ans = max(ans, 2 * (ll)dx[i] + 2 * (ll)dy[i]);
	}

	vector <int> g;

	g.push_back(a);
	g.push_back(b);
	g.push_back(c);
	g.push_back(d);

	ll res = go(g);

	printf("%lld", ans);

	for (int i = 4; i <= n; i++) {
		printf(" %lld", res);
	}

	printf("\n");

	//system("pause");
}