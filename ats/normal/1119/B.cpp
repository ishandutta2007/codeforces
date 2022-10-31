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
	int N, H;
	cin >> N >> H;
	vector<int> A(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 1; i <= N; i++) {
		vector<int> B;

		for (int j = 0; j < i; j++) {
			B.push_back(A[j]);
		}
		sort(B.rbegin(), B.rend());
		int h = 0;
		for (int j = 0; j < B.size(); j+= 2) {
			h += B[j];
		}
		if (h <= H)res = i;

	}




	cout << res << endl;
}