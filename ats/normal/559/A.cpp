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
int solve(int a) {
	return a * a;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int A[6];
	for (int i = 0; i < 6; i++) {
		cin >> A[i];
	}
	
	cout << solve(A[0] + A[4] + A[5]) - solve(A[0]) - solve(A[2]) - solve(A[4]) << endl;
}