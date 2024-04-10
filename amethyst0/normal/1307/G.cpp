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

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>
#define uint int

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int maxn = 55;

struct edge {
	int x, y, f, c, w;

	edge() {

	}

	edge(int x, int y, int c, int w) : x(x), y(y), f(0), c(c), w(w) {

	}
};

const int maxm = (int)1e5 + 10;

edge mas[maxm];
vector <int> ed[maxn];
int posit = 0;

void add(int x, int y, int c, int w) {
	ed[x].push_back(posit);
	mas[posit++] = edge(x, y, c, w);
	ed[y].push_back(posit);
	mas[posit++] = edge(y, x, 0, -w);
}

int dst[maxn];
bool in[maxn];
int lnk[maxn];
int n;

const int inf = (int)1e9;
int dist = -1;

bool ford(int s, int t) {
	for (int i = 0; i < n; i++) {
		dst[i] = inf;
	}

	dst[s] = 0;
	queue <int> q;
	q.push(s);
	in[s] = true;

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		in[v] = false;

		for (int it : ed[v]) {
			int u = mas[it].y;

			if (mas[it].f != mas[it].c && dst[u] > dst[v] + mas[it].w) {
				dst[u] = dst[v] + mas[it].w;
				lnk[u] = it;
				if (!in[u]) {
					q.push(u);
					in[u] = true;
				}
			}
		}
	}

	if (dst[t] == inf) {
		return false;
	}

	dist = dst[t];

	while (t != s) {
		int it = lnk[t];
		mas[it].f++;
		mas[it ^ 1].f--;
		t = mas[it].x;
	}
	return true;
}

int ford1(int s, int t) {
	for (int i = 0; i < n; i++) {
		dst[i] = inf;
	}

	dst[s] = 0;
	queue <int> q;
	q.push(s);
	in[s] = true;

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		in[v] = false;

		for (int it : ed[v]) {
			int u = mas[it].y;

			if (mas[it].f > 0 && dst[u] > dst[v] + mas[it].w) {
				dst[u] = dst[v] + mas[it].w;
				lnk[u] = it;
				if (!in[u]) {
					q.push(u);
					in[u] = true;
				}
			}
		}
	}

	int res = dst[t];

	if (dst[t] == inf) {
		throw 1;
	}

	while (t != s) {
		int it = lnk[t];
		mas[it].f--;
		t = mas[it].x;
	}

	return res;
}

int main() {
	int m;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y, w;

		scanf("%d %d %d", &x, &y, &w);
		x--;
		y--;
		add(x, y, 1, w);
	}

	int ans = 0;

	vector <int> f;

	while (ford(0, n - 1)) {
		ans++;
		f.push_back(dist);
	}

	/*while (ans--) {
		f.push_back(ford1(0, n - 1));
	}*/

	int q;

	cin >> q;

	while (q--) {
		ll x;

		scanf("%lld", &x);

		int cur = f[0];
		ld ans = 0;
		bool ok = true;

		for (int i = 1; i < (int)f.size(); i++) {
			int nd = f[i] - cur;
			if (i * (ll)nd <= x) {
				x -= (ll)i * nd;
				cur = f[i];
			}
			else {
				ok = false;
				ans = cur + (ld)x / i;
				break;
			}
		}

		if (ok) {
			ans = cur + (ld)x / (int)f.size();
		}

		printf("%.10lf\n", (double)ans);
	}
}