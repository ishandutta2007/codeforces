#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define per(i, a, b) for(int i = a; i >= b; --i)
#define siz(a) ((int) a.size())
#define PB push_back
#define LL long long
const int N = 1e9;
const int M = 1e5;
const int mod = 1e9 + 7;
const int inf = 1e18;

int read() {
	int x = 0, y = 0;
	char ch = getchar();
	for(; ch < '0' || ch > '9'; y |= (ch == '-'), ch = getchar());
	for(; ch >= '0' && ch <= '9'; x = x * 10 + ch - '0', ch = getchar());
	return x * (y ? -1 : 1);
}

int a, b, c, d, res, x, y, p, q;

int ask(int x, int y) {
	printf("? %lld %lld\n", x, y);
	fflush(stdout);
	int ans = inf;
//	rep(i, 2, 4) rep(j, 3, 5) ans = min(ans, abs(i - x) + abs(j - y));
	return read();
}

signed main() {
//	freopen("in.txt", "r", stdin);
	a = ask(1, 1);
	b = ask(N, 1);
	c = ask(1, N);
	d = ask(N, N);
	int l1 = a + 1, l2 = N - b, mid = (l1 + l2 + 1) / 2;
	y = ask(mid, 1) + 1;
//	cout << a << ' ' << N - c << endl;
	l1 = a + 1, l2 = N - c, mid = (l1 + l2 + 1) / 2;
	x = ask(1, mid) + 1;
	l1 = b + 1, l2 = N - d, mid = (l1 + l2 + 1) / 2;
//	cout << d << endl;
	p = N - ask(N, mid);
	l1 = c + 1, l2 = N - d, mid = (l1 + l2 + 1) / 2;
	q = N - ask(mid, N);
	printf("! %lld %lld %lld %lld", x, y, p, q);
	return 0;
}