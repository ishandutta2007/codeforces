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
	int M, N;
	cin >> M >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cout << 1 << endl;
		cout << flush;
		int a;
		cin >> a;
		if (a == 0) {
			return 0;
		}
		A[i] = a;
	}
	int mx = M + 1;
	int mn = 1;
	int k = 0;
	while (true) {
		int m = (mx + mn)/2;
		cout << m << endl;
		cout << flush;
		int a;
		cin >> a;
		if (a == 0) {
			return 0;
		}
		if (a == 1) {
			if (A[k] == 1) {
				mn = m;
			}
			else {
				mx = m;
			}
		}
		else {
			if (A[k] == 1) {
				mx = m;
			}
			else {
				mn = m;
			}
		}
		k++;
		k %= N;
	}
}