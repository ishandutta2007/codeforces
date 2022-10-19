#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
#define MAXN 300030
typedef long long ll;
struct segtree {
	array<ll, 3> rangetree[MAXN*4];
	int N;
	void init(int n) {
		N = n+1;
		array<ll, 3> arr = { (ll)(1e15), 0, 0 };
		fill_n(rangetree, 4*n+20, arr);
	}
	void upd(int curr) {
		rangetree[curr][0] = min(rangetree[2*curr][0], rangetree[2*curr+1][0]);
		rangetree[curr][1] = 0;
		if (rangetree[2*curr][0] == rangetree[curr][0]) rangetree[curr][1] += rangetree[2*curr][1];
		if (rangetree[2*curr+1][0] == rangetree[curr][0]) rangetree[curr][1] += rangetree[2*curr+1][1];
		rangetree[curr][0] += rangetree[curr][2];
	}
	void pointUpdate(int node, ll val, int curr = 1, int cstart = 0, int cend = -1) {
		if (cend == -1) cend = N;
		if (cstart == cend) {
			rangetree[curr][0] = val;
			rangetree[curr][1] = 1;
			rangetree[curr][2] = 0;
			return;
		}
		int mid = (cstart+cend)/2;
		if (node <= mid) pointUpdate(node, val, 2*curr, cstart, mid);
		else if (node > mid) pointUpdate(node, val, 2*curr+1, mid+1, cend);
		upd(curr);
	}
	void rangeUpdate(int s, int e, ll val, int curr = 1, int cstart = 0, int cend = -1) {
		if (cend == -1) cend = N;
		if (s <= cstart && cend <= e) {
			rangetree[curr][0] += val;
			rangetree[curr][2] += val;
			return;
		}
		int mid = (cstart+cend)/2;
		if (e <= mid) rangeUpdate(s, e, val, 2*curr, cstart, mid);
		else if (s > mid) rangeUpdate(s, e, val, 2*curr+1, mid+1, cend);
		else {
			rangeUpdate(s, e, val, 2*curr, cstart, mid);
			rangeUpdate(s, e, val, 2*curr+1, mid+1, cend);
		}
		upd(curr);
	}
	pair<ll, ll> query(int s, int e, int curr = 1, int cstart = 0, int cend = -1) {
		if (cend == -1) cend = N;
		if (s <= cstart && cend <= e) {
			return { rangetree[curr][0], rangetree[curr][1] };
		}
		int mid = (cstart+cend)/2;
		if (e <= mid) {
			auto ans = query(s, e, 2*curr, cstart, mid);
			ans.first += rangetree[curr][2];
			return ans;
		}
		else if (s > mid) {
			auto ans = query(s, e, 2*curr+1, mid+1, cend);
			ans.first += rangetree[curr][2];
			return ans;
		}
		else {
			auto ans1 = query(s, e, 2*curr, cstart, mid);
			auto ans2 = query(s, e, 2*curr+1, mid+1, cend);
			pair<ll, ll> ans = { 0, 0 };
			ans.first = min(ans1.first, ans2.first);
			if (ans.first == ans1.first) ans.second += ans1.second;
			if (ans.first == ans2.first) ans.second += ans2.second;
			ans.first += rangetree[curr][2];
			return ans;
		}
	}
	int findLess0(int curr = 1, int cstart = 0, int cend = -1, ll add = 0) {
		if (cend == -1) cend = N;
		if (cstart == cend) return cstart;
		add += rangetree[curr][2];
		int mid = (cstart+cend)/2;
		if (rangetree[2*curr][0] + add < 0) {
			return findLess0(2*curr, cstart, mid, add);
		} else {
			return findLess0(2*curr+1, mid+1, cend, add);
		}
	}
};
int n;
ll a[MAXN];
segtree s1, s2;
int main() {
	int t;
	scanf("%d", &t);
	for (int _ = 0; _ < t; _++) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		ll ans = 0;
		s1.init(n);
		s2.init(n);
		for (int i = n; i >= 1; i--) {
			if (i%2 == 0) {
				s1.pointUpdate(i, a[i]);
				if (i != n) {
					s1.rangeUpdate(i+1, n, a[i]);
					s2.rangeUpdate(i+1, n, -a[i]);
				}
			} else {
				s2.pointUpdate(i, a[i]);
				if (i != n) {
					s2.rangeUpdate(i+1, n, a[i]);
					s1.rangeUpdate(i+1, n, -a[i]);
				}
			}
			int less0 = min(s1.findLess0(), s2.findLess0());
			auto q1 = s1.query(i, less0-1);
			auto q2 = s2.query(i, less0-1);
			assert(q1.first >= 0);
			assert(q2.first >= 0);
			if (q1.first == 0) ans += q1.second;
			if (q2.first == 0) ans += q2.second;
		}
		printf("%lld\n", ans);
	}
}