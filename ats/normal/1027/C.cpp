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
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int a;
		map<int, int> mp;
		for (int i = 0; i < N; i++) {
			cin >> a;
			mp[a]++;
		}
		vector<int> X;
		for (auto m : mp) {
			if (m.second >= 4) {
				X.push_back(m.first);
				X.push_back(m.first);
			}
			else if (m.second >= 2) {
				X.push_back(m.first);
			}
		}
		int mnu = 1 << 30;
		int mnd = 1;
		int res1;
		int res2;
		for (int i = 0; i < (int)X.size() - 1; i++) {
			int u = X[i] + X[i + 1];
			u = u*u;
			int d = X[i] * X[i + 1];
			if (mnu*d > u*mnd) {
				mnu = u;
				mnd = d;
				res1 = X[i];
				res2 = X[i + 1];
			}
		}
		cout << res1 << " " << res1 << " " << res2 << " " << res2 << endl;
	}

}