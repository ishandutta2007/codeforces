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
int n, m, a[200015];

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);

	rep(i, 1, n) scanf("%d", &a[i]);

	set<int> S;

	rep(i, 1, m) {
		int x;
		scanf("%d", &x);
		S.emplace(x);
	}

	vector<pii> vec;

	rep(i, 1, n) {
		int p = (i - 1) * 100, dis = inf;

		auto it = S.lower_bound(p);

		if (it != S.end()) dis = min(dis, *it - p);

		if (it != S.begin()) dis = min(dis, p - *prev(it));

		if (dis > 0) vec.emplace_back((p - dis) * 2 + 1, a[i]), vec.emplace_back((p + dis) * 2, -a[i]);
	}

	sort(all(vec));

	ll ans = 0, cur = 0;

	for (auto [p, v] : vec) {
		cur += v;
		ans = max(ans, cur);
	}

	printf("%lld\n", ans);

	return 0;
}