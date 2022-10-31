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
string removeZeros(string T) {
	reverse(T.begin(), T.end());
	while ((int)T.size() > 0 && T.back() == '0')T.pop_back();
	reverse(T.begin(), T.end());
	return T;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string S;
	cin >> S;
	int res = 0;
	for (int i = 0; i < S.size(); i++) {
		res = max(res, (int)(S[i] - '0'));
	}
	vector<string> X(res, string(S.size(), '0'));
	for (int i = 0; i < res; i++) {
		for (int j = 0; j < S.size(); j++) {
			if (i < (int)(S[j] - '0')) {
				X[i][j] = '1';
			}
		}
	}
	cout << res << endl;
	for (int i = 0; i < res; i++) {
		if (i > 0)cout << " ";
		cout << removeZeros(X[i]);
	}
	cout << endl;
}