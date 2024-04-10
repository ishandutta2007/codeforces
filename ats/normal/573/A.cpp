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
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		while (A[i] % 2 == 0)A[i] /= 2;
		while (A[i] % 3 == 0)A[i] /= 3;
	}
	for (int i = 0; i < N; i++) {
		if (A[i] != A[0]) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}