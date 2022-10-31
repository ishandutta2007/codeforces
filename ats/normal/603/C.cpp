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
vector<int> X;
int K;
int g(int a) {
	if (a < (int)X.size())return X[a];
	if (a % 2 == 1)return 0;

	int g2;
	if (K % 2 == 1) {
		g2 = g(a / 2);
	}
	else {
		g2 = 0;
	}
	if (g2 == 0 || g2 == 2)return 1;

	return 2;

}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N >> K;
	vector<int> A(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}


	X.resize(1000);
	X[0] = 0;
	for (int i = 1; i < X.size(); i++) {
		set<int>st;
		st.insert(X[i - 1]);
		if (K % 2 == 1) {
			if (i % 2 == 0)st.insert(X[i / 2]);
		}
		else {
			if (i % 2 == 0)st.insert(0);
		}
		for (int j = 0; j < 3; j++) {
			if (st.count(j) == 0) {
				X[i] = j;
				break;
			}
		}
	}
	int gr = 0;
	for (int i = 0; i < N; i++) {
		gr ^= g(A[i]);
	}

	if (gr == 0) {
		cout << "Nicky" << endl;
	}
	else {
		cout << "Kevin" << endl;
	}

}