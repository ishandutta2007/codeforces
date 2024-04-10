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
int MOD = 998244353;
void add(int &a, const int &b) {
	a += b;
	if (a >= MOD)a -= MOD;
}
int dp[1000][1000];
int solve(const vector<int> &X, int l, int r) {
	if (l >= r)return 1;
	if (dp[l][r] == -1) {
		int mn = 10000000;
		int p = -1;
		for (int i = l; i <= r; i++) {
			if (mn > X[i]) {
				mn = X[i];
				p = i;
			}
		}
		int L = 0;
		for (int i = l; i <= p; i++) {
			L += (solve(X, l, i - 1) * solve(X, i, p - 1)) % MOD;
		}
		L %= MOD;
		int R = 0;
		for (int i = p; i <= r; i++) {
			R += (solve(X, p + 1, i) * solve(X, i + 1, r)) % MOD;
		}
		R %= MOD;
		dp[l][r] = (L * R) % MOD;
		//cerr << l << " " << r << " "<<dp[l][r] << endl;
	}
	return dp[l][r];
}

int solve(const vector<int> &X) {
	for (int i = 0; i < X.size(); i++) {
		for (int j = 0; j < X.size(); j++) {
			dp[i][j] = -1;
		}
	}
	return solve(X, 0, (int)X.size() - 1);
}
vector<int> A;

vector<vector<int> > T;
bool ok = true;
int rec(int l, int r, int mn) {
	if (l > r)return 1;
	vector<int> X;
	int res = 1;
	for (int i = l; i <= r; i++) {
		if (T[A[i]][0] != i)return 0;
		if (A[i] <= mn)return 0;
		for (int k = 1; k < T[A[i]].size(); k++) {
			res = (res * rec(T[A[i]][k - 1] + 1, T[A[i]][k] - 1, A[i])) % MOD;
		}
		X.push_back(A[i]);
		i = T[A[i]].back();
		if (i > r)return 0;
	}

	res = (res * solve(X)) % MOD;
	return res;

}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	A.resize(M);
	for (int i = 0; i < M; i++) {
		cin >> A[i]; A[i]--;
	}
	T.resize(N);
	for (int i = 0; i < M; i++) {
		T[A[i]].push_back(i);
	}




	cout << rec(0, M - 1, -1) << endl;


}