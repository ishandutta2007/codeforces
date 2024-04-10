// Problem: H. Load Testing
// Contest: Codeforces - 2017-2018 ACM-ICPC, NEERC, Southern Subregional Contest, qualification stage (Online Mirror, ACM-ICPC Rules, Teams Preferred)
// Author: RedreamMer
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define LL long long
#define PB push_back
#define siz(a) ((int)((a).size()))
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
const int N = 1e5;
const int M = 100000;
const int mod = 1e9 + 7;
const int inf = 1e18;
int read() {
	int x = 0, y = 0;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar()) y |= (c == '-');
	for (; c >= '0' && c <= '9'; x = x * 10 + (c ^ 48), c = getchar());
	return (y ? -x : x);
}

int a, s[N + 5], L[N + 5], R[N + 5], l[N + 5], r[N + 5];

signed main() {
	// freopen("in1.in", "r", stdin);
	a = read();
	rep(i, 1, a) s[i] = read();
	int mx = 0;
	rep(i, 1, a) {
		mx = max(mx + 1, s[i]);
		L[i] = L[i - 1] + mx - s[i];
		l[i] = mx;
	}
	mx = 0;
	int o = 0;
	per(i, a, 1) {
		mx = max(mx + 1, s[i]);
		R[i] = R[i + 1] + mx - s[i];
		r[i] = mx;
		o += mx - s[i];
	}
	// cout << o << endl;
	// cout << R[2];
	int ans = inf;
	rep(i, 1, a) {
		int n = max(l[i - 1], r[i + 1]);
		// cout << l[2] << ' ' << r[4] << endl;
		ans = min(ans, max(n - s[i] + 1, 0ll) + L[i - 1] + R[i + 1]);
		// cout << ans << endl;
	}
	cout << ans;
	return 0;
}