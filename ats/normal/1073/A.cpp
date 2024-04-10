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
	for (int i = 0; i < N - 1; i++) {
		if (S[i] != S[i + 1]) {
			cout << "YES" << endl;
			cout << S[i] << S[i + 1] << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}