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
	int a = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == '8') {
			a++;
		}
	}
	int res = -1;
	for (int i = 0; i <= a; i++) {
		res = max(res, min(i, (N - i) / 10));
	}
	cout << res << endl;
}