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
char X[5] = { 'a','e','i','o','u' };
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		if (N % i == 0) {
			int j = N / i;
			if (i >= 5 && j >= 5) {
				string S;
				for (int x = 0; x < N; x++) {
					int ii = x % i;
					int jj = x / i;
					S.push_back(X[(ii + jj) % 5]);
				}
				cout << S << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
}