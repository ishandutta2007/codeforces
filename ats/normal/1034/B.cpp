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
	int N, M;
	cin >> N >> M;
	if (N > M)swap(N, M);
	int res = 0;
	if (N == 1) {
		int a[6] = { 0,1,2,3,2,1 };
		res = M - a[M % 6];
	}
	else if (N == 2) {
		if (M == 2)res = 0;
		else if (M == 3)res = 4;
		else if (M == 7)res = 12;
		else {
			res = N*M;
		}
	}
	else if (N == 3) {
		if (M % 2 == 1)res = N*M - 1;
		else {
			res = N*M;
		}
	}
	else {
		res = ((N*M) / 2) * 2;
	}
	cout << res << endl;
}