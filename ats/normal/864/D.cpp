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
	vector<int> C(N, 0);
	vector<int> B(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		A[i]--;
		C[A[i]]++;
	}
	int res = 0;
	int st = 0;
	for (int i = 0; i < N; i++) {
		if (C[A[i]] > 1) {
			
			while (true) {
				if (C[st] == 0)break;
				st++;
				if (st == N) break;
			}
			if (A[i] > st || (B[A[i]] == 1)) {
				C[A[i]]--;
				A[i] = st;
				C[st]++;
				res++;
			}
			else {
				B[A[i]] = 1;
			}
		}
	}
	cout << res << endl;
	for (int i = 0; i < N; i++) {
		if (i > 0)cout << " ";
		cout << A[i] + 1;
	}
	cout << endl;
}