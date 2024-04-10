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
bool solve(string S, string T) {
	if (S == T)return true;
	if (S.size() % 2 == 1) return false;
	int N = S.size();
	return  (solve(S.substr(0, N / 2), T.substr(0, N / 2)) && solve(S.substr(N / 2, N / 2), T.substr(N / 2, N / 2)))
		|| (solve(S.substr(N / 2, N / 2), T.substr(0, N / 2)) && solve(S.substr(0, N / 2), T.substr(N / 2, N / 2)));
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string S, T;
	cin >> S >> T;
	if (solve(S, T)) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}