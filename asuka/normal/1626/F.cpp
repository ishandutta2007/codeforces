#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 1e7 + 15, M = 720720, mod = 998244353;
int n, a[N], x, y, k, m, ans, f[M], g[M], pd[111];
int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d%d%d%d%d%d", &n, &a[1], &x, &y, &k, &m);
	rep(i, 2, n) a[i] = ((ll) a[i - 1] * x + y) % m;
	pd[0] = 1;
	rep(i, 1, k) pd[i] = (ll) pd[i - 1] * n % mod;
	rep(i, 1, n) f[a[i] % M]++;
	rep(j, 1, k) {
		memset(g, 0, sizeof g);
		rep(i, 0, M - 1) {
			g[i] += (ll) f[i] * (n - 1) % mod;
			if(g[i] >= mod) g[i] -= mod;
			int ni = i - (i % j);
			g[ni] += f[i];
			if(g[ni] >= mod) g[ni] -= mod;
			ans += (ll) i * f[i] % mod * pd[k - j] % mod;
			if(ans >= mod) ans -= mod;
		}
		swap(f, g);
	}
	rep(i, 1, n) {
		int o = a[i] / M * M;
		ans += (ll) o * pd[k - 1] % mod * k % mod;
		if(ans >= mod) ans -= mod;
	}
	printf("%d\n", ans);
	return 0;
}