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
	S = S + S;
	int N = S.size();
	int a = 1;
	int res = 1;
	for (int i = 1; i < N; i++) {
		if (S[i] != S[i - 1]) {
			a++;
			res = max(res, a);
		}
		else {
			a = 1;
		}
	}
	cout << min(res, N / 2) << endl;
}