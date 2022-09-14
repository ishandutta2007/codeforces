#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

const int P = 1e9 + 7;

typedef long long ll;
typedef long double ld;
mt19937 rr(random_device{}());

struct Face {
	vector<int> imp;
	int col;
};

bool operator < (const Face &a, const Face &b) {
	for (int i = 0; i < min(sz(a.imp), sz(b.imp)); ++i) {
		if (a.imp[i] != b.imp[i])
			return a.imp[i] < b.imp[i];
	}
	return sz(a.imp) < sz(b.imp);
}

vector<Face> faces; 

vector<int> pos;

int g(int x, int y, int n) {
	return min(abs(x - y), n - abs(x - y));
}

void solve(vector<int> ver, vector<int> x, vector<int> y, int col) {
	assert(col < 21);
	// cout << col << endl;
	int n = sz(ver);
	int m = sz(x);
	// for (int i = 0; i < n; ++i)
	// 	cout << ver[i] << " ";
	// cout << endl;

	// for (int i = 0; i < m; ++i)
	// 	cout << x[i] << ' ' << y[i] << endl;

	for (int i = 0; i < n; ++i)
		pos[ver[i]] = i;

	for (int i = 0; i < m; ++i) {
		if (pos[x[i]] > pos[y[i]]) {
			swap(x[i], y[i]);
		}
	}

	int k = 0;
	int cur = g(pos[x[0]], pos[y[0]], n);
	for (int i = 1; i < n; ++i) {
		if (cur < g(pos[x[i]], pos[y[i]], n)) {
			cur = g(pos[x[i]], pos[y[i]], n);
			k = i;
		}
	}

	vector<vector<int>> g(n);
	for (int i = 0; i < m; ++i) {
		g[pos[x[i]]].push_back(pos[y[i]]);
		g[pos[y[i]]].push_back(pos[x[i]]);
	}

	vector<int> d(n);

	int u = pos[x[k]];
	int v = pos[y[k]];
	cur = v;
	Face f;
	f.imp.push_back(ver[v]);
	d[u] = 1;
	d[v] = 1;

	// cout << u << endl << v << endl;

	if (v - u <= n / 2) {
		while (cur != u) {
			int t = -1;
			for (int w : g[cur]) {
				if ((u < w && w < v) || (cur == v && u == w))
					continue;
				if (t == -1 || (u - w + n) % n < (u - t + n) % n)
					t = w;
			}
			assert(t != -1);
			d[t] = 1;
			f.imp.push_back(ver[t]);
			cur = t;
			// cout << cur << endl;
		}
	} else {
		while (cur != u) {
			int t = -1;
			for (int w : g[cur]) {
				if (!(u <= w && w <= v) || (cur == v && u == w))
					continue;
				if (t == -1 || (w - u + n) % n < (t - u + n) % n)
					t = w;
			}
			assert(t != -1);
			d[t] = 1;
			f.imp.push_back(ver[t]);
			cur = t;
			// cout << cur << endl;
		}
	}

	int s = sz(f.imp);

	// for (int v : f.imp)
	// 	cout << v << ' ';
	// cout << endl;
	// cout << endl;


	f.col = col;
	sort(all(f.imp));
	reverse(all(f.imp));
	faces.push_back(f);

	vector<vector<int>> newV(s);
	vector<vector<int>> newX(s);
	vector<vector<int>> newY(s);
	vector<vector<int>> type(n);  

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		newV[cnt % s].push_back(ver[i]);
		type[i].push_back(cnt % s);
		if (d[i]) {
			++cnt;
			newV[cnt % s].push_back(ver[i]);
			type[i].push_back(cnt % s);
		}
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < sz(type[pos[x[i]]]); ++j) {
			for (int k = 0; k < sz(type[pos[y[i]]]); ++k) {
				int u = type[pos[x[i]]][j];
				int v = type[pos[y[i]]][k];
				if (u == v) {
					newX[u].push_back(x[i]);
					newY[u].push_back(y[i]);
				}
			}
		}
	}

	for (int i = 0; i < s; ++i) {
		if (sz(newV[i]) > 2) {
			solve(newV[i], newX[i], newY[i], col + 1);
		}
	}
}
	
int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> x(m), y(m);
	for (int i = 0; i < m; ++i) {
		cin >> x[i] >> y[i];
		--x[i]; --y[i];
	}

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		v[i] = i;

	pos.resize(n);

	for (int i = 0; i < n; ++i) {
		x.push_back(i);
		y.push_back((i + 1) % n);
	}

	solve(v, x, y, 1);

	sort(all(faces));

	for (int i = 0; i < sz(faces); ++i) {
		// for (int v : faces[i].imp)
		// 	cout << v << " ";
		// cout << endl;
		// cout << faces[i].col << endl;
		cout << faces[i].col << " ";
	}
	cout << endl;

}