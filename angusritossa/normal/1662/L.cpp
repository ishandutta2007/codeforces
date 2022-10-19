#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
typedef long long ll;

const ll rangetreeMAX = 2e15;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
struct Node {
	int left, right, mx;
};
Node rangetree[MAXN*90];
int upto = 1;
void update(ll node, int mx, int curr = 1, ll cstart = 0, ll cend = rangetreeMAX) {
	if (cstart == cend) {
		rangetree[curr].mx = mx;
		return;
	}
	ll mid = (cstart+cend)/2;
	if (node <= mid) {
		if (!rangetree[curr].left) {
			rangetree[curr].left = ++upto;
			rangetree[rangetree[curr].left] = rangetree[0];
		}
		update(node, mx, rangetree[curr].left, cstart, mid);
	} else {
		if (!rangetree[curr].right) {
			rangetree[curr].right = ++upto;
			rangetree[rangetree[curr].right] = rangetree[0];
		}
		update(node, mx, rangetree[curr].right, mid+1, cend);
	}
	rangetree[curr].mx = max(rangetree[rangetree[curr].left].mx, rangetree[rangetree[curr].right].mx);
}
int query(ll s, ll e, int curr = 1, ll cstart = 0, ll cend = 2e15) {
	if (s <= cstart && cend <= e) {
		return rangetree[curr].mx;
	}
	ll mid = (cstart+cend)/2;
	if (e <= mid) {
		return query(s, e, rangetree[curr].left, cstart, mid);
	} else if (s > mid) {
		return query(s, e, rangetree[curr].right, mid+1, cend);
	} else {
		auto val1 = query(s, e, rangetree[curr].left, cstart, mid);
		auto val2 = query(s, e, rangetree[curr].right, mid+1, cend);
		return max(val1, val2);
	}
}
int n;
ll t[MAXN], pos[MAXN], v;
vector<pair<ll, ll> > sorted; // b, -a
int main() {
	scanf("%d%lld", &n, &v);
	for (int i = 0; i < n; i++) scanf("%lld", &t[i]);
	for (int i = 0; i < n; i++) scanf("%lld", &pos[i]);
	for (int i = 0; i < n; i++) {
		pos[i] += 1e9;
		ll b = pos[i]-v*t[i];
		D("b %lld\n", b);
		if (b <= 1e9) {
			sorted.push_back({b, -pos[i]-v*t[i]});
		}
	}
	sort(sorted.begin(), sorted.end());
	for (auto x : sorted) {
		ll a = -x.second;
		int res = query(a, rangetreeMAX);
		res++;
		D("%lld %lld : %d\n", a, x.second, res);
		update(a, res);
	}

	printf("%d\n", query(1e9, rangetreeMAX));
}