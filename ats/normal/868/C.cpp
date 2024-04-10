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
	int N, K;
	cin >> N >> K;
	vector<int> A(N, 0);
	int a;
	bool f = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			cin >> a;
			A[i] *= 2;
			A[i] += a;
		}
		if (A[i] == 0) {
			f = true;
		}
	}
	set<int> st;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < (1 << (K)); j++) {
			if ((A[i] & j) == 0) {
				if (st.count(j) != 0) {
					f = true;
				}
			}
		}
		st.insert(A[i]);
	}
	if (f) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}