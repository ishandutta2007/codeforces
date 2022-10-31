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
	string S;
	cin >> S;
	int N = S.size();
	int l = 0;
	int r = N - 1;
	int c = 0;
	int res = N;
	while (l < N) {
		if (c == 0) {
			if (S[l] == '[') {
				c++;
			}
			else {
				res--;
			}
		}else if (c == 1) {
			if (S[l] == ':') {
				c++;
				break;
			}
			else {
				res--;
			}
			
		}
		l++;
	}
	c = 0;
	while (r >= 0) {
		if (c == 0) {
			if (S[r] == ']') {
				c++;
			}
			else {
				res--;
			}
		}
		else if (c == 1) {
			if (S[r] == ':') {
				c++;
				break;
			}
			else {
				res--;
			}
			
		}
		r--;
	}
	//cerr << l << " " << r << endl;
	if (l < r) {
		for (int i = l + 1; i < r; i++) {
			if (S[i] != '|')res--;
		}
	}
	else {
		res = -1;
	}
	cout << res << endl;
}