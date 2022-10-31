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
	vector<int> B(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		A[i]--;
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
		B[i]--;
	}
	vector<int> V(N, 0);
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	int cur = 0;
	for (int i = 0; i < N; i++) {
		while (cur < N && V[B[cur]] == 1) {
			cur++;
		}
		if (A[i] != B[cur]) {
			res++;
		}
		V[A[i]] = 1;
	}
	cout << res << endl;
}