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
	int N;
	cin >> N;
	vector<vector<int> > A(N,vector<int>(N));
	vector<int> res;
	for (int i = 0; i < N; i++) {
		set<int> st;
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
			st.insert(A[i][j]);
		}
		if (st.size() == N) {
			res = A[i];
			res[i] = N;
		}
	}
	for (int i = 0; i < N; i++) {
		if (i > 0)cout << " ";
		cout << res[i];
	}
	cout << endl;
}