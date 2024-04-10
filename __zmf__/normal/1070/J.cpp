// Problem: J. Streets and Avenues in Berhattan
// Contest: Codeforces - 2018-2019 ICPC, NEERC, Southern Subregional Contest (Online Mirror, ACM-ICPC Rules, Teams Preferred)
// Author: RedreamMer
// Memory Limit: 256 MB
// Time Limit: 3000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define LL long long
#define PB push_back
#define siz(a) ((int)((a).size()))
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
const int N = 2e5;
const int M = 3e4;
const int mod = 1e9 + 7;
const int inf = 1e9;
int read() {
	int x = 0, y = 0;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar()) y |= (c == '-');
	for (; c >= '0' && c <= '9'; x = x * 10 + (c ^ 48), c = getchar());
	return (y ? -x : x);
}

int a, b, c, st[26];
char o[N + 5];
bitset<M + 5> p1, q1, tmp1;
bitset<205> p2, q2, tmp2;

signed main() {
	// freopen("in1.in", "r", stdin);
	per(t, read(), 1) {
		a = read();
		b = read();
		c = read();
		scanf("%s", o + 1);
		rep(i, 0, 25) st[i] = 0;
		rep(i, 1, c) ++st[o[i] - 'A'];
		if(a > b) swap(a, b);
		if(a > 200) {
		p1.reset(), tmp1.reset();
		rep(i, 0, a) tmp1[i] = 1;
		p1[0] = 1;
		LL ans = 1ll * inf * inf;
		rep(i, 0, 25) {
			q1 = p1;
			rep(j, i + 1, 25) q1 |= (q1 << st[j]);
			q1 &= tmp1;
			per(j, a, 0) {
				if(!q1[j] || j + st[i] < a) continue;
				int k = j + st[i];
				ans = min(ans, 1ll * max(b - (c - k), 0) * (a - j));
			}
			p1 |= (p1 << st[i]);
		}
		printf("%lld\n", ans);
		}
		else {
		p2.reset(), tmp2.reset();
		rep(i, 0, a) tmp2[i] = 1;
		p2[0] = 1;
		LL ans = 1ll * inf * inf;
		rep(i, 0, 25) {
			q2 = p2;
			rep(j, i + 1, 25) q2 |= (q2 << st[j]);
			q2 &= tmp2;
			per(j, a, 0) {
				if(!q2[j] || j + st[i] < a) continue;
				int k = j + st[i];
				ans = min(ans, 1ll * max(b - (c - k), 0) * (a - j));
			}
			p2 |= (p2 << st[i]);
		}
		printf("%lld\n", ans);
		}
	}
	return 0;
}