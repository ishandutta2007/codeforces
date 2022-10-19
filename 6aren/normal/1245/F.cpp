#include<bits/stdc++.h>
using namespace std;

#define int long long

int dp[50][2][2][2][2];
vector<int> v1, v2;

void go(int pos, int ok1, int ok2, int ok3, int ok4) {
	int u = dp[pos][ok1][ok2][ok3][ok4];
	if (u == 0) return;
	int newok1, newok2, newok3, newok4;
	int npos = pos + 1;
	if (v1[npos] == 0 && v2[npos] == 0) {
		for (int d1 = 0; d1 < 2; d1++) {
			for (int d2 = 0; d2 < 2; d2++) {
				if (d1 + d2 == 2) continue;
				if (ok1 == 1 && d1 == 0) newok1 = 1;
				else newok1 = 0;
				if (ok2 == 1 && d1 == 0) newok2 = 1;
				else if (ok2 == 1 && d1 == 1) continue;
				else newok2 = 0;
				if (ok3 == 1 && d2 == 0) newok3 = 1;
				else newok3 = 0;
				if (ok4 == 1 && d2 == 0) newok4 = 1;
				else if (ok4 == 1 && d2 == 1) continue;
				else newok4 = 0;
				dp[npos][newok1][newok2][newok3][newok4] += u;
			} 
		}
	}
	if (v1[npos] == 0 && v2[npos] == 1) {
		for (int d1 = 0; d1 < 2; d1++) {
			for (int d2 = 0; d2 < 2; d2++) {
				if (d1 + d2 == 2) continue;
				if (ok1 == 1 && d1 == 0) newok1 = 1;
				else newok1 = 0;
				if (ok2 == 1 && d1 == 1) newok2 = 1;
				else newok2 = 0;
				if (ok3 == 1 && d2 == 0) newok3 = 1;
				else newok3 = 0;
				if (ok4 == 1 && d2 == 1) newok4 = 1;
				else newok4 = 0;
				dp[npos][newok1][newok2][newok3][newok4] += u;
			} 
		}
	}
	if (v1[npos] == 1 && v2[npos] == 0) {
		for (int d1 = 0; d1 < 2; d1++) {
			for (int d2 = 0; d2 < 2; d2++) {
				if (d1 + d2 == 2) continue;
				if (ok1 == 1 && d1 == 1) newok1 = 1;
				else if (ok1 == 1 && d1 == 0) continue;
				else newok1 = 0;
				if (ok2 == 1 && d1 == 0) newok2 = 1;
				else if (ok2 == 1 && d1 == 1) continue;
				else newok2 = 0;
				if (ok3 == 1 && d2 == 1) newok3 = 1;
				else if (ok3 == 1 && d2 == 0) continue;
				else newok3 = 0;
				if (ok4 == 1 && d2 == 0) newok4 = 1;
				else if (ok4 == 1 && d2 == 1) continue;
				else newok4 = 0;
				dp[npos][newok1][newok2][newok3][newok4] += u;
			} 
		}
	}
	if (v1[npos] == 1 && v2[npos] == 1) {
		for (int d1 = 0; d1 < 2; d1++) {
			for (int d2 = 0; d2 < 2; d2++) {
				if (d1 + d2 == 2) continue;
				if (ok1 == 1 && d1 == 1) newok1 = 1;
				else if (ok1 == 1 && d1 == 0) continue;
				else newok1 = 0;
				if (ok2 == 1 && d1 == 1) newok2 = 1;
				else newok2 = 0;
				if (ok3 == 1 && d2 == 1) newok3 = 1;
				else if (ok3 == 1 && d2 == 0) continue;
				else newok3 = 0;
				if (ok4 == 1 && d2 == 1) newok4 = 1;
				else newok4 = 0;
				dp[npos][newok1][newok2][newok3][newok4] += u;
			} 
		}
	}
}

main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof(dp));
		int l, r;
		cin >> l >> r;
		v1.clear();
		v2.clear();
		for (int i = 1; i <= 50; i++) {
			v1.push_back(l % 2);
			l /= 2;
		}
		for (int i = 1; i <= 50; i++) {
			v2.push_back(r % 2);
			r /= 2;
		}
		reverse(v1.begin(), v1.end());
		reverse(v2.begin(), v2.end());
		dp[0][1][1][1][1] = 1;
		for (int pos = 0; pos < 49; pos++) {
			for (int ok1 = 0; ok1 < 2; ok1++) {
				for (int ok2 = 0; ok2 < 2; ok2++) {
					for (int ok3 = 0; ok3 < 2; ok3++) {
						for (int ok4 = 0; ok4 < 2; ok4++) {
							go(pos, ok1, ok2, ok3, ok4);
						}
					}
				}
			}
		}
		int res = 0;
		for (int ok1 = 0; ok1 < 2; ok1++) {
			for (int ok2 = 0; ok2 < 2; ok2++) {
				for (int ok3 = 0; ok3 < 2; ok3++) {
					for (int ok4 = 0; ok4 < 2; ok4++) {
						res += dp[49][ok1][ok2][ok3][ok4];
					}
				}
			}
		}
		//cout << dp[48][0][1][0][0] << endl;
		cout << res << endl;
	}
	return 0;
}