#ifndef DEBUG
#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,abm,mmx,popcnt")
#endif
#include <bits/stdc++.h>
using namespace std;

#define int long long

#define endl '\n'
typedef long long ll;
typedef long double ldb;


int n, m;

bool check2(int a, int b) {
	return 0 <= a && a < b;
}

bool check(int i, int j) {
	return check2(i, n) && check2(j, m);
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(12);
	cin >> n >> m;
	vector<string> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> canx(n);
	vector<int> cany(m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '#') {
				canx[i] = 1;
				cany[j] = 1;
			}
		}
	}
	bool bad = 0;
	for (int i = 0; i < n; i++) {
		int cur = 0;
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '#') {
				if (cur == 0) {
					cur = 1;
				} else if (cur == 2) {
					bad = 1;
				}
			} else {
				if (cur == 1) {
					cur = 2;
				}
			}
		}
	}
	for (int j = 0; j < m; j++) {
		int cur = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i][j] == '#') {
				if (cur == 0) {
					cur = 1;
				} else if (cur == 2) {
					bad = 1;
				}
			} else {
				if (cur == 1) {
					cur = 2;
				}
			}
		}
	}
	int sumx1 = 0;
	for (int i = 0; i < m; i++) {
		sumx1 += cany[i];
	}
	if (sumx1 == m) {
		for (int i = 0; i < n; i++) {
			int sumx2 = 0;
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == '#') {
					sumx2 += 1;
				}
			}
			if (sumx2 == 0)
				bad = 1;
		}
	}
	int sumy1 = 0;
	for (int i = 0; i < n; i++) {
		sumy1 += canx[i];
	}
	if (sumy1 == n) {
		for (int j = 0; j < m; j++) {
			int sumx2 = 0;
			for (int i = 0; i < n; i++) {
				if (arr[i][j] == '#') {
					sumx2 += 1;
				}
			}
			if (sumx2 == 0)
				bad = 1;
		}
	}
	if (bad) {
		cout << -1 << endl;
		return 0;
	}
	vector<int> dx = {-1, 0, 0, 1};
	vector<int> dy = {0, -1, 1, 0};
	vector<vector<char>> used(n, vector<char> (m));
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '#' && !used[i][j]) {
				ans++;
				deque<pair<int, int>> d;
				d.push_back({i, j});
				while (!d.empty()) {
					int a = d.front().first;
					int b = d.front().second;
					d.pop_front();
					for (int k = 0; k < 4; k++) {
						int aa = a;
						int bb = b;
						aa += dx[k];
						bb += dy[k];
						if (check(aa, bb) && arr[aa][bb] == '#' && !used[aa][bb]) {
							d.push_back({aa, bb});
							used[aa][bb] = 1;
						}
					}
				}
			}
		}
	}
	cout << ans << endl;
}

// If interactive problem remove #define endl '\n'
// CopyPasted part from BenQ:

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/