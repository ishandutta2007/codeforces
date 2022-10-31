#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
set<int> m;
set<int> e;
vector<vector<int> > g;
int z = -1;
void dfs(int a, int p) {
	if (z != -1)return;
	if (m.count(a) != 0) {
		z = a;
		return;
	}
	for (int i = 0; i < g[a].size(); i++) {
		if (p != g[a][i]) {
			dfs(g[a][i], a);
		}
	}
	if (z != -1)return;
}
signed main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		g.clear();
		g.resize(N);
		int a, b;
		for (int i = 0; i < N - 1; i++) {
			cin >> a >> b; a--; b--;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		m.clear();
		e.clear();
		int X;
		cin >> X;
		for (int i = 0; i < X; i++) {
			cin >> a;
			m.insert(a - 1);
		}
		int Y;
		cin >> Y;
		for (int i = 0; i < Y; i++) {
			cin >> a;
			e.insert(a - 1);
		}
		cout << "B " << ((*e.begin()) + 1) << endl << flush;

		cin >> a; a--;
		if (m.count(a) != 0) {
			cout << "C " << a + 1 << endl << flush;
		}
		else {
			z = -1;
			dfs(a, -1);
			cout << "A " << (z + 1) << endl << flush;
			cin >> a;
			if (e.count(a - 1) != 0) {
				cout << "C " << z + 1 << endl << flush;
			}
			else {
				cout << "C " << -1 << endl << flush;
			}
		}
	}
}