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
	int N, M, K, S;;
	cin >> N >> M >> K >> S;
	vector<vector<int> > g(N);
	vector<vector<int> > X(K);
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a; a--;
		X[a].push_back(i);
	}

	for (int i = 0; i < M; i++) {
		cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int INF = (int)1 << 60;
	vector<vector<int> > D(N, vector<int>(K, INF));


	for (int i = 0; i < K; i++) {
		queue<int> qu;
		for (int j = 0; j < X[i].size(); j++) {
			qu.push(X[i][j]);
			D[X[i][j]][i] = 0;
		}

		while (qu.size()) {
			a = qu.front();
			qu.pop();
			for (int k : g[a]) {
				if (D[k][i] > D[a][i] + 1) {
					D[k][i] = D[a][i] + 1;
					qu.push(k);
				}
			}
		}

	}

	for (int i = 0; i < N; i++) {
		sort(D[i].begin(), D[i].end());
		int res = 0;
		for (int j = 0; j < S; j++) {
			res += D[i][j];
		}
		if (i > 0)cout << " ";
		cout << res;
	}
	cout << endl;

}