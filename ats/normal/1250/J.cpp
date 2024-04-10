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
	vector<int> A(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int ok = M;
	int ng = -1;
	while (ok - ng > 1) {
		int m = (ok + ng) / 2;
		int mn = 0;
		bool f = true;
		for (int i = 0; i < N; i++) {
			if (A[i] <= mn && mn <= A[i] + m) {

			}
			else if (A[i] <= mn + M && mn + M <= A[i] + m) {

			}
			else if(A[i] + m < mn){
				f = false;
				break;
			}
			else {
				mn = A[i];
			}
		}
		if (f) {
			ok = m;
		}
		else {
			ng = m;
		}
	}


	cout << ok << endl;
}