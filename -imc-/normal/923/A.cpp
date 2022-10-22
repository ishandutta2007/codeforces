#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 1111111;
int erat[N];

int dp[N];

int main() {
	erat[1] = 1;
	for (int i = 2; i < N; ++i) {
		if (erat[i]) {
			continue;
		}
		erat[i] = i;
		if (1.0 * i * i < N + N) {
			for (int j = i * i; j < N; j += i) {
				if (erat[j] == 0) {
					erat[j] = i;
				}
			}
		}
	}

	for (int p = 2; p < N; ++p) {
		if (erat[p] != p) {
			continue;
		}
		for (int i = 2 * p; i < N; i += p) {
			int cand = (i == p) ? p : i - p + 1;
			if (dp[i] == 0 || dp[i] > cand) {
				dp[i] = cand;
			}
		}
	}

	// for (int i = 2; i <= 10; ++i) {
	// 	cerr << "before " << i << " can be only at least " << dp[i] << "\n";
	// }

	int n = nxt();
	int max_p = 0;
	for (int i = 2; i < n; ++i) {
		if (erat[i] == i && n % i == 0) {
			max_p = i;
		}
	}

	int ans = n;
	for (int i = n - max_p + 1; i <= n; ++i) {
		if (dp[i] > 0) {
			ans = min(ans, dp[i]);
		}
	}

	printf("%d\n", ans);

	return 0;
}