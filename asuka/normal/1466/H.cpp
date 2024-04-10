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
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 55, M = 2222, mod = 1e9 + 7;

int n, m, cnt[N], c[N], v[N], p[N], dp[M], C[N][N], pd[N][N], fac[N];

bool vis[N];

void prework() {
	fac[0] = 1;
	rep(i, 1, n) fac[i] = (ll) fac[i - 1] * i % mod;
	rep(i, 0, n) {
		C[i][0] = 1;
		rep(j, 1, i) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
	rep(i, 0, n - 1) {
		pd[i][0] = 1;
		int base = 0;
		rep(j, 0, i) (base += (ll) C[i][j] * fac[j] % mod * fac[n - j - 1] % mod) %= mod;
		rep(j, 1, n - i) pd[i][j] = (ll) pd[i][j - 1] * base % mod;
	}
	rep(i, 1, n) {
		if (vis[i]) continue;
		int x = i, o = 0;
		while (!vis[x]) {
			o++;
			vis[x] = 1;
			x = p[x];
		}
		cnt[o]++;
	}
	rep(i, 1, n) {
		if (!cnt[i]) continue;
		m++; c[m] = cnt[i]; v[m] = i;
	}
}

int encode(int a[]) {
	int res = 0;
	rep(i, 1, m) res = res * (c[i] + 1) + a[i];
	return res;
}

void decode(int x, int a[]) {
	per(i, 1, m) a[i] = x % (c[i] + 1), x /= c[i] + 1;
}

void move(int a[], int b[]) {
	a[1]++;
	rep(i, 1, m) if (a[i] > b[i]) a[i] = 0, a[i + 1]++;
}

pii get(int a[]) {
	int sum = 0, siz = 0;
	rep(i, 1, m) sum += a[i] * v[i], siz += a[i];
	return mp(sum, siz);
}

int main() {
	// freopen("c.in", "r", stdin);
	// freopen("c.out", "w", stdout);
	cin >> n;
	rep(i, 1, n) cin >> p[i];
	prework();
	int all = encode(c);
	dp[0] = 1;
	rep(i, 1, all) {
		static int cur[N], nxt[N];
		decode(i, cur);
		auto [csum, csiz] = get(cur);
		int j;
		for (decode(0, nxt); (j = encode(nxt)) != i; move(nxt, cur)) {
			auto [nsum, nsiz] = get(nxt);
			int coef = pd[nsum][csum - nsum];
			rep(i, 1, m) coef = (ll) coef * C[cur[i]][nxt[i]] % mod;
			if ((csiz - nsiz + 1) & 1) coef = mod - coef;
			(dp[i] += (ll) dp[j] * coef % mod) %= mod;
		}
	}
	cout << dp[all] << endl;
	return 0;
}