#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
#define MAXN 200010
typedef long long ll;
int n, a[MAXN];
int afterBigger[MAXN], beforeSmaller[MAXN];
int rangetree[MAXN*4];
void update(int node, int val, int curr = 1, int cstart = 0, int cend = MAXN) {
	if (cstart == cend) {
		rangetree[curr] = val;
		return;
	}
	int mid = (cstart+cend)/2;
	if (node <= mid) update(node, val, 2*curr, cstart, mid);
	else if (node > mid) update(node, val, 2*curr+1, mid+1, cend);
	rangetree[curr] = min(rangetree[2*curr], rangetree[2*curr+1]);
}

int query(int s, int e, int curr = 1, int cstart = 0, int cend = MAXN) {
	if (s <= cstart && cend <= e) {
		return rangetree[curr];
	}
	int mid = (cstart+cend)/2;
	if (e <= mid) return query(s, e, 2*curr, cstart, mid);
	else if (s > mid) return query(s, e, 2*curr+1, mid+1, cend);
	else {
		return min(query(s, e, 2*curr, cstart, mid), query(s, e, 2*curr+1, mid+1, cend));
	}
}
vector<int> beforeAt[MAXN], afterAt[MAXN];
void findLimits(int* limit) {
	// find the first value before that is smaller
	stack<int> s;
	s.push(0);
	for (int i = 1; i <= n; i++) {
		while (a[s.top()] > a[i]) s.pop();
		beforeSmaller[i] = s.top();
		s.push(i);
		beforeAt[i].clear();
		afterAt[i].clear();
	}

	while (s.size()) s.pop();

	s.push(n+1);
	a[n+1] = 1e9;
	for (int i = n; i >= 1; i--) {
		while (a[s.top()] < a[i]) s.pop();
		afterBigger[i] = s.top();
		s.push(i);
	}

	fill_n(rangetree, 4*MAXN, 1e9);

	for (int i = 1; i <= n; i++) {
		beforeAt[beforeSmaller[i]].push_back(i);
		afterAt[afterBigger[i]].push_back(i);
		limit[i] = 1e9;
	}

	for (int i = n; i >= 1; i--) {
		for (auto b : beforeAt[i]) {
			update(a[b], b);
		}
		for (auto b : afterAt[i]) {
			int res = query(0, a[b]-1);
			limit[b] = res;
			//D("i = %d, res = %d\n", i, res);
		}
	}
}

int limit1[MAXN], limit2[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	findLimits(limit1);
	for (int i = 1; i <= n; i++) {
		a[i] = n+1-a[i];
	}
	findLimits(limit2);

	ll ans = 0;
	ll mn = n+1;
	for (ll i = n; i >= 1; i--) {
		mn = min(mn, (ll)limit1[i]);
		mn = min(mn, (ll)limit2[i]);
		D("i=%lld, mn=%lld\n", i, mn);
		ans += mn-i;
	}
	printf("%lld\n", ans);
}