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
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}

	vector<int> AA;
	vector<int> BB;
	for (int i = 0; i < N - 1; i++) {
		AA.push_back(A[i + 1] - A[i]);
		BB.push_back(B[i + 1] - B[i]);
	}
	sort(AA.begin(), AA.end());
	sort(BB.begin(), BB.end());
	if (AA == BB && A[0] == B[0]) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}