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
	vector<vector<int> > A(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}

	vector<vector<int> > X(N);
	vector<vector<int> > Y(M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			X[i].push_back(A[i][j]);
		}
		sort(X[i].begin(), X[i].end());
		X[i].erase(unique(X[i].begin(), X[i].end()), X[i].end());
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			Y[i].push_back(A[j][i]);
		}
		sort(Y[i].begin(), Y[i].end());
		Y[i].erase(unique(Y[i].begin(), Y[i].end()), Y[i].end());
	}
	//cerr << Y[2].size() << endl;
	vector<vector<int> >res(N, vector<int>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int val = A[i][j];
			res[i][j] = 0;
			int x = lower_bound(X[i].begin(), X[i].end(), val) - X[i].begin();
			int y = lower_bound(Y[j].begin(), Y[j].end(), val) - Y[j].begin();


			res[i][j] += max(x, y);
			res[i][j] += max((int)X[i].size() - x, (int)Y[j].size() - y);

		}
	}



	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (j > 0)cout << " ";
			cout << res[i][j];
		}
		cout << endl;
	}


}