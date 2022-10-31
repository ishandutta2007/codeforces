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
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int Q;
	cin >> Q;
	vector<int> L(Q);
	vector<int> R(Q);

	set<int> st;
	vector<int> X;
	for (int i = 0; i < Q; i++) {
		cin >> L[i] >> R[i];
		st.insert(R[i] - L[i] + 1);
	}

	for (auto s : st) {
		X.push_back(s);
	}
	int INF = 4 * 1e9 * 1e9;
	//cerr << INF << endl;
	A.push_back(INF);
	vector<int> sum1(X.size() + 1, 0);
	vector<int> sum0(X.size() + 1, 0);
	for (int i = 0; i < N; i++) {
		int d = A[i + 1] - A[i];

		int idx = upper_bound(X.begin(), X.end(), d) - X.begin();
		//cerr << d << " " << idx << endl;
		sum1[0]++;
		sum1[idx]--;
		sum0[idx] += d;
		sum0[X.size()] -= d;
	}
	map<int, int> mp; 
	for (int i = 0; i < X.size(); i++) {
		if (i > 0) {
			sum1[i] += sum1[i - 1];
			sum0[i] += sum0[i - 1];
		}
		mp[X[i]] = sum1[i] * X[i] + sum0[i];
	}
	vector<int> res(Q);
	for (int i = 0; i < Q; i++) {
		res[i] = mp[R[i] - L[i] + 1];
	}
	for (int i = 0; i < Q; i++) {
		if (i > 0)cout << " ";
		cout << res[i];
	}
	cout << endl;
}