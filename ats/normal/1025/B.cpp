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
int gcd(int a, int b)
{
	int c;
	while (a != 0) {
		c = a; a = b%a;  b = c;
	}
	return b;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
	}
	int g = A[0] * B[0];
	for (int i = 1; i < N; i++) {
		g = gcd(g, A[i] * B[i]);
	}
	//cerr << g << endl;
	int res = -1;
	
	if (res == -1) {
		for (int i = 2; i*i <= A[0]; i++) {
			if (A[0] % i == 0) {
				if (g%i == 0) {
					res = i;
					break;
				}
				while (A[0] % i == 0)A[0] /= i;
			}
		}
		if (res == -1) {
			if (A[0] != 1) {
				if (g % A[0] == 0) {
					res = A[0];
				}
			}
		}
	}
	if (res == -1) {
		for (int i = 2; i*i <= B[0]; i++) {
			if (B[0] % i == 0) {
				if (g%i == 0) {
					res = i;
					break;
				}
				while (B[0] % i == 0)B[0] /= i;
			}
		}
		if (res == -1) {
			if (B[0] != 1) {
				if (g % B[0] == 0) {
					res = B[0];
				}
			}
		}
	}

	cout << res << endl;
}