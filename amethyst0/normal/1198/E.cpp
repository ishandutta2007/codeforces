#pragma comment(linker, "/STACK:1000000000")
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

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int maxn = 110, maxm = 210;

struct edge {
	int x, y, f, c;

	edge() {

	}

	edge(int x, int y, int f, int c) : x(x), y(y), f(f), c(c) {

	}
};

edge mas[maxm * maxm];
int posit = 0;

int my_new(int x, int y, int f, int c) {
	mas[posit] = edge(x, y, f, c);
	return posit++;
}

vector <int> ed[maxm];

void add(int x, int y, int c) {
	ed[x].push_back(my_new(x, y, 0, c));
	ed[y].push_back(my_new(y, x, 0, 0));
}

int dst[maxm];
int pos[maxm];

bool bfs(int s, int t) {
	memset(dst, -1, sizeof dst);
	memset(pos, 0, sizeof pos);
	dst[s] = 0;

	queue <int> q;

	q.push(s);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int i = 0; i < (int)ed[v].size(); i++) {
			int it = ed[v][i];
			int u = mas[it].y;

			if (mas[it].f != mas[it].c && dst[u] == -1) {
				dst[u] = dst[v] + 1;
				q.push(u);
			}
		}
	}

	return dst[t] != -1;
}

ll dfs(int s, int t, ll cnt) {
	if (s == t) {
		return cnt;
	}

	ll tot = 0;

	while (pos[s] != (int)ed[s].size()) {
		int it = ed[s][pos[s]];
		int u = mas[it].y;

		if (dst[u] == dst[s] + 1) {
			ll cur = dfs(u, t, min((ll)mas[it].c - mas[it].f, cnt));
			cnt -= cur;
			tot += cur;
			mas[it].f += cur;
			mas[it ^ 1].f -= cur;
			if (cnt == 0) {
				break;
			}
		}

		pos[s]++;
	}

	return tot;
}

int n;

vector <pair <pii, pii> > g;

bool used[maxn][maxn];

int main() {
	cin >> n;
	cin >> n;

	vector <int> x, y;

	for (int i = 0; i < n; i++) {
		int lx, ly, rx, ry;

		cin >> lx >> ly >> rx >> ry;

		x.push_back(lx);
		x.push_back(rx + 1);
		y.push_back(ly);
		y.push_back(ry + 1);

		g.push_back(mp(mp(lx, rx + 1), mp(ly, ry + 1)));
	}

	if (n == 0) {
		cout << 0 << endl;
		return 0;
	}

	sort(x.begin(), x.end());
	x.resize(unique(x.begin(), x.end()) - x.begin());
	sort(y.begin(), y.end());
	y.resize(unique(y.begin(), y.end()) - y.begin());

	int d = (int)x.size() - 1;
	int d1 = (int)y.size() - 1;

	int s = d + d1;
	int t = s + 1;

	for (int i = 0; i < d; i++) {
		add(s, i, x[i + 1] - x[i]);
	}

	for (int i = 0; i < d1; i++) {
		add(i + d, t, y[i + 1] - y[i]);
	}

	for (int i = 0; i < n; i++) {
		int lx = g[i].first.first;
		int rx = g[i].first.second;
		int ly = g[i].second.first;
		int ry = g[i].second.second;

		lx = lower_bound(x.begin(), x.end(), lx) - x.begin();
		rx = lower_bound(x.begin(), x.end(), rx) - x.begin();
		ly = lower_bound(y.begin(), y.end(), ly) - y.begin();
		ry = lower_bound(y.begin(), y.end(), ry) - y.begin();

		for (int j = lx; j < rx; j++) {
			for (int k = ly; k < ry; k++) {
				if (!used[j][k]) {
					add(j, k + d, (int)1e9);
				}
				used[j][k] = true;
			}
		}
	}

	ll ans = 0;

	while (bfs(s, t)) {
		ans += dfs(s, t, (ll)1e18);
	}

	cout << ans << endl;

	//system("pause");
}