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
vector<int> X;
vector<int> A;
int solve(int x, int l, int d, int muki) {
	//cerr << x << " " <<l<<" "<< muki << endl;
	if (d >= 2) {
		if (A[d - 2] == x) {
			if (A[d - 1] == x) {
				return x;
			}
			else {
				int t = abs(x - A[d - 1]);

				if ((l / t) % 2 == 0) {
					return solve(x, l % t, 0, muki);
				}
				else {
					return solve(A[d - 1], l % t, 0, 1 - muki);
				}
			}
		}
	}
	A[d] = x;
	if (muki == 0) {
		int z = upper_bound(X.begin(), X.end(), x + l) - X.begin();
		z--;
		return solve(X[z], l - abs(X[z] - x), d + 1, 1 - muki);
	}
	else {
		int z = lower_bound(X.begin(), X.end(), x - l) - X.begin();
		return solve(X[z], l - abs(X[z] - x), d + 1, 1 - muki);
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	X.resize(N);
	A.resize(max((int)100, N));
	int res = 0;
	map<int, int> mp;
	vector<int> rev;
	for (int i = 0; i < N; i++) {
		cin >> X[i];
		mp[X[i]] = i + 1;
	}
	rev = X;
	sort(X.begin(), X.end());
	int a;
	int b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		a = rev[a - 1];
		//cerr << "solve " << a << " " << b << endl;
		cout << mp[solve(a, b, 0, 0)] << endl;
	}
}