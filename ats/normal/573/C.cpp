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
vector<vector<int> > g;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	g.resize(N);
	int res = 0;
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	queue<int> qu;
	vector<int> cnt(N, 0);
	vector<int> V(N, 0);
	for (int i = 0; i < N; i++) {
		if (g[i].size() == 1) {
			qu.push(i);
			cnt[i] = 1;
			V[i] = 1;
		}
	}
	while (qu.size()) {
		a = qu.front(); qu.pop();
		if (cnt[a] == 1 && (int)g[a].size() <= 2) {
			V[a] = 1;
			for (auto i : g[a]) {
				if (V[i] == 0) {
					cnt[i]++;
					qu.push(i);
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (V[i] == 0) {
			if ((cnt[i] == 1 && g[i].size() == 2) || (cnt[i] == 2 && g[i].size() == 3)) {
				V[i] = 1;
			}
		}
	}
	bool ok = true;
	int c1 = 0;
	int vs = 0;
	int es = 0;
	for (int i = 0; i < N; i++) {
		if (V[i] == 0) {
			vs++;
			int z = 0;
			for (auto j : g[i]) {
				if (V[j] == 0) {
					z++;
				}
			}
			es += z;
			if (z > 2) {
				//cerr << "z>2 " << i << endl;
				ok = false;
			}
		}
	}
	//cerr << "vs es " << vs << " " << es / 2 << endl;
	if (vs > 0 && es / 2 != vs - 1) {
		ok = false;
	}

	if (ok) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}