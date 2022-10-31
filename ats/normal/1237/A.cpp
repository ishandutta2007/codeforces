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
	vector<int> res;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int a = 1;
	for (int i = 0; i < N; i++) {
		if (A[i] % 2 == 0) {
			res.push_back(A[i] / 2);
		}
		else {
			res.push_back((A[i] + a) / 2);
			a *= -1;
		}
	}
	for (int i = 0; i < N; i++) {
		cout << res[i] << endl;
	}
}