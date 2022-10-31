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
	int N, T;
	cin >> N >> T;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	vector<int> X(N);
	string res = "Yes";
	vector<int> mx(N, (int)1 << 61);
	vector<int> mn(N, -1);
	int cur = 0;
	for (int i = 0; i < N; i++) {
		cin >> B[i];
		B[i]--;
		if (B[i] < i) {
			res = "No";
			break;
		}
		cur = max(cur, i);
		while (cur < B[i] && cur < N - 1) {
			mn[cur] = max(mn[cur], A[cur + 1] + T);
			//cerr << i << " " << cur << endl;
			cur++;

		}

		mn[B[i]] = max(mn[B[i]], A[i] + T);
		if (B[i] + 1 < N)mx[B[i]] = min(mx[B[i]], A[B[i] + 1] + T - 1);
	}
	if (B[N - 1] != N - 1) {
		res = "No";
	}
	if (res == "No") {
		cout << res << endl;
		return 0;
	}

	vector<int> ans(N);
	ans[0] = mn[0];
	if (ans[0] > mx[0])res = "No";
	for (int i = 1; i < N; i++) {
		ans[i] = max(ans[i - 1] + 1, mn[i]);
		if (ans[i] > mx[i])res = "No";
	}

	for (int i = 0; i < N; i++) {
		cerr << ans[i] << " ";
	}
	cerr << endl;
	if (res == "No") {
		cout << res << endl;
		return 0;
	}
	cout << res << endl;
	for (int i = 0; i < N; i++) {
		if (i > 0)cout << " ";
		cout << ans[i];
	}
	cout << endl;
}