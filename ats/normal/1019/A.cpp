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
	int N, M;
	cin >> N >> M;
	vector<vector<int> > A(M);
	int res = 0;
	int a, b;
	map<int, int> mp;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		a--;
		A[a].push_back(b);
		if (a > 0)mp[b]++;
	}
	//cerr << "ok" << endl;
	for (int i = 0; i < M; i++) {
		sort(A[i].begin(), A[i].end());
	}
	res = (int)1 << 60;
	int c;
	for (int i = 1; i <= N; i++) {
		int ans = 0;
		map<int, int> mp2 = mp;
		c = A[0].size();
		for (int j = 1; j < M; j++) {
			if ((int)A[j].size() >= i) {
				for (int k = 0; k <= (int)A[j].size() - i; k++) {
					ans += A[j][k];
					/*if (i == 2) {
						cerr << A[j][k] << endl;
					}*/
					c++;
					if ((--mp2[A[j][k]]) == 0) {
						mp2.erase(A[j][k]);
					}
					
				}
			}
		}
		//cerr << i << " " << ans << endl;
		while (c < i) {
			auto x = mp2.begin();
			int t = (*x).first;
		/*	if (i == 2) {
				cerr << t << endl;
			}
*/
			ans += t;
			c++;

			if (--mp2[t] == 0) {
				mp2.erase(t);
			}

		}
		//cerr << i << " " << ans << endl;
		res = min(res, ans);
	}
	cout << res << endl;
}