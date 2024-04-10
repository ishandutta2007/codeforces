#include <bits/stdc++.h>
#define int long long
#define bp __builtin_popcountll
#define pb push_back
#define in(s) freopen(s, "r", stdin);
#define inout(s) freopen(string(s) + ".inp", "r", stdin), freopen(string(s) + ".out", "w", stdout);
#define fi first
#define se second
#define bw(i, r, l) for (int i = r - 1; i >= l; i--)
#define fw(i, l, r) for (int i = l; i < r; i++)
#define fa(i, x) for (auto i: x)
using namespace std;
const int mod = 1e9 + 7, inf = 1061109567;
const long long infll = 4557430888798830399;
typedef pair<int, int> ii;
const int N = 2e5 + 5;
int n, a[N], k, dp[N];
int ceil(int x, int y) {
	if (x % y == 0) return x / y;
	else return x / y + 1;
}
signed main() {
	#ifdef BLU
	in("blu.inp");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	fw (i, 1, n + 1) cin >> a[i];
	/*
	If we make new bags on day i, some of it should be used to contain garbage on day i + 1.
	So now, for day 1, make garbage bags and see how much of day 2 we can also put in (Dispose of them
	on day 2). Keep doing the same.
	*/
	int ans = 0;
	fw (i, 1, n + 1) {
		if (i == n) ans += ceil(a[i], k);
		else {
			ans += ceil(a[i], k);
			//a[i] % k is the garbage put in the last bag. Put in k - a[i] % k garbage from the next
			//day inside
			int tmp = a[i] % k;
			if (tmp) {
				a[i + 1] -= (k - tmp);
				a[i + 1] = max(a[i + 1], 0LL);
			}
		}
	}
	cout << ans;
	return 0;
}