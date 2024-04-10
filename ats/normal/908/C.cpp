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
	int N, R;
	cin >> N >> R;
	vector<int> A(N);
	vector<double>  mx(1001, R);
	vector<double> res;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	double t;
	double t2;
	for (int i = 0; i < N; i++) {
		res.push_back(mx[A[i]]);
		t2 = mx[A[i]];
		for (int j = A[i] - 2 * R; j <= A[i] + 2 * R; j++) {
			if (j >= 1 && j <= 1000) {
				t = t2 + sqrt(4 * R * R - (j - A[i]) * (j - A[i]));
				mx[j] = max(mx[j], t);
			}
		}
	}
	for (int i = 0; i < res.size(); i++) {
		if (i > 0)cout << " ";
		cout << setprecision(15) << res[i];
	}
	cout << endl;
}