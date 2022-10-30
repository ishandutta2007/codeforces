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
vector<vector<int> > res;
void tenchi(vector<vector<int> > A) {
	res.clear();
	res.resize(A[0].size(), vector<int>(A.size()));
	for (int i = 0; i < A[0].size(); i++) {
		for (int j = 0; j < A.size(); j++) {
			res[i][j] = A[j][i];
		}
	}
	map<int, int> mp;
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A[0].size(); j++) {
			mp[(i)*A[0].size() + j + 1] = (j)*A.size() + i + 1;
		}
	}
	for (int i = 0; i < A[0].size(); i++) {
		for (int j = 0; j < A.size(); j++) {
			res[i][j] = mp[res[i][j]];
		}
	}
}
int solve(int N, int M) {
	res.clear();
	res.resize(N, vector<int>(M));
	vector<int> K;
	K.push_back(2);
	K.push_back(4);
	K.push_back(1);
	K.push_back(3);
	for (int i = 5; i <= M; i++) {
		if (i % 2 == 1) {
			K.push_back(i);
		}
		else {
			K.insert(K.begin() + (int)(K.size() - 2), i);
		}
	}
	if (M == 4) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (i % 2 == 0) {
					res[i][j] = K[j] + M*i;
				}
				else {
					res[i][j] = K[M - 1 - j] + M*i;
				}
			}
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				res[i][j] = K[(j + (i % 2)) % M] + M*i;

			}
		}
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	bool f = true;
	if (M >= 4) {
		solve(N, M);
	}
	else if (N >= 4) {
		solve(M, N);
		tenchi(res);
	}
	else {
		if (N == 3 && M == 3) {

			res = { {1,5,7},{3,9,2},{8,4,6} };
		}
		else {
			if (N == 1 && M == 1) {
				res = { {1} };
			}
			else {
				f = false;
			}
		}
		//f = false;
	}
	if (f) {
		///*for (int i = 0; i < N; i++) {
		//	for (int j = 0; j < M; j++) {
		//		if (j < M - 1) {
		//			int k = abs(res[i][j] - res[i][j + 1]);
		//			if (k == M)cerr << "ERRORtate" << i << " " << j << endl;
		//			if (k == 1) {
		//				if (((res[i][j] - 1) / M) == ((res[i][j + 1] - 1) / M)) {
		//					cerr << "ERRORtate" << i << " " << j << endl;
		//				}
		//			}
		//		}
		//		if (i < N - 1) {
		//			int k = abs(res[i + 1][j] - res[i][j]);
		//			if (k == M)cerr << "ERRORyoko" << i << " " << j << endl;
		//			if (k == 1) {
		//				if (((res[i][j] - 1) / M) == ((res[i + 1][j] - 1) / M)) {
		//					cerr << "ERRORyoko" << i << " " << j << endl;
		//				}
		//			}
		//		}
		//	}
		//}*/
		cout << "YES" << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (j > 0)cout << " ";
				cout << res[i][j];
			}
			cout << endl;
		}
	}
	else {
		cout << "NO" << endl;
	}

}