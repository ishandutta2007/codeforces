#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MaxN = (int) 1e5 + 3;
const int mod = 998244353;
int A[MaxN];
ll dp[MaxN][102];
ll dpS[MaxN];
int nxt[MaxN][102];

struct DS {
	int min1 = 1 << 30, min2 = 1 << 30;

	void insert(const int x) {
		if (x < min1) {
			min2 = min1;
			min1 = x;
		} else if (x < min2) {
			min2 = x;
		}
	}

	void rem(const int x) {
		if (x == min2)
			min2 = 1 << 30;
		else if (x == min1) {
			min1 = min2;
			min2 = 1 << 30;
		}
	}

};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N, K, L;
	cin >> N >> K >> L;

	if (L == 1) {
		cout << "0";
		return 0;
	}

	for (int i = 1; i <= N; ++i)
		cin >> A[i];

	fill(nxt[N + 1], nxt[N + 1] + 101, 1 << 30);
	for (int i = N; i >= 1; --i) {
		copy(nxt[i + 1], nxt[i + 1] + 101, nxt[i]);
		if (A[i] != -1)
			nxt[i][A[i]] = i;
	}

	for (int i = N; i >= 1; --i) {
		DS ds;
		ds.insert(i + L);
		for (int j = 1; j <= K; ++j)
			ds.insert(nxt[i + 1][j] + 1);

		for (int j = 1; j <= K; ++j) {
			ll &res = dp[i][j] = 0;
			if (A[i] < 0 || A[i] == j) {
				if (i == N)
					res = 1;
				else if (N - i + 1 < L) {
					res = dpS[i + 1] - dpS[i + 2];
				} else {
					ds.rem(nxt[i + 1][j] + 1);
					const int limit = ds.min1;

					res = dpS[i + 1] - dpS[limit];
					res -= dp[i + 1][j] - dp[limit][j];

					ds.insert(nxt[i + 1][j] + 1);
				}
			}
			(res += dp[i + 1][j]) %= mod;
			(dpS[i] += res) %= mod;
		}
	}

	ll ans = dpS[1] - dpS[2];
	cout << (ans % mod + mod) % mod << '\n';
	return 0;
}