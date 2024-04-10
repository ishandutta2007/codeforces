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
	pair<int, int> A[3];
	vector<int> X;
	vector<int> Y;
	for (int i = 0; i < 3; i++) {
		cin >> A[i].first >> A[i].second;
		X.push_back(A[i].first);
		Y.push_back(A[i].second);
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	vector<pair<int, int> > res;
	for (int i = 0; i < 3; i++) {
		int x = X[1];
		int y = Y[1];
		while (x != A[i].first || y != A[i].second) {
			if (x > A[i].first)x--;
			else if (x < A[i].first)x++;
			else if (y > A[i].second)y--;
			else if (y < A[i].second)y++;
			res.emplace_back(x, y);
		}
	}
	res.emplace_back(X[1], Y[1]);
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i].first << " " << res[i].second << endl;
	}
}