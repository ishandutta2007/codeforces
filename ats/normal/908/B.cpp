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
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<string> S(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}
	int sx, sy;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (S[i][j] == 'S') {
				sx = i;
				sy = j;
				break;
			}
		}
	}
	int x, y;
	vector<int> A = { 0,1,2,3 };
	string T;
	cin >> T;
	//cerr << sx << " " << sy << endl;
	do {
		//res++;
		x = sx;
		y = sy;
		for (int i = 0; i < T.size(); i++) {
			x += dx[A[T[i] - '0']];
			y += dy[A[T[i] - '0']];
			if (x < 0 || x >= N || y < 0 || y >= M) {
				break;
			}
			if (S[x][y] == '#') {
				break;
			}
			if (S[x][y] == 'E') {
				res++;
				break;
			}
		}
		
	} while (next_permutation(A.begin(), A.end()));
	cout << res << endl;
}