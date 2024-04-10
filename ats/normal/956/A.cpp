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
	vector<string> A(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	bool ok = true;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (A[i] != A[j]) {
				for (int k = 0; k < M; k++) {
					if (A[i][k] == '#' && A[j][k] == '#') {
						ok = false;
					}
				}
			}
		}
	}
	if (ok) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO"  << endl;
	}
}