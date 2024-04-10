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
	vector<int> A(N + 2);
	vector<int> B(N + 2);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i + 1];
	}
	A[0] = A[1];
	A[N + 1] = A[N];
	int prev = 0;
	for (int i = 1; i <= N + 1; i++) {
		if (A[i] == A[i - 1]) {

			res = max(res, (i - prev - 1) / 2);
			for (int j = prev; j < i; j++) {
				if (j < prev + ((i - prev) / 2)) {
					B[j] = A[prev];
				}
				else {
					B[j] = A[i];
				}
			}
			prev = i;
		}
	}
	cout << res << endl;
	for (int i = 1; i <= N; i++) {
		if (i > 1)cout << " ";
		cout << B[i];
	}
	cout << endl;


}