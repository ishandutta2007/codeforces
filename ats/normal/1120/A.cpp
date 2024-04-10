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
	int M, K, N, S;
	cin >> M >> K >> N >> S;
	vector<int> C(500001, 0);
	vector<int> A(M);
	int res = 0;
	for (int i = 0; i < M; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < S; i++) {
		int a; cin >> a;
		C[a]++;
	}
	if (S > K) {
		cout << -1 << endl;
		return 0;
	}

	int o = K;

	int rem = M - N * K;
	K += rem;
	int mx = 500000;
	int ok = 0;
	vector<int> X(500001, 0);
	
	for (int i = 0; i < K; i++) {
		X[A[i]]++;
	}
	

	for (int i = 1; i <= mx; i++) {
		if (X[i] >= C[i])ok++;
	}
	int la = -1;
	for (int i = K; i <= M; i++) {
		//cerr << ok << endl;
		if (ok == mx && (i - K) % o == 0) {
			la = i - K;
			break;
		}
		if (i == M)break;
		X[A[i]]++;

		if (X[A[i]] == C[A[i]])ok++;

		if (X[A[i - K]] == C[A[i - K]])ok--;
		X[A[i - K]]--;
	}

	if (la == -1) {
		cout << -1 << endl;
		return 0;
	}
	else {
		cout << rem << endl;
		vector<int> r;
		for (int i = la; i < la + K; i++) {
			if (X[A[i]] > C[A[i]]) {
				r.push_back(i + 1);
				X[A[i]]--;
			}
		}

		for (int i = 0; i < rem; i++) {
			if (i > 0)cout << " ";
			cout << r[i];
		}
		cout << endl;

	}
}