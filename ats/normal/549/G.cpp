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
	set<int> st;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		st.insert(A[i] + i);
	}
	if ((int)st.size() != N) {
		cout << ":(" << endl;
	}
	else {
		int i = 0;
		for (auto s : st) {
			if (i > 0)cout << " ";
			cout << s - i;
			i++;
		}
		cout << endl;
	}
}