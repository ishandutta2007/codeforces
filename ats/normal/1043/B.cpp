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
	vector<int> A(N + 1, 0);
	vector<int> B(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> A[i + 1];
	}
	for (int i = 0; i < N; i++) {
		B[i] = A[i + 1] - A[i];
	}
	vector<int> res;
	for (int i = 1; i <= N; i++) {
		bool f = true;
		for (int j = 0; j < i; j++) {
			for (int k = j; k < N; k += i) {
				if (B[k] != B[j])f = false;
			}
		}
		if (f) {
			res.push_back(i);
		}
	}
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		if (i > 0)cout << " ";
		cout << res[i];
	}
	cout << endl;
}