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
bool isInside(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < N;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N;
	vector<string> A(N);
	vector<string> B(N, string(N, '.'));
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	set<pair<int, int> > st;
	for (int i = -(N - 1); i <= N - 1; i++) {
		for (int j = -(N - 1); j <= N - 1; j++) {
			st.emplace(i, j);
		}
	}
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			if (A[x][y] == 'o') {
				for (int xx = 0; xx < N; xx++) {
					for (int yy = 0; yy < N; yy++) {
						if (A[xx][yy] == '.') {
							st.erase(make_pair(xx - x, yy - y));
						}
					}
				}
			}
		}
	}
	vector<pair<int, int> > vp;
	for (auto s : st) {
		vp.push_back(s);
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i][j] == 'o') {
				B[i][j] = 'o';
				for (pair<int, int> p : vp) {
					int xx = i + p.first;
					int yy = j + p.second;
					if (isInside(xx, yy)) {
						if (A[xx][yy] != 'o') {
							B[xx][yy] = 'x';
						}
					}
				}
			}
		}
	}
	
	bool ok = true;
	for (int i = 0; i < N; i++) {
		if (A[i] != B[i]) {
			ok = false;
		}
	}
	if (ok) {
		vector<string> res(2 * N - 1, string(2 * N - 1, '.'));
		for (pair<int, int> p : vp) {
			res[p.first + N - 1][p.second + N - 1] = 'x';
		}
		res[N - 1][N - 1] = 'o';
		cout << "YES" << endl;
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << endl;
		}
	}
	else {
		cout << "NO" << endl;
	}
}