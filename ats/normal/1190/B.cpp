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
string fi = "sjfnb";
string se = "cslnb";
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> A(N);
	int res = 0;
	set<int> st;
	int du = -1;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sum += A[i];
		if (st.count(A[i]) == 1) {
			du = A[i];
		}
		st.insert(A[i]);
	}

	if ((int)st.size() <= N - 2) {
		cout << se << endl;
		return 0;
	}
	if (du != -1) {
		if (du == 0 || st.count(du - 1) == 1) {
			cout << se << endl;
			return 0;
		}
	}

	for (int i = 0; i < N; i++) {
		sum -= i;
	}
	
	if (sum % 2 == 1) {
		cout << fi << endl;
	}
	else {
		cout << se << endl;
	}
}