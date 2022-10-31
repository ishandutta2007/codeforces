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
	string S;
	cin >> S;
	int c = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == '(')c++;
		else c--;
		if (c < 0) {
			S.erase(S.begin() + i);
			S.push_back(')');
			break;
		}
	}
	string res = "Yes";
	c = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == '(')c++;
		else c--;
		if (c < 0) {
			res = "No";
		}
	}
	if (c != 0) {
		res = "No";
	}





	cout << res << endl;
}