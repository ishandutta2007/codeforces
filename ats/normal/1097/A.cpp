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
	string X;
	cin >> X;
	int N = 5;
	vector<string> A(N);
	string res = "NO";
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (A[i][0] == X[0] || A[i][1] == X[1]) {
			res = "YES";
		}
	}

	cout << res << endl;
}