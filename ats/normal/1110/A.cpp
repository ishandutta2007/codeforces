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
	int K, N;
	cin >> K >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	string res;
	if (K % 2 == 0) {
		if (A.back() % 2 == 0) {
			res = "even";
		}
		else {
			res = "odd";
		}
	}
	else {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += A[i];
		}
		if (sum % 2 == 0) {
			res = "even";
		}
		else {
			res = "odd";
		}
	}
	cout << res << endl;
}