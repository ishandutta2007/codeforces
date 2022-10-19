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

const int N = 1e6 + 15, mod = 998244353;

int n, k, v[N];

void solve() {
	scanf("%d%d", &n, &k);

	rep(i, 1, n) scanf("%d", &v[i]);

	int ans = 1;

	rep(i, 1, k) ans = (ll) ans * i % mod;

	rep(i, k + 1, n) {
		if (v[i - k] == 0) ans = (ll) ans * min(i, k + 1) % mod;
		else if (v[i - k] == -1) ans = (ll) ans * i % mod;
		else if (v[i - k] >= i - k) ans = 0;
	}

	rep(i, n - k + 1, n) if (v[i] > 0) ans = 0;

	printf("%d\n", ans);
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int t;

	for (scanf("%d", &t); t; t--) solve();

	return 0;
}