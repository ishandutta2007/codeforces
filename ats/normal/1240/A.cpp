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
	int t;
	cin >> t;
	while (t--) {
		int N;
		cin >> N;
		vector<int> P(N);
		int res = 0;
		for (int i = 0; i < N; i++) {
			cin >> P[i];
		}
		int X, A;
		cin >> X >> A;
		int Y, B;
		cin >> Y >> B;
		if (X > Y) {
			swap(X, Y);
			swap(A, B);
		}
		int K;
		cin >> K;
		sort(P.rbegin(), P.rend());
		vector<int> sum(N + 1, 0);
		for (int i = 0; i < N; i++) {
			sum[i + 1] = sum[i] + P[i];
		}
		int ab = 0;
		int b = 0;
		int a = 0;
		res = -1;
		for (int i = 0; i < N; i++) {
			if ((i + 1) % A == 0 && (i + 1) % B == 0) {
				ab++;
			}
			else if ((i + 1) % B == 0) {
				b++;
			}
			else if ((i + 1) % A == 0) {
				a++;
			}
			int x = 0;
			x += sum[ab] * (X + Y);
			x += (sum[ab + b] - sum[ab]) * Y;
			x += (sum[ab + b + a] - sum[ab + b]) * X;
			//cerr << i << " " << x << endl;
			if (x >= K * 100) {
				res = i + 1;
				break;
			}
		}


		cout << res << endl;
	}
}