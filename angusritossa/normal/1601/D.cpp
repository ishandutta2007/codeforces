#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define MAXN 500010
int n, d;
int a[MAXN], s[MAXN], A[MAXN], S[MAXN];
pair<int, int> sorted[MAXN];
int rangetree[MAXN*4][2];
void update(int s, int e, int val, int curr = 1, int cstart = 0, int cend = MAXN) {
	if (s <= cstart && cend <= e) {
		rangetree[curr][0] += val;
		rangetree[curr][1] += val;
		return;
	}
	int mid = (cstart+cend)/2;
	if (e <= mid) update(s, e, val, 2*curr, cstart, mid);
	else if (s > mid) update(s, e, val, 2*curr+1, mid+1, cend);
	else {
		update(s, e, val, 2*curr, cstart, mid);
		update(s, e, val, 2*curr+1, mid+1, cend);
	}
	rangetree[curr][0] = max(rangetree[2*curr][0], rangetree[2*curr+1][0]) + rangetree[curr][1];
}
int query(int s, int e, int curr = 1, int cstart = 0, int cend = MAXN) {
	if (s <= cstart && cend <= e) return rangetree[curr][0];
	int mid = (cstart+cend)/2;
	int add = rangetree[curr][1];
	if (e <= mid) return query(s, e, 2*curr, cstart, mid) + add;
	else if (s > mid) return query(s, e, 2*curr+1, mid+1, cend) + add;
	else return max(query(s, e, 2*curr, cstart, mid), query(s, e, 2*curr+1, mid+1, cend)) + add;
}

typedef tree<int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update> ordered_set;

ordered_set se;

vector<pair<int, pair<int, int> > > events; // .first is val - .second.first is type (1 for s, 0 for a), .second.second is index

int main() {
	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &s[i], &a[i]);
		sorted[i] = { a[i] + s[i], i };
	}
	sort(sorted, sorted+n);

	for (int j = 0; j < n; j++) {
		int i = sorted[j].second;
		A[j+1] = a[i];
		S[j+1] = s[i];
		events.push_back({a[i], {0, j+1}});
		events.push_back({s[i], {1, j+1}});
	}
	events.push_back({2e9, {0, n+1}});
	events.push_back({d, {0, 0}});
	sort(events.begin(), events.end());

	reverse(events.begin(), events.end());

	for (auto e : events) {
		int i = e.second.second;
		//printf("val %d : i %d, type %d\n", e.first, i, e.second.first);
		if (e.second.first) {
			// is s

			if (S[i] >= A[i]) {
				update(i, n+1, 1);
				se.insert(i);
			} else {
				update(i, i, 1);
			}
		} else {
			int ans = query(i, n+1);
			ans -= se.order_of_key(i+1);
			//printf("ans %d\n", ans);
			update(i, i, ans);

			if (S[i] >= A[i] && i > 0 && i <= n) {
				update(i+1, n+1, -1);
				se.erase(i);
			}
		}
	}
	
	int ans = query(0, 0);

	printf("%d\n", ans);
}