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
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	vector<vector<int> > X(100010);

	for (int i = 2; i <= 100000; i++) {
		if (X[i].size() == 0) {
			for (int j = i; j <= 100000; j += i) {
				X[j].push_back(i);
			}
		}
	}

	vector<int> B(N);
	vector<int> C(N);
	map<int, int> mp;
	for (int i = 0; i < N; i++) {
		int x = 1;
		int y = 1;
		for (int &j : X[A[i]]) {
			int t = A[i];
			int cnt = 0;
			while (t % j == 0) {
				t /= j;
				cnt++;
			}
			cnt %= K;
			for (int k = 0; k < cnt; k++) {
				x *= j;
			}
			if (cnt != 0) {
				cnt = K - cnt;
				for (int k = 0; k < cnt && y <= 100010; k++) {
					y *= j;
				}
			}
		}
		res += mp[y];
		B[i] = x;
		//cerr << i << " " << x << " " << y << endl;
		mp[x]++;
	}


	cout << res << endl;
}