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
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sum += A[i];
	}
	sort(A.begin(), A.end());
	if (sum * 2 >= 9 * N) {
		res = 0;
	}
	else {
		for (int i = 0; i < N; i++) {
			sum += 5 - A[i];
			//cerr << sum << endl;
			if (sum * 2 >= 9 * N) {
				res = i + 1;
				break;
			}
		}
	}
	cout << res << endl;
}