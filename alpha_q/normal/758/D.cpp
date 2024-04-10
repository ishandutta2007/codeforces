#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;

const int N = 70;
const ll INF = 1e18 + 0LL;

char s[N];
ll n, dp[N];
int m;

ll at (char c) {
	return (ll) (c - '0');
}

ll power (ll a, int e) {
	ll res = 1LL;
	while (e--) res *= a;
	return res;
}

ll call (int pos) {
	if (pos > m) return 0LL;
	if (dp[pos] != -1) return dp[pos];
	ll &ret = dp[pos];
	ret = INF + 10;
	ll num = 0LL, pwr = 1LL;
	for (int i = pos; i <= m; ++i) {
		if (num >= n) break;
		if (at(s[i]) <= (n - 1LL - num)/pwr) {
			num += (at(s[i]) * pwr);
			if (i == pos or (i > pos and at(s[i]) != 0)) {
				ll now = call(i + 1);
				if (now <= (INF - num)/n) {
					ret = min(ret, num + n * now);
				}
			}
		} else {
			break;
		}
		pwr *= 10LL;
	}
	return ret;
}

int main (int argc, char const *argv[]) {
	scanf("%lld %s", &n, s + 1);
	m = strlen(s + 1);
	s[m + 1] = '#';
	reverse(s + 1, s + m + 1);
	memset(dp, -1, sizeof dp);
	// for (int i = 1; i <= m; ++i) {
	// 	cout << i << ": " << call(i) << endl;
	// }
	printf("%lld\n", call(1));
	return 0;
}