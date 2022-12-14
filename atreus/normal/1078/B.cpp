#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 100 + 4;
const int maxA = 10000 + 10;
int a[maxn];
int n, mark[maxn];
bitset <maxA> dp[maxn];

bool check (int x, int ted) {
	for (int i = 0; i < maxn; i++)
		dp[i].reset();

	dp[0][0] = 1;
	int tmp = ted;
	for (int i = 1; i <= n; i++) {
		if (a[i] == x) {
			if (tmp == 1)
				continue;
			tmp --;
		}
		for (int k = n; k >= 1; k--) {
			dp[k] |= (dp[k - 1] << a[i]);
		}
	}
	return dp[ted][x * ted];
}

int main () {
	ios::sync_with_stdio(false);
	cin >> n;

	int tmp = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (mark[a[i]] == 0)
			tmp ++;
		mark[a[i]] = 1;
	}
	if (tmp <= 2) {
		return cout << n << endl, 0;
	}
	sort (a + 1, a + n + 1);
	int ans = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt ++;
		if (a[i] != a[i + 1]) {
			int lo = 1, hi = cnt + 1;
			while (hi - lo > 1) {
				int mid = (hi + lo) >> 1;
				if (check (a[i], mid))
					hi = mid;
				else
					lo = mid;
			}
			ans = max (ans, lo);
			cnt = 0;
		}
	}
	cout << ans << endl;
}