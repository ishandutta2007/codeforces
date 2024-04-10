#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (register int i = a, end = b; i <= end; i++)
#define repd(i, a, b) for (register int i = a, end = b; i >= end; i--)
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define INF (1<<30)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define fst first
#define snd second
#define pii pair<int, int>

inline int read() {
    int w = 0, f = 1; char c;
    while (!isdigit(c = getchar())) f = c == '-' ? -1 : f;
    while (isdigit(c)) w = (w << 3) + (w << 1) + (c ^ 48), c = getchar();
    return w * f;
}

const int maxn = 300000 + 5;

int T, N;
int a[maxn], b[maxn];
ll f[maxn][6];

int main() {
	T = read();
	while (T--) {
		N = read();
		rep(i, 1, N) {
			a[i] = read(), b[i] = read();
			rep(x, 0, 5) f[i][x] = 1ll<<60;
			rep(x, 0, 5) {
				rep(y, 0, 5) {
					if (a[i]+x != a[i-1]+y) chkmin(f[i][x], f[i-1][y] + 1ll*b[i]*x);
				}
			}
		}
		ll ans = 1ll<<60;
		rep(x, 0, 5) chkmin(ans, f[N][x]);
		printf("%lld\n", ans);
	}
	return 0;
}