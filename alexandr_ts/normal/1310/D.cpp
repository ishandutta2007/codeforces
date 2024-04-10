#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <numeric>
#include <map>
#include <vector>
#include <set>
#include <cassert>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cmath>
#include <string>
#include <queue>
#include <unordered_map>
#include <iomanip>

using namespace std;


typedef long long ll;
typedef long double ld;

const int INF = (int)2e9 + 10;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const ll MOD = (int)1e9 + 7;
const int M = (int)4e4 + 10;
const int N = 80;

int a[N][N];
int d[N][N][6];
int id[N][N][6];
int sz[N][N];
vector<pair<int, int>> tmp[N][N];

int used[N];

inline int go(vector<int>& seq) {
	int cur = 0;
	for (size_t i = 0; i < (int)seq.size(); ++i) {
		size_t j = i + 1;
		if (j == seq.size()) {
			j = 0;
		}
		bool ok = true;
		for (size_t k = 0; ok && k < sz[seq[i]][seq[j]]; ++k) {
			if (!used[id[seq[i]][seq[j]][k]]) {
				cur += d[seq[i]][seq[j]][k];
				ok = false;
			}
		}
		if (ok) {
			return INF;
		}
	}
	return cur;
}

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (k != i && k != j) {
					tmp[i][j].push_back(make_pair(a[i][k] + a[k][j], k));
				}
			}
			sort(tmp[i][j].begin(), tmp[i][j].end());
			tmp[i][j].resize(min(6u, tmp[i][j].size()));
			sz[i][j] = tmp[i][j].size();
			for (size_t k = 0; k < tmp[i][j].size(); ++k) {
				d[i][j][k] = tmp[i][j][k].first;
				id[i][j][k] = tmp[i][j][k].second;
			}
		}
	}

	int cnt = k / 2 - 1;
	vector<int> seq(cnt + 1, 0);
	int ans = INF;
	if (cnt == 0) {
		ans = go(seq);
	}
	else { 
		for (int i1 = 0; i1 < n; ++i1) {
			used[i1]++;
			seq[1] = i1;
			if (cnt == 1) {
				ans = min(ans, go(seq));
			}
			else {
				for (int i2 = 0; i2 < n; ++i2) {
					used[i2]++;
					seq[2] = i2;
					if (cnt == 2) {
						ans = min(ans, go(seq));
					}
					else {
						for (int i3 = 0; i3 < n; ++i3) {
							used[i3]++;
							seq[3] = i3;
							if (cnt == 3) {
								ans = min(ans, go(seq));
							}
							else {
								for (int i4 = 0; i4 < n; ++i4) {
									used[i4]++;
									seq[4] = i4;
									if (cnt == 4) {
										ans = min(ans, go(seq));
									}
									used[i4]--;
								}
							}
							used[i3]--;
						}
					}
					used[i2]--;
				}
			}
			used[i1]--;
		}
	}

	cout << ans << endl;
}

int main() {
	//freopen("a.in", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
}