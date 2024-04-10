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
const int N = 1000015;
int T, n, m, a[N], cnt[N], Min[N];
int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		ll ans = 0;
		rep(i, 1, n) scanf("%d", &a[i]), ans += abs(a[i]);
		int g = 0;
		rep(i, 1, m) {
			int b;
			scanf("%d", &b);
			g = __gcd(g, b);
		}
		rep(i, 0, g - 1) cnt[i] = 0, Min[i] = inf;
		rep(i, 1, n) {
			cnt[i % g] += (a[i] < 0);
			Min[i % g] = min(Min[i % g], abs(a[i]));
		}
		ll sum[2] = {0, 0};
		rep(i, 0, g - 1) sum[cnt[i] & 1] += Min[i];
		printf("%lld\n", ans - 2 * min(sum[0], sum[1]));
	}
	return 0;
}