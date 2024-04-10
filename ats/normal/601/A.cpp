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


int N;
const int INF = 1ll << 60;
int solve(vector<vector<int> > &A) {
	queue<int> qu;
	qu.push(0);

	vector<int> dist(N, INF);
	dist[0] = 0;

	while (qu.size()) {
		int a = qu.front(); qu.pop();
		for (int i = 0; i < N; i++) {
			if (A[a][i] == 1) {
				if (dist[i] > dist[a] + 1) {
					dist[i] = dist[a] + 1;
					qu.push(i);
				}
			}
		}
	}
	return dist[N - 1];
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int M;
	cin >> N >> M;
	vector<vector<int> > A(N, vector<int>(N, 0));
	int res = 0;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b; a--; b--;
		A[a][b] = 1;
		A[b][a] = 1;
	}


	int X = solve(A);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i != j) {
				A[i][j] ^= 1;
			}
		}
	}
	//cerr << X << endl;
	X = max(X, solve(A));

	if (X >= INF)X = -1;
	cout << X << endl;
}