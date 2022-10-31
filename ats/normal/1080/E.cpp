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
vector<vector<int> > S;
bool EQ(const vector<int> &A, const vector<int> &B) {
	if (A[0] == -1 && B[0] == -1)return true;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] != B[i])return false;
	}
	return true;
}
int cnt(const vector<vector<int> > &_S) {
	vector<int> V(_S.size(), 1);
	for (int i = 0; i < _S.size(); i++) {
		S[2 * i] = _S[i];
		int t = 0;
		for (int j = 0; j < 26; j++) {
			t += (_S[i][j] & 1);
		}
		if (t > 1) {
			V[i] = 0;
			S[2 * i][0] = 100000 + i;
		}
	}
	//cerr << _S.size() << endl;
	vector<int> R(S.size(), 0);
	{
		int i = 0, j = 0;
		while (i < S.size()) {
			while (i - j >= 0 && i + j < S.size() && EQ(S[i - j], S[i + j])) ++j;
			R[i] = j;
			int k = 1;
			while (i - k >= 0 && i + k < S.size() && k + R[i - k] < j) R[i + k] = R[i - k], ++k;
			i += k; j -= k;
		}
	}
	int res = 0;
	for (int i = 0; i < R.size(); i++) {
		if (i % 2 == 0 && V[i / 2] == 0) {
			continue;
		}
		res += (R[i] + 1-(i%2)) / 2;
	}
	return res;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	S.resize(2 * N - 1, vector<int>(26, -1));
	vector<vector<int> > A(N, vector<int>(M));
	int res = 0;
	string T;
	for (int i = 0; i < N; i++) {
		cin >> T;
		//T = string(M, 'a');
		for (int j = 0; j < M; j++) {
			A[i][j] = T[j] - 'a';
		}
	}
	for (int i = 0; i < M; i++) {
		vector<vector<int> > X(N, vector<int>(26, 0));
		for (int j = i; j < M; j++) {
			for (int k = 0; k < N; k++) {
				X[k][A[k][j]]++;
			}
			res += cnt(X);
		}
	}
	cout << res << endl;
}