#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <limits>
#include <ctime>
#include <random>
#include <bitset>
#include <numeric>
#include <complex>

#define pb push_back
#define mp make_pair
//#define endl '\n'
#define sqr(x) ((x) * (x))
#define IOboost ios_base::sync_with_stdio(false); cin.tie(NULL)
//#define int ll

#ifndef LOCALFILE
#define _getchar_nolock getchar_unlocked
#define _putchar_nolock putchar_unlocked
#endif

#pragma warning(disable : 4996)
#pragma optimize("gtsy", on)
//#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ld EPS = 1e-6;
const int N = (int)1e6 + 10;
const int INF = (int)1e9 + 10;
const int MOD = (int)1e9 + 7;

int ask(int u, int v) {
	cout << "? " << u + 1 << ' ' << v + 1 << endl;
	int w;
	cin >> w;
	return w - 1;
}

pii find(int v, vector<vector<int>>& a, int p = -1) {
	random_shuffle(a[v].begin(), a[v].end());
	vector<int> x;
	for (int i = 0; i < (int)a[v].size(); ++i) {
		if (a[v][i] == p)
			continue;
		x.pb(a[v][i]);
		if ((int)x.size() == 2) {
			int w = ask(x[0], x[1]);
			if (w != v)
				return find(w, a, v);
			x = {};
		}
	}
	if ((int)x.size() == 1) {
		pii p = find(x[0], a, v);
		p.first = 0;
		return p;
	}
	return { 1, v };
}

signed main() {/*
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif*/
	IOboost;

	srand(time(0));
	int n;
	cin >> n;
	vector<vector<int>> a(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		a[u].pb(v);
		a[v].pb(u);
	}
	pii x = find(0, a);
	if (x.first)
		cout << "! " << x.second + 1 << endl;
	else {
		int u = ask(0, x.second);
		cout << "! " << u + 1 << endl;
	}

	return 0;
}