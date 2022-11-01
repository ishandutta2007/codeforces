#include <bits/stdc++.h>

using namespace std;

struct state {
	int l, r, sz;
	state() { l = -1, r = -1, sz = 0; }
};

int n, q;
vector<int> a;
vector<state> t(1);
int sz = 1;
int xr;

inline bool bit(int x, int i) {
	return (x & (1 << i));
}

inline void add(int x) {
	int v = 0;
	for(int i = 18; i >= 0; i--) {
		if(!bit(x, i)) {
			if(t[v].l == -1) { t[v].l = sz; t.push_back(state()); sz++; }
			v = t[v].l;
		} else {
			if(t[v].r == -1) { t[v].r = sz; t.push_back(state()); sz++; }
			v = t[v].r;
		}
		t[v].sz++;
	}
}

inline int query() {
	int v = 0, ret = 0;
	for(int i = 18; i >= 0; i--) {
		int l = t[v].l, r = t[v].r;
		if(bit(xr, i)) swap(l, r);
		if(t[l].sz != 1 << i) v = l;
		else v = r, ret += 1 << i;
		if(v == -1) break;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	a.resize(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	for(int x : a) add(x);
	while(q--) {
		int x;
		cin >> x;
		xr ^= x;
		cout << query() << '\n';
	}
}