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
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> A(N, 0);
	int a;
	for (int i = 0; i < K; i++) {
		cin >> a; a--;
		A[a] = 1;
	}
	int b;
	vector<vector<int> > g(N);
	for (int i = 0; i < M; i++) {
		cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<int> t_cnt(N, 0);
	vector<int> t_use(N, 0);

	for (int i = 0; i < N; i++)if (A[i] == 0) {
		t_use[i] = 1;
		for (int j = 0; j < g[i].size(); j++) {
			if (A[g[i][j]] == 0) {
				t_cnt[i]++;
			}
		}
	}
	double ok = 0;
	double ng = 1.0001;
	double m;
	vector<int> cnt;
	vector<int> use;
	for (int t = 0; t < 50; t++) {
		m = (ok + ng)*0.5;
		if (t == 49)m = ok;
		queue<int> qu;
		cnt = t_cnt;
		use = t_use;
		int num = N - K;
		for (int i = 0; i < N; i++) {
			if (use[i] == 1) {
				if (cnt[i] < m * (double)g[i].size()) {
				
					use[i] = 0;
					qu.push(i);
					num--;
				}
			}
		}
		while ((int)qu.size()) {
			a = qu.front(); qu.pop();
			for (auto i : g[a]) {
				if (use[i] == 1) {
					cnt[i]--;
					if (cnt[i] - m * (double)g[i].size() < 0) {
						use[i] = 0;
						qu.push(i);
						num--;
					}
				}
			}
		}
		if (num > 0) {
			ok = m;
		}
		else {
			ng = m;
		}
	}
	//cerr << ok << endl;
	vector<int> res;
	for (int i = 0; i < N; i++) {
		if (use[i] == 1)res.push_back(i);
	}
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		if (i > 0) cout << " ";
		cout << res[i] + 1;
	}
	cout << endl;
}