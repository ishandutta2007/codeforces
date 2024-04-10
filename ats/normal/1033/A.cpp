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
	int A[3][2];
	int N;
	cin >> N;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> A[i][j];
		}
	}
	string res;
	if ((A[0][0] < A[1][0]) == (A[0][0] < A[2][0])) {
		if ((A[0][1] < A[1][1]) == (A[0][1] < A[2][1])) {
			res = "YES";
		}
		else {
			res = "NO";
		}
	}
	else {
		res = "NO";
	}
	cout << res << endl;
}