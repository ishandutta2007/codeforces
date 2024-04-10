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
	int N, M;
	cin >> N >> M;
	vector<int> A(2 * N);
	vector<int> X(2 * N, 0);
	for (int i = 0; i < 2 * N; i++) {
		cin >> A[i];
	}
	int a, b;
	vector<int> P(2 * N, -1);
	for (int i = 0; i < M; i++) {
		cin >> a >> b; a--; b--;
		P[a] = b;
		P[b] = a;
	}
	int turn;
	cin >> turn;
	int ans;
	b = -1;
	for (int i = 0; i < 2 * N; i++) {
		if (turn == 1) {
			if (b != -1 && P[b] != -1 && X[P[b]] == 0) {
				ans = P[b];
			}
			else {
				int mx = -1e9;
				int mxj = -1;
				for (int j = 0; j < 2 * N; j++) {
					if (X[j] == 0) {
						if (P[j] != -1) {
							if (mx < A[j] - A[P[j]]) {
								mx = A[j] - A[P[j]];
								mxj = j;
							}
						}
					}
				}
				if (mxj != -1) {
					//cerr << "mx = " << mx << endl;
					ans = mxj;
				}
				else {
					for (int j = 0; j < 2 * N; j++) {
						if (X[j] == 0) {
							if (mx < A[j]) {
								mx = A[j];
								mxj = j;
							}
						}
					}
					//cerr << "mx2 = " << mx << endl;
					ans = mxj;
				}
			}
			cout <<  ans + 1 << endl << flush;
			X[ans] = 1;
			turn = 2;
		}
		else {
			cin >> a; a--;
			X[a] = 1;
			b = a;
			turn = 1;
		}
	}
}