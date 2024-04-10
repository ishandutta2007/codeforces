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

const int N = 200015;

int n, p[N], q[N], to[N];
bool vis[N];

void solve() {
	scanf("%d", &n);
	fill(vis + 1, vis + n + 1, 0);

	rep(i, 1, n) scanf("%d", p + i);

	rep(i, 1, n) scanf("%d", q + i);

	rep(i, 1, n) to[p[i]] = q[i];

	int odd = 0;

	rep(i, 1, n) if (!vis[i]) {
		int x = i, cnt = 0;

		while (!vis[x]) {
			vis[x] = 1;
			cnt++;
			x = to[x];
		}

		if (cnt & 1) odd++;
	}

	int x = (n - odd) / 2;
	ll ans = 0;

	rep(i, 1, x) ans -= i;

	rep(i, n - x + 1, n) ans += i;

	printf("%lld\n", ans * 2);
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