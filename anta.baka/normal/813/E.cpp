#include <bits/stdc++.h>

using namespace std;

struct node {
	int s;
	node *l, *r;
};

typedef node *pnode;

int n, k;
vector<pnode> root;
vector<int> mem[100000];
int q;

pnode build(int l, int r) {
	pnode res = new node;
	if(l == r) {
		res->s = 0;
		res->l = res->r = NULL;
	} else {
		int m = (l + r) / 2;
		res->l = build(l, m);
		res->r = build(m + 1, r);
		res->s = res->l->s + res->r->s;
	}
	return res;
}

pnode modify(pnode t, int l, int r, int pos, int x) {
	pnode res = new node;
	if(l == r) {
		res->s = x;
		res->l = res->r = NULL;
	} else {
		int m = (l + r) / 2;
		if(pos <= m) {
			res->l = modify(t->l, l, m, pos, x);
			res->r = t->r;
		} else {
			res->l = t->l;
			res->r = modify(t->r, m + 1, r, pos, x);
		}
		res->s = res->l->s + res->r->s;
	}
	return res;
}

int get(pnode t, int l, int r, int l1, int r1) {
	if(r < l1 || r1 < l)
		return 0;
	if(l1 <= l && r <= r1)
		return t->s;
	int m = (l + r) / 2;
	return get(t->l, l, m, l1, r1) + get(t->r, m + 1, r, l1, r1);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	root.push_back(build(0, n - 1));
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		--x;
		mem[x].push_back(i);
		pnode t = root.back();
		if(mem[x].size() > k)
			t = modify(t, 0, n - 1, mem[x][mem[x].size() - k - 1], 0);
		root.push_back(modify(t, 0, n - 1, i, 1));
	}
	cin >> q;
	int lst = 0;
	for(int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		int l = (x + lst) % n;
		int r = (y + lst) % n;
		if(l > r)
			swap(l, r);
		lst = get(root[r + 1], 0, n - 1, l, r);
		cout << lst << '\n';
	}
}