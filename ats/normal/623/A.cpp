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
	int N, M;
	cin >> N >> M;
	int INF = 1000000;
	vector<vector<int> > g(N, vector<int>(N, INF));
	vector<vector<int> > G(N, vector<int>(N, 0));
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		a--; b--;
		g[a][b] = 1;
		g[b][a] = 1;
	}
	for (int i = 0; i < N; i++) {
		g[i][i] = 0;
	}
	G = g;
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	string res(N, 'b');
	bool ok = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			
			if (g[i][j] >= 2) {
				ok = true;

				for (int k = 0; k < N; k++) {
					if (g[i][k] >= 2) {
						res[k] = 'a';
					}
				}

				for (int k = 0; k < N; k++) {
					if (g[k][j] >= 2) {
						res[k] = 'c';
					}
				}


				break;
			}
		}
		if (ok)break;
	}
	//cout << res << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i != j) {
				if ((G[i][j] == 1) != (abs(res[i] - res[j]) <= 1)) {
					cout << "No" << endl;
					return 0;
				}
			}
		}
	}
	cout << "Yes" << endl;
	cout << res << endl;
}