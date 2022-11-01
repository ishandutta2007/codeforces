#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 9;

struct fen {
	int n; vector<int> t;
	fen(int _n) { n = _n; t.resize(n, 0); }
	void upd(int v, int x) {
		for(int i = v; i < n; i |= i + 1) t[i] += x;
	}
	int get(int v) {
		int res = 0;
		for(int i = v; i >= 0; i = (i & (i + 1)) - 1) res += t[i];
		return res;
	}
	int sum(int l, int r) { return get(r) - get(l - 1); }
};

struct segTree {
	int n; vector<pair<int, int>> t;
	segTree(int _n) {
		n = _n;
		t.resize(2 * n, {0, 0});
	}
	void upd(int v, pair<int, int> x) {
		t[v += n] = x;
		for(v >>= 1; v; v >>= 1) t[v] = min(t[v * 2], t[v * 2 + 1]);
	}
	pair<int,int> get(int l, int r) {
		pair<int, int> res = {INF, INF};
		for(l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
			if(l&1) res = min(res, t[l]);
			if(!(r & 1)) res = min(res, t[r]);
		}
		return res;
	}
};

int n;
int a[100000];
set<int> b[100001];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	fen t1(n);
	segTree t2(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		t1.upd(i, 1);
		t2.upd(i, {a[i], i});
		b[a[i]].insert(i);
	}
	long long ans = 0;
	int pt = 0;
	int step = n;
	if(t2.get(0, n - 1).first == a[0]) {
		ans++;
		t1.upd(0, -1);
		t2.upd(0, {INF, INF});
		step--;
	}
	for(int i = 0; i < step; i++) {
		int x = t2.get(0, n - 1).first;
		auto it = b[x].insert(pt).first;
		it++;
		int idx;
		if(it == b[x].end()) idx = *b[x].begin();
		else idx = *it;
		if(idx >= pt) ans += t1.sum(pt, idx);
		else ans += t1.sum(pt, n - 1) + t1.sum(0, idx);
		t1.upd(idx, -1);
		t2.upd(idx, {INF, INF});
		pt = idx;
		b[x].erase(idx);
	}
	cout << ans;
}