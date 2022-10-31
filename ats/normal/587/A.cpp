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
	vector<int> A(1000500, 0);
	int res = 0;
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		A[a]++;
	}
	for (int i = 0; i < A.size(); i++) {
		if (A[i] > 0) {
			A[i + 1] += A[i] / 2;
		}
		if (A[i] % 2 == 1) {
			res++;
		}
	}
	cout << res << endl;
}