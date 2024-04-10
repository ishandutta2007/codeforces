#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;
const int maxl = 18;

deque<int> pre[maxn];
int newint = 1, root[maxn], seg[maxn * maxl], lc[maxn * maxl], rc[maxn * maxl];

int add(int id, int L, int R, int idx){
	if (idx < L or R <= idx)
		return id;
	int me = newint ++;
	seg[me] = seg[id] + 1;
	if (L + 1 == R)
		return me;
	int mid = (L + R) >> 1;
	lc[me] = add(lc[id], L, mid, idx);
	rc[me] = add(rc[id], mid, R, idx);
	return me;
}

int get(int id, int L, int R, int l, int r){
	if (R <= l or r <= L)
		return 0;
	if (l <= L and R <= r)
		return seg[id];
	int mid = (L + R) >> 1;
	return get(lc[id], L, mid, l, r) + get(rc[id], mid, R, l, r);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<pair<int, int> > events;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		int y;
		if (pre[x].size() == k)
			y = pre[x].front();
		else
			y = 0;
		pre[x].push_back(i);
		if (pre[x].size() > k)
			pre[x].pop_front();
		events.push_back({y, i});
	}
	sort(events.begin(), events.end());
	for (int i = 1; i <= n; i++)
		root[i] = add(root[i - 1], 1, n + 1, events[i - 1].second);
	int last = 0;
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++){
		int x, y;
		cin >> x >> y;
		int l = ((x + last) % n) + 1;
		int r = ((y + last) % n) + 1;
		if (l > r)
			swap(l, r);
		int lo = -1, hi = n;
		while (hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if (events[mid].first < l)
				lo = mid;
			else
				hi = mid;
		}
		last = get(root[hi], 1, n + 1, l, r + 1);
		cout << last << '\n';
	}
}