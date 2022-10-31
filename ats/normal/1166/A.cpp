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
	vector<int> A(26, 0);
	int res = 0;
	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;
		A[S[0] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		int k = A[i] / 2;

		res += (k * (k - 1)) / 2;


		k = A[i] - k;
		res += (k * (k - 1)) / 2;

	}
	cout << res << endl;
}