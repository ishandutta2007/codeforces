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
struct Edge {
	int a;
	int b;
	int w;
};
int N, M, L, S, T;
vector<vector<int> > g;
vector<vector<int> > w;
vector<vector<int> > idx;
vector<Edge> es;
int solve() {
	priority_queue<pair<int, int> > pq;
	int INF = (int)1 << 60;
	vector<int> D(N, INF);
	D[S] = 0;
	pq.emplace(0, S);
	while (pq.size()) {
		int a = pq.top().second;
		pq.pop();

		for (int i = 0; i < g[a].size(); i++) {
			if (D[g[a][i]] > D[a] + es[idx[a][i]].w) {
				D[g[a][i]] = D[a] + es[idx[a][i]].w;
				pq.emplace(-D[g[a][i]], g[a][i]);
			}
		}

	}

	return D[T];

}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M >> L >> S >> T;
	g.resize(N);
	w.resize(N);
	idx.resize(N);
	es.resize(M);
	vector<int> A;
	for (int i = 0; i < M; i++) {
		cin >> es[i].a >> es[i].b >> es[i].w;
		g[es[i].a].push_back(es[i].b);
		g[es[i].b].push_back(es[i].a);
		w[es[i].a].push_back(es[i].w);
		w[es[i].b].push_back(es[i].w);
		idx[es[i].a].push_back(i);
		idx[es[i].b].push_back(i);

		if (es[i].w == 0) {
			A.push_back(i);
		}
	}
	int K = A.size();
	int ng = K - 1;
	int ok = max(ng + 10, (L + 5) * K);

	bool f = false;
	while (ok - ng > 1) {
		int m = (ok + ng) / 2;

		if (K > 0) {
			int b = m / K;

			for (int i = 0; i < K; i++) {
				if (i < m % K) {
					es[A[i]].w = b + 1;
				}
				else {
					es[A[i]].w = b;
				}
			}
		}
		int c = solve();
		//cerr << m << " " << c << endl;
		if (c == L && m >= K) {
			f = true;
			break;
		}
		if (c > L) {
			ok = m;
		}
		else {
			ng = m;
		}
	}
	if (f) {
		cout << "YES" << endl;
		for (int i = 0; i < M; i++) {
			cout << es[i].a << " " << es[i].b << " " << es[i].w << endl;
		}
	}
	else {
		cout << "NO" << endl;
	}
}