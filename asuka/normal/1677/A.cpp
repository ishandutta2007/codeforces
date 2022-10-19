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

const int N = 5055;

int n, a[N], buc[N];

void solve() {
	scanf("%d", &n);

	rep(i, 1, n) scanf("%d", a + i);

	ll ans = 0;

	rep(i, 1, n) {
		fill(buc + 1, buc + n + 1, 0);

		rep(j, i + 1, n) buc[a[j]]++;

		rep(j, 1, n) buc[j] += buc[j - 1];

		ll sum = 0;

		per(j, 1, i - 1) {
			if (a[j] < a[i]) ans += sum;

			sum += buc[a[j]];
		}
	}

	printf("%lld\n", ans);
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