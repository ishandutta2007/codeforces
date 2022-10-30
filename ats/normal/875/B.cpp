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
	vector<int> B(N, 0);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		A[i]--;
	}
	cout << 1;
	int l = N;
	for (int i = 0; i < N - 1; i++) {
		B[A[i]] = 1;
		while(l >= 0 && B[l - 1] == 1) {
			l--;
		}
		cout << " " << i + 2 - N + l;
	}
	cout << " " << 1 << endl;
}