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
	vector<int> A(2 * N);
	int res = 0;
	for (int i = 0; i < 2 * N; i++) {
		cin >> A[i];
	}
	int k;
	for (int i = 0; i < 2 * N; i++) {
		if (i % 2 == 0) {
			k = A[i];
		}
		else {
			for (int j = i; j < 2 * N; j++) {
				if (A[j] == k) {
					for (int jj = j; jj >= i + 1; jj--) {
						swap(A[jj], A[jj - 1]);
						res++;
					}
				}
			}
		}
	}
	cout << res << endl;
}