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
	}
	int X = (int)2e5;
	cout << N + 1 << endl;
	for (int i = N - 1; i >= 0; i--) {
		int a = ((A[i] + X - 1) / X)*X + i - A[i];
		cout << 1 << " " << i + 1 << " " << a << endl;
		for (int j = 0; j <= i; j++) {
			A[j] += a;
		}
	}
	cout << 2 << " " << N << " " << X << endl;
	for (int i = 0; i < N; i++) {
		A[i] = A[i] % X;
	}
	//for (int i = 0; i < N; i++) {
	//	cerr << A[i] << " ";
	//}
	//cerr << endl;
}