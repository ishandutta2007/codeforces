#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 50015, mod = 1e9 + 7;
int n, m, a[N], ch[N * 30][2], cnt[N * 30][30], siz[N * 30], tot;

void ins(int x) {
	int u = 0;

	per(i, 0, 29) {
		int &v = ch[u][x >> i & 1];
		if (!v) v = ++tot;
		u = v;
		rep(j, 0, 29) cnt[u][j] += x >> j & 1;
		siz[u]++;
	}
}

int _calc(int x, int y) {
	int u = 0, ans = 0;

	per(i, 0, 29) {
		int o = (x ^ y) >> i & 1;
		if (~y >> i & 1) ans += siz[ch[u][!o]];
		u = ch[u][o];
		if (!u) break;
	}

	if (y == 0) ans--;
	return ans + siz[u];
}

int calc(int x) {
	unsigned ans = 0;
	rep(i, 1, n) ans += _calc(a[i], x);
	return ans >> 1;
}

int Calc(int x, int y) {
	int u = 0, ans = 0;

	per(i, 0, 29) {
		int o = (x ^ y) >> i & 1, w = ch[u][!o];
		if (~y >> i & 1) rep(j, 0, 29) 
			ans = (ans + (1ll << j) * (x >> j & 1 ? siz[w] - cnt[w][j] : cnt[w][j])) % mod;   
		u = ch[u][o];
		if (!u) break;
	}

	rep(j, 0, 29) 
		ans = (ans + (1ll << j) * (x >> j & 1 ? siz[u] - cnt[u][j] : cnt[u][j])) % mod;

	return ans;
}

int main() {
#ifdef Asuka
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i], ins(a[i]);
	int ans = 0;

	for (int l = 0, r = (1 << 30) - 1, mid; mid = (l + r) >> 1, l <= r; ) {
		if (calc(mid) >= m) ans = mid, l = mid + 1;
		else r = mid - 1;
	}

	int c = calc(ans), sum = 0;
	rep(i, 1, n) sum += Calc(a[i], ans), sum >= mod && (sum -= mod);
	sum -= 2ll * (c - m) * ans % mod, sum < 0 && (sum += mod);
	sum = (ll) sum * (mod + 1) / 2 % mod;
	cout << sum << '\n';
	return 0;
}