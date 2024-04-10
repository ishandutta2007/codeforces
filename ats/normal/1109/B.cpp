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
int N;
bool check(string &T) {
	for (int i = 0; i < N / 2; i++) {
		if (T[i] != T[N - 1 - i])return false;
	}
	return true;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	string S;
	cin >> S;
	N = S.size();
	bool ok = false;

	for (int i = 0; i < N / 2; i++) {
		if (S[i] != S[0])ok = true;
	}
	int res = -1;
	if (ok) {
		res = 2;
		for (int i = 1; i < N; i++) {
			string T;
			for (int k = 0; k < N; k++) {
				T += S[(k + i) % N];
			}
			if (T != S) {
				if (check(T)) {
					res = 1;
					break;
				}
			}
		}


	}
	if (res == -1) {
		cout << "Impossible" << endl;
	}
	else {
		cout << res << endl;
	}
}