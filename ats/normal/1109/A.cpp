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
	vector<int> B(N + 1);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	B[0] = 0;
	vector<map<int, int> >mp(2);

	mp[0][0]++;

	for (int i = 0; i < N; i++) {
		B[i + 1] = B[i] ^ A[i];

		res += mp[(i + 1) % 2][B[i + 1]];

		mp[(i + 1) % 2][B[i + 1]]++;
	}


	cout << res << endl;
}