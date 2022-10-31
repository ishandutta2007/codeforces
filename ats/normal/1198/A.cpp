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
	int N, X;
	cin >> N >> X;
	map<int, int> mp;
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		mp[a]++;
	}


	vector<int> A;
	for (auto m : mp) {
		A.push_back(m.second);
	}

	int b = (X * 8) / N;
	X = 1;
	for (int i = 0; i < b; i++) {
		X *= 2;
		if (X >= (int)A.size())break;
	}
	if (X >= (int)A.size()) {
		cout << 0 << endl;
		return 0;
	}
	
	int res = N;
	int sum = 0;
	for (int i = 0; i < X; i++) {
		sum += A[i];
	}
	res = N - sum;
	//cerr << N - sum << endl;
	for (int i = X; i < A.size(); i++) {
		sum += A[i];
		sum -= A[i - X];
		//cerr << N - sum << endl;

		res = min(res, N - sum);
	}


	cout << res << endl;
}