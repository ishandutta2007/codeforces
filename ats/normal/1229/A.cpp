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
	vector<int> B(N);
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}

	map<int, int> mp;
	for (int i = 0; i < N; i++) {
		mp[A[i]]++;
	}
	bool ok = false;
	int a = 0;
	vector<int> X;
	for (int i = 0; i < N; i++) {
		if (mp[A[i]] > 1) {
			ok = true;
			X.push_back(A[i]);
		}
	}
	int res = 0;
	if (ok) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < X.size(); j++) {
				if ((X[j] & A[i]) == A[i]) {
					res += B[i];
					break;
				}
			}
		}
	}
	cout << res << endl;
}