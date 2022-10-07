#include <bits/stdc++.h>

const int LG = 20, U = (1 << LG) - 1;

struct Node {
	int all0, all1;
	int sz;

	Node() : all0(U), all1(U), sz(0) {}
	Node(int a0, int a1, int _sz) : all0(a0), all1(a1), sz(_sz) {}
};

Node operator+(const Node &a, const Node &b) {
	return Node(a.all0 & b.all0, a.all1 & b.all1, a.sz + b.sz);
}

struct Trie {
	Trie *son[2];
	Node a;
	int dep;
	int tag;

	Trie(int d) : dep(d), tag(0) {
		son[0] = son[1] = NULL;
	}

	~Trie() {
		delete son[0];
		delete son[1];
	}
};

void up(Trie *u) {
	u->a = (u->son[0] != NULL ? u->son[0]->a : Node()) + 
	       (u->son[1] != NULL ? u->son[1]->a : Node());
	u->a.all0 |= (u->son[1] == NULL) << (u->dep - 1);
	u->a.all1 |= (u->son[0] == NULL) << (u->dep - 1);
}

void work_xor(Trie *u, int v) {
	if (u != NULL && u->dep > 0) {
		int t = (u->a.all0 & v) ^ (u->a.all1 & v);
		u->a.all0 ^= t, u->a.all1 ^= t;
		if (v >> (u->dep - 1) & 1) {
			std::swap(u->son[0], u->son[1]);
			v ^= 1 << (u->dep - 1);
		}
		u->tag ^= v;
	}
}

void down(Trie *u) {
	work_xor(u->son[0], u->tag);
	work_xor(u->son[1], u->tag);
	u->tag = 0;
}

void insert(Trie *&u, int v, int d = LG) {
	if (u == NULL) {
		u = new Trie(d);
	}
	if (d == 0) {
		u->a = Node(0, 0, 1);
		return;
	}
	down(u);
	insert(u->son[v >> (d - 1) & 1], v, d - 1);
	up(u);
}

void split(Trie *u, int v, Trie *&x, Trie *&y) {
	if (u == NULL) {
		x = y = NULL;
		return;
	}
	if (u->dep == 0) {
		x = u;
		y = NULL;
		return;
	}
	down(u);
	if (v >> (u->dep - 1) & 1) {
		x = u;
		y = new Trie(u->dep);
		split(u->son[1], v, x->son[1], y->son[1]);
	} else {
		y = u;
		x = new Trie(u->dep);
		split(u->son[0], v, x->son[0], y->son[0]);
	}
	if (x->son[0] == NULL && x->son[1] == NULL) {
		delete x;
		x = NULL;
	} else {
		up(x);
	}
	if (y->son[0] == NULL && y->son[1] == NULL) {
		delete y;
		y = NULL;
	} else {
		up(y);
	}
}

Trie *merge(Trie *u, Trie *v) {
	if (u == NULL) {
		return v;
	}
	if (v == NULL) {
		return u;
	}
	if (u->dep == 0) {
		u->a.sz = u->a.sz || v->a.sz;
		delete v;
		return u;
	}
	down(u), down(v);
	u->son[0] = merge(u->son[0], v->son[0]);
	u->son[1] = merge(u->son[1], v->son[1]);
	up(u);
	v->son[0] = v->son[1] = NULL;
	delete v;
	return u;
}

void split(Trie *u, int l, int r, Trie *&x, Trie *&y) {
	if (l == 0) {
		split(u, r, y, x);
	} else {
		split(u, l - 1, x, y);
		Trie *z;
		split(y, r, y, z);
		x = merge(x, z);
	}
}

void work_and(Trie *u, int v) {
	if (u == NULL || u->dep == 0) {
		return;
	}
	v &= (1 << u->dep) - 1;
	if (((u->a.all0 | u->a.all1) & v) == v) {
		work_xor(u, u->a.all1 & v);
		return;
	}
	down(u);
	if (v >> (u->dep - 1) & 1) {
		u->son[0] = merge(u->son[0], u->son[1]);
		u->son[1] = NULL;
	}
	work_and(u->son[0], v);
	work_and(u->son[1], v);
	up(u);
}

void work_or(Trie *u, int v) {
	if (u == NULL || u->dep == 0) {
		return;
	}
	v &= (1 << u->dep) - 1;
	if (((u->a.all0 | u->a.all1) & v) == v) {
		work_xor(u, u->a.all0 & v);
		return;
	}
	down(u);
	if (v >> (u->dep - 1) & 1) {
		u->son[1] = merge(u->son[0], u->son[1]);
		u->son[0] = NULL;
	}
	work_or(u->son[0], v);
	work_or(u->son[1], v);
	up(u);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	Trie *rt = NULL;
	for (int i = 0; i < n; ++i) {
		int v;
		std::cin >> v;
		insert(rt, v);
	}
	
	while (q--) {
		int op, l, r;
		std::cin >> op >> l >> r;
		Trie *tmp;
		split(rt, l, r, tmp, rt);
		if (op <= 3) {
			int x;
			std::cin >> x;
			if (op == 1) {
				work_and(rt, U ^ x);
			} else if (op == 2) {
				work_or(rt, x);
			} else {
				work_xor(rt, x);
			}
		} else {
			std::cout << (rt == NULL ? 0 : rt->a.sz) << "\n";
		}
		rt = merge(rt, tmp);
	}
}