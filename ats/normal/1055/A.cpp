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
	int N, S;
	cin >> N >> S;
	vector<int> A(N);
	vector<int> B(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}
	if (A[0] == 1) {
		if (A[S - 1] == 1) {
			cout << "YES" << endl;
			return 0;
		}
		if (B[S - 1] == 1) {
			for (int i = S; i < N; i++) {
				if (A[i] == 1 && B[i] == 1) {
					cout << "YES" << endl;
					return 0;
				}
			}
		}
	}
	cout << "NO" << endl;
}