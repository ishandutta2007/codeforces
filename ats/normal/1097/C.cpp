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
	vector<string> A(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	map<int, int> mp;
	int c;
	for (int i = 0; i < N; i++) {
		c = 0;
		for (int j = 0; j < A[i].size(); j++) {
			if (A[i][j] == '(')c++;
			else c--;
		}
		if (c >= 0) {
			c = 0;
			bool ok = true;
			for (int j = 0; j < A[i].size(); j++) {
				if (A[i][j] == '(')c++;
				else c--;
				if (c < 0)ok = false;
			}
			if (ok)mp[c]++;
		}
		else {
			c = 0;
			bool ok = true;
			for (int j = (int)A[i].size() - 1; j >= 0; j--) {
				if (A[i][j] == ')')c++;
				else c--;
				if (c < 0)ok = false;
			}
			if (ok)mp[-c]++;
		}
	}
	
	for (auto x : mp) {
		if (x.first >= 0) {
			if (x.first == 0) {
				res += x.second / 2;
			}
			else {
				res += min(x.second, mp[-x.first]);
			}
		}
	}
	cout << res << endl;
}