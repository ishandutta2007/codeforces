#include <bits/stdc++.h>

using namespace std;

struct node {
	int sz;
	int cnt;
	int apply;
	int xr;
};

node t[4 * 300001];
vector<long long> temp;

node merge(node a, node b) {
	node c;
	c.sz = a.sz + b.sz;
	c.cnt = a.cnt + b.cnt;
	c.apply = -1;
	c.xr = 0;
	return c;
}

void build(int v, int l, int r) {
	if(l == r) {
		t[v].sz = 1;
		t[v].cnt = 0;
		t[v].apply = -1;
		t[v].xr = 0;
	} else {
		int m = (l + r) / 2;
		build(v * 2 + 1, l, m);
		build(v * 2 + 2, m + 1, r);
		t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
	}
}

void push(int v) {
	if(t[v].apply != -1) {
		int x = t[v].apply;
		t[v].apply = -1;
		t[v * 2 + 1].xr = t[v * 2 + 2].xr = 0;
		t[v * 2 + 1].apply = t[v * 2 + 2].apply = x;
		if(x == 0)
			t[v * 2 + 1].cnt = t[v * 2 + 2].cnt = 0;
		else {
			t[v * 2 + 1].cnt = t[v * 2 + 1].sz;
			t[v * 2 + 2].cnt = t[v * 2 + 2].sz;
		}
	}
	if(t[v].xr == 1) {
		t[v].xr = 0;
		t[v * 2 + 1].xr ^= 1;
		t[v * 2 + 2].xr ^= 1;
		t[v * 2 + 1].cnt = t[v * 2 + 1].sz - t[v * 2 + 1].cnt;
		t[v * 2 + 2].cnt = t[v * 2 + 2].sz - t[v * 2 + 2].cnt;
	}
}

void do_apply(int v, int l, int r, int l1, int r1, int x) {
	if(r < l1 || r1 < l)
		return;
	if(l1 <= l && r <= r1) {
		t[v].apply = x;
		t[v].xr = 0;
		if(x == 0)
			t[v].cnt = 0;
		else
			t[v].cnt = t[v].sz;
		return;
	}
	push(v);
	int m = (l + r) / 2;
	do_apply(v * 2 + 1, l, m, l1, r1, x);
	do_apply(v * 2 + 2, m + 1, r, l1, r1, x);
	t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
}

void do_xor(int v, int l, int r, int l1, int r1) {
	if(r < l1 || r1 < l)
		return;
	if(l1 <= l && r <= r1) {
		t[v].xr ^= 1;
		t[v].cnt = t[v].sz - t[v].cnt;
		return;
	}
	push(v);
	int m = (l + r) / 2;
	do_xor(v * 2 + 1, l, m, l1, r1);
	do_xor(v * 2 + 2, m + 1, r, l1, r1);
	t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
}

long long get(int v, int l, int r) {
	if(l == r)
		return temp[l];
	push(v);
	int m = (l + r) / 2;
	if(t[v * 2 + 1].cnt != t[v * 2 + 1].sz)
		return get(v * 2 + 1, l, m);
	return get(v * 2 + 2, m + 1, r);
}

int n;
int type[100000];
long long l[100000], r[100000];
map<long long, int> num;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> type[i] >> l[i] >> r[i];
		--l[i]; --r[i];
		num[l[i]];
		num[r[i]];
		num[r[i] + 1];
	}
	num[0];
	int m = 0;
	for(auto it = num.begin(); it != num.end(); it++) {
		it->second = m++;
		temp.push_back(it->first);
	}
	build(0, 0, m - 1);
	for(int i = 0; i < n; i++) {
		if(type[i] == 1)
			do_apply(0, 0, m - 1, num[l[i]], num[r[i]], 1);
		if(type[i] == 2)
			do_apply(0, 0, m - 1, num[l[i]], num[r[i]], 0);
		if(type[i] == 3)
			do_xor(0, 0, m - 1, num[l[i]], num[r[i]]);
		cout << get(0, 0, m - 1) + 1 << '\n';
	}
}