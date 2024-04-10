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
	int a, b, m;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> m;
		if (a == b) {
			cout << 1 << " " << a << endl;
			continue;
		}
		bool ok = false;
		for (int t = 0; t < 60; t++) {
			int low = (a + 1) * ((int)1 << t);
			if (low > b)break;

			int high = (a + m) * ((int)1 << t);
			if (b <= high) {
				int r = b - (a + 1) * ((int)1 << t);
				vector<int> X(t + 1, 1);
				for (int tt = t - 1; tt >= 0; tt--) {
					int add = min(m - 1, (r / ((int)1 << tt)));
					X[tt + 1] = 1 + add;
					r -= add * ((int)1 << tt);
				}
				{
					int tt = 0;

					int add = min(m - 1, r);
					X[0] = 1 + add;
					r -= add;

				}
				reverse(X.begin(), X.end());

				int sum = 0;
				vector<int>res(t + 2);
				res[0] = a; sum = a;
				for (int j = 1; j <= t + 1; j++) {
					res[j] = sum + X[j - 1];
					sum += res[j];
				}
			
				cout << res.size();
				for (int j = 0; j < res.size(); j++) {
					cout << " " << res[j];
				}
				cout << endl;
				ok = true;
				break;
			}
		}
		if (!ok) {
			cout << -1 << endl;
		}



	}
}