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
	vector<int> B(N);
	int res = 0;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sum += A[i];
	}
	B[N - 1] = A[N - 1] + 1;
	for (int i = N - 2; i >= 0; i--) {
		B[i] = max(B[i + 1] - 1, A[i] + 1);
	}
	int s2 = B[0];
	for (int i = 1; i < N; i++) {
		B[i] = max(B[i], B[i - 1]);
		s2 += B[i];
		//cerr << B[i] << " ";
	}
	//crr << endl;
	cout << s2 - sum - N << endl;
}