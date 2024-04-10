#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 998244353;

int dp[25][2][(1 << 10) + 1], k, cnt[25][2][(1 << 10) + 1];
vector<int> v;

void go(int pos, int ok, int mask) {
	if (dp[pos][ok][mask] == -1) return;
	int new_pos = pos - 1;
	if (ok == 1) {
		for (int i = 0; i < v[new_pos]; i++) {
			int new_ok = 0;
			int new_mask = (mask | (1 << i));;
			if (mask == 0 && i == 0) new_mask = 0;
			cnt[new_pos][new_ok][new_mask] += cnt[pos][ok][mask];
			cnt[new_pos][new_ok][new_mask] %= MOD;
			if (dp[new_pos][new_ok][new_mask] == -1) {
				dp[new_pos][new_ok][new_mask] = (dp[pos][ok][mask] * 10 + i * cnt[pos][ok][mask]) % MOD;
			} else {
				dp[new_pos][new_ok][new_mask] += (dp[pos][ok][mask] * 10 + i * cnt[pos][ok][mask]) % MOD;
				dp[new_pos][new_ok][new_mask] %= MOD;
			}
		}
		int u = v[new_pos];
		int new_mask = (mask | (1 << u));
		if (mask == 0 && u == 0) new_mask = 0;
		cnt[new_pos][ok][new_mask] = 1;
		dp[new_pos][ok][new_mask] =  (dp[pos][ok][mask] * 10 + u) % MOD;
	} else {
		for (int i = 0; i < 10; i++) {
			int new_ok = 0;
			int new_mask = (mask | (1 << i));;
			if (mask == 0 && i == 0) new_mask = 0;
			cnt[new_pos][new_ok][new_mask] += cnt[pos][ok][mask];
			cnt[new_pos][new_ok][new_mask] %= MOD;
			if (dp[new_pos][new_ok][new_mask] == -1) {
				dp[new_pos][new_ok][new_mask] = (dp[pos][ok][mask] * 10 + i * cnt[pos][ok][mask]) % MOD;
			} else {
				dp[new_pos][new_ok][new_mask] += (dp[pos][ok][mask] * 10 + i * cnt[pos][ok][mask]) % MOD;
				dp[new_pos][new_ok][new_mask] %= MOD;
			}
		}
	}
}

int solve(int u) {
	if (u == 0) return 0;
	memset(dp, -1, sizeof(dp));
	memset(cnt, 0, sizeof(cnt));
	v.clear();
	for (int i = 1; i <= 20; i++) {
		v.push_back(u % 10);
		u /= 10;
	}
	dp[20][1][0] = 0;
	cnt[20][1][0] = 1;
	go(20, 1, 0);
	for (int pos = 19; pos > 0; pos--) {
		for (int ok = 0; ok <= 1; ok++) {
			for (int mask = 0; mask < (1 << 10); mask++) {
				go(pos, ok, mask);
			}
		}
	}
	int res = 0;
	for (int i = 0; i < 20; i++) {
	}
	for (int mask = 1; mask < (1 << 10); mask++) {
		int t = __builtin_popcountll(mask);
		if (t > k) continue;
		if (dp[0][0][mask] != -1) res = (res + dp[0][0][mask]) % MOD;
		if (dp[0][1][mask] != -1) res = (res + dp[0][1][mask]) % MOD;
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int l, r;
	cin >> l >> r >> k;
	l--;
	cout << (solve(r) - solve(l) + MOD) % MOD << endl;
	return 0;
}