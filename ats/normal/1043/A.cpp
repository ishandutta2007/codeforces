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
	int mx = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		mx = max(mx, A[i]);
	}
	for (int i = mx; i <= 10000; i++) {
		int a = 0;
		int b = 0;
		for (int j = 0; j < N; j++) {
			a += A[j];
			b += i - A[j];
		}
		if (a < b) {
			cout << i << endl;
			return 0;
		}
	}
}