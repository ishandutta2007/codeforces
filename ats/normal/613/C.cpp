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
int gcd(int a, int b) {
	return b != 0 ? gcd(b, a % b) : a;
}
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
	string res;
	int t = 0;
	if (N == 1) {
		t = A[0];
		for (int i = 0; i < A[0]; i++) {
			res.push_back('a');
		}
	}
	else {
		int K = 0;
		while (true) {
			bool ok = true;
			for (int i = 0; i < N; i++) {
				if ((A[i] % (1 << (K + 1))) != 0) {
					ok = false;
				}
			}
			if (!ok)break;
			K++;
		}

		if (K == 0) {
			int c = 0;
			int oi = -1;
			for (int i = 0; i < N; i++) {
				if (A[i] % 2 != 0) {
					c++;
					oi = i;
				}
			}
			if (c >= 2) {
				t = 0;
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < A[i]; j++) {
						res.push_back('a' + i);
					}
				}
			}
			else {

				string x;
				int g = 0;
				for (int i = 0; i < N; i++) {
					g = gcd(A[i], g);
				}
				t = g;
				for (int i = 0; i < N; i++) {
					if (i != oi) {
						for (int j = 0; j < A[i] / (2 * g); j++) {
							x.push_back('a' + i);
						}
					}
				}
				{
					for (int j = 0; j < A[oi] / g; j++) {
						x.push_back('a' + oi);
					}
				}
				for (int i = N - 1; i >= 0; i--) {
					if (i != oi) {
						for (int j = 0; j < A[i] / (2 * g); j++) {
							x.push_back('a' + i);
						}
					}
				}
				res = "";
				for (int i = 0; i < g; i++) {
					res += x;
				}

			}
		}
		else {
			string x;
			int g = 0;
			for (int i = 0; i < N; i++) {
				g = gcd(A[i], g);
			}
			t = g;
			res = "";
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < (A[i] / g); j++) {
					x.push_back('a' + i);
				}
			}
			for (int i = N - 1; i >= 0; i--) {
				for (int j = 0; j < (A[i] / g); j++) {
					x.push_back('a' + i);
				}
			}

			for (int j = 0; j < (g / 2); j++) {
				res += x;
			}


		}
	}
	cout << t << endl;
	cout << res << endl;
}