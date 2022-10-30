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
	vector<int> B(200, 0);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		B[A[i]]++;
	}
	int k = -1;
	bool f = false;
	for (int i = 0; i < 200; i++) {
		if (B[i] != 0) {
			if (k == -1) {
				k = B[i];
			}
			else {
				if (!f) {
					if (k == B[i]) {
						f = true;
					}
					else {
						f = false;
						break;
					}
				}
				else {
					f = false;
					break;
				}
			}
		}
	}
	if (f) {
		cout << "YES" << endl;
		bool g = false;
		for (int i = 0; i < 200; i++) {
			if (B[i] != 0) {
				if (g)cout << " ";
				cout << i;
				g = true;
			}
		}
	}
	else {
		cout << "NO" << endl;
	}
}