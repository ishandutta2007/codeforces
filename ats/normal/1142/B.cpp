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
vector<vector<int> > g;
vector<int> S;
vector<int> R;
int N, M, Q;
int dfs(int a) {
	S.push_back(a);

	R[a] = S[max((int)0, (int)S.size() - (N))];
	for (int i : g[a]) {
		dfs(i);
	}
	S.pop_back();
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N >> M >> Q;
	vector<int> A(N);
	vector<int> ne(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		A[i]--;
	}
	for (int i = 0; i < N; i++) {
		ne[A[i]] = A[(i + 1) % N];
	}
	vector<int> B(M);
	for (int i = 0; i < M; i++) {
		cin >> B[i]; B[i]--;
	}
	vector<int> pos(N, M);
	g.resize(M + 1);
	R.resize(M + 1);
	for (int i = M - 1; i >= 0; i--) {
		g[pos[ne[B[i]]]].push_back(i);
		pos[B[i]] = i;
	}

	dfs(M);

	


	for (int i = M - 1; i >= 0; i--) {
		R[i] = min(R[i], R[i + 1]);
	}

	string res;

	int l, r;
	for (int i = 0; i < Q; i++) {
		cin >> l >> r;
		l--; r--;
		if (R[l] <= r) {
			res.push_back('1');
		}
		else {
			res.push_back('0');
		}
	}

	/*for (int i = 0; i < M; i++) {
		cerr << R[i] << " ";
	}
	cerr << endl;*/

	cout << res << endl;
}