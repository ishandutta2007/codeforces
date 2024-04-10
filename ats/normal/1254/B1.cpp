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
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sum += A[i];
	}
	if (sum == 1) {
		cout << -1 << endl;
		return 0;
	}
	vector<int> X;

	int B = sum;
	for (int i = 2; i*i <= B; i++) {
		if (B % i == 0) {
			X.push_back(i);
			B /= i;
			while (B % i == 0)B /= i;
		}
	}
	if (B > 1) {
		X.push_back(B);
	}
	int res = (int)1 << 60;
	vector<int> C;
	for (const int &x : X) {
		int tmp = 0;
		int l = 0;
		int ans = 0;
		C = A;
		//cerr << "x = " << x << endl;
		for (int i = 0; i < N; i++) {
			C[i] = A[i] % x;
		}
		for (int i = 0; i < N; i++) {
			tmp += C[i];
			if (tmp >= x) {
				int n = tmp - x;
				C[i] = (C[i] - n) % x;
				int c = 0;
				int m;
				/*for (int j = l; j <= i; j++) {
					cerr << C[j] << " ";
				}
				cerr << endl;*/
				for (int j = l; j <= i; j++) {
					c += C[j];
					if (c * 2 >= x) {
						m = j;
						break;
					}
				}
				
				for (int j = l; j <= m; j++) {
					ans += C[j] * (m - j);
				}
				for (int j = m; j <= i; j++) {
					ans += C[j] * (j - m);
				}
				C[i] = n;
				tmp = n;
				l = i;
				if (C[l] == 0)l++;
				//tmp = 0;
			}
		}
		//cerr << x << " " << ans << endl;
		res = min(res, ans);
	}
	

	cout << res << endl;
}