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
	vector<int> B(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}
	int k = -1;
	for (int i = 0; i < N; i++) {
		int l = (i + 1) % N;
		if (B[i] < B[l]) {
			k = l;
		}
	}
	if (k == -1) {
		if (B[0] == 0) {
			cout << "YES" << endl;
			for (int i = 0; i < N; i++) {
				if (i > 0)cout << " ";
				cout << 1;
			}
			cout << endl;
		}
		else {
			cout << "NO" << endl;
		}
		return 0;
	}
	else {
		A[k] = B[k];
		for (int i = k - 1; i != k; i--) {
			if (i == -1)i = N - 1;
			if (i == k)break;
			int r = (i + 1) % N;
			int l = i - 1;
			if (l == -1)l = N - 1;
			int x = (B[l] - B[i]) / A[r];
			while (x * A[r] + B[i] <= B[l])x++;
			A[i] = x * A[r] + B[i];
		}
	}
	cout << "YES" << endl;
	for (int i = 0; i < N; i++) {
		if (i > 0)cout << " ";
		cout << A[i];
	}
	cout << endl;
}