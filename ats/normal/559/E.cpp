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
vector<int> X;
vector<int> B;
vector<int> C;
vector<int> dp;
int M;
const int INF = (int)1 << 60;
int rec(int a) {
	if (a == M - 1)return 0;
	if (dp[a] == -1) {

		
		{
			int mx = a + 1;
			for (int i = a + 1; i <= mx; i++) {
				if (B[i] != -1) {
					int t = lower_bound(X.begin(), X.end(), X[i] + B[i]) - X.begin();
					mx = max(mx, t);
				}
			}
			dp[a] = X[a + 1] - X[a] + rec(mx);
		}
		for (int k = a + 1; k < M; k++) {
			if (B[k] != -1) {
				if (X[a] >= X[k] - B[k]) {
					int mx = k;
					for (int i = a + 1; i <= mx; i++) {
						if (B[i] != -1 && k != i) {
							int t = lower_bound(X.begin(), X.end(), X[i] + B[i]) - X.begin();
							if (mx < t) {
								mx = t;
							}
						}
					}
					//cerr << a << " " << mx << endl;
					dp[a] = min(dp[a], rec(mx));
				}
			}
		}
		return dp[a];
	}
	else {
		return dp[a];
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> L(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> L[i];
	}
	set<int> st;
	for (int i = 0; i < N; i++) {
		st.insert(A[i] - L[i]);
		st.insert(A[i]);
		st.insert(A[i] + L[i]);
	}

	for (auto s : st) {
		X.push_back(s);
	}
	M = X.size();
	B.resize(X.size(), -1);
	C.resize(X.size(), -1);

	dp.resize(X.size(), -1);
	for (int i = 0; i < N; i++) {
		int t = lower_bound(X.begin(), X.end(), A[i]) - X.begin();
		B[t] = L[i];
		for (int j = t - 1; j >= 0 && X[j] >= A[i] - L[i]; j--) {
			C[j] = max(C[j], t);
		}
	}
	/*for (int i = 0; i < C.size(); i++) {
		cerr << B[i] << " ";
	}
	cerr << endl;*/
	cout << X.back() - X[0] - rec(0) << endl;
}