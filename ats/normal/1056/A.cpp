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
	vector<int> B(1000, 0);
	int r;
	int a;
	for (int i = 0; i < N; i++) {
		cin >> r;
		for (int j = 0; j < r; j++) {
			cin >> a;
			B[a]++;
		}
	}
	vector<int> res;
	for (int i = 1; i <= 100; i++) {
	if (B[i] == N)res.push_back(i);
	}
	for (int i = 0; i < res.size(); i++) {
		if (i > 0)cout << " ";
		cout << res[i];
	}
	cout << endl;
}