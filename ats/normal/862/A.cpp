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
	int N, X;
	cin >> N >> X;
	vector<int> A(N);
	int res = 0;
	set<int> st;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		st.insert(A[i]);
	}
	for (int i = 0; i < 10000; i++) {
		if (X == i) {
			if (st.count(i) == 0) {
			}
			else {
				res++;
			}
			break;
		}
		else {
			if (st.count(i) == 0) {
				res++;
			}
		}
	}
	cout << res << endl;
}