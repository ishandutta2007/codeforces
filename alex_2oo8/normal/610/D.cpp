#include<bits/stdc++.h>

using namespace std;

struct {
	int l, r, lSon, rSon, sum;
} t[6000000];

int build_tree(int l, int r) {
	static int tw = 0;
	int v = ++tw;
	
	t[v].l = l;
	t[v].r = r;
	t[v].sum = 0;
	
	return v;
}

void update(int v, int x, int d) {
	t[v].sum += d;
	if (t[v].l == t[v].r) return;
	
	int c = t[v].l + (t[v].r - t[v].l) / 2;
	if (x <= c) {
		if (t[v].lSon == 0) t[v].lSon = build_tree(t[v].l, c);
		
		update(t[v].lSon, x, d);
	}
	else {
		if (t[v].rSon == 0) t[v].rSon = build_tree(c + 1, t[v].r);
		
		update(t[v].rSon, x, d);
	}
}

int query(int v, int l, int r) {
	if (l <= t[v].l && t[v].r <= r) return t[v].sum;
	
	int res = 0;
	if (t[v].lSon > 0 && t[t[v].lSon].r >= l) res += query(t[v].lSon, l, r);
	if (t[v].rSon > 0 && t[t[v].rSon].l <= r) res += query(t[v].rSon, l, r);
	
	return res;
}

void merge(vector< pair< int, pair<int, int> > > &v) {
	if (v.size() == 0) return;
	
	sort(v.begin(), v.end());
	
	int k = 1;
	for (int i = 1; i < v.size(); i++) {
		if (v[i].first != v[k - 1].first || v[i].second.first > v[k - 1].second.second) {
			v[k++] = v[i];
			
			continue;
		}
		
		v[k - 1].second.second = max(v[i].second.second, v[k - 1].second.second);
	}
	
	v.resize(k);
}

vector< pair< int, pair<int, int> > > hor, ver, events;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		
		if (x1 == x2) hor.push_back(make_pair(x1, make_pair(min(y1, y2), max(y1, y2))));
		else ver.push_back(make_pair(y1, make_pair(min(x1, x2), max(x1, x2))));
	}
	
	merge(hor);
	merge(ver);
	
	long long ans = 0;
	for (auto it : hor) {
		events.push_back(make_pair(it.second.first , make_pair(it.first, +1)));
		events.push_back(make_pair(it.second.second + 1, make_pair(it.first, -1)));
		
		ans += it.second.second - it.second.first + 1;
	}
	
	sort(events.begin(), events.end());
	
	build_tree(-1000000000, 1000000000);
	
	int i = 0;
	for (auto it : ver) {
		while (i < events.size() && events[i].first <= it.first) {
			update(1, events[i].second.first, events[i].second.second);
			
			i++;
		}
		
		ans += it.second.second - it.second.first + 1 - query(1, it.second.first, it.second.second);
	}
	
	printf("%lld\n", ans);
	
	return 0;
}