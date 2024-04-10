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
#include <assert.h>
using namespace std;
#define int long long
int MOD = 1000000007; 
int N, M, K;
vector<set<int> > g;
int A;
vector<int> V;
void eraseV(int a) {
	V[a] = 0;
	A--;
	vector<int> t;
	for (auto x : g[a]) {
		g[x].erase(a);
		t.push_back(x);
	}
	g[a].clear();
	for (auto x : t) {
		if (V[x] == 1 && (int)g[x].size() < K) {
			eraseV(x);
		}
	}
	
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N >> M >> K;
	A = N;
	g.resize(N);
	V.resize(N, 1);
	int a, b;
	vector < pair<int, int> > vp;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		a--; b--;
		g[a].insert(b);
		g[b].insert(a);
		vp.emplace_back(a, b);
	}
	for (int i = 0; i < N; i++) {
		if ((int)g[i].size() < K && V[i] == 1) {
			eraseV(i);
		}
	}
	/*for (int i = 0; i < N; i++) {
		if (V[i] == 1) {
			assert((int)g[i].size() >= K);
		}
	}*/
	vector<int> res;
	res.push_back(A);
	for (int i = M - 1; i > 0; i--) {
		a = vp[i].first;
		b = vp[i].second;
		g[a].erase(b);
		g[b].erase(a);
		if (V[a] == 1 && (int)g[a].size() < K) {
			eraseV(a);
		}
		if (V[b] == 1 && (int)g[b].size() < K) {
			eraseV(b);
		}
		res.push_back(A);
	}
	reverse(res.begin(), res.end());
	for (int i = 0; i < M; i++) {
		cout << res[i] << endl;
	}
}