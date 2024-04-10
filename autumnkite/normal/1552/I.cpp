#include <bits/stdc++.h>

class basic_PQ_tree {
protected:
	struct node {
		std::vector<node *> son;
		int type, op;

		node(int tp) : son(), type(tp), op(0) {}
	};

	int n;

	node *rt;
	std::vector<node *> p;

	bool ok;

	void init_op(node *u) {
		if (u->son.empty()) {
			return;
		}
		u->op = 0;
		for (auto v : u->son) {
			init_op(v);
			u->op |= v->op;
		}
	}

	bool dfs(node *u, int lim) {
		if (u->op != 3) {
			return true;
		}
		std::vector<node *> a[4];
		for (auto v : u->son) {
			a[v->op].push_back(v);
		}
		if ((int)a[3].size() > 2 - (lim > 0)) {
			return false;
		}
		if (lim == 0 && (int)(a[2].size() + a[3].size()) == 1) {
			if (!a[2].empty()) {
				return dfs(a[2][0], 0);
			} else {
				return dfs(a[3][0], 0);
			}
		}
		if (u->type) {
			if (u->son.front()->op == 2 || u->son.back()->op == 1) {
				std::reverse(u->son.begin(), u->son.end());
			}
			int now = 0;
			std::vector<node *> tmp;
			for (auto v : u->son) {
				if (v->op == 1) {
					tmp.push_back(v);
					now += now == 1;
				} else {
					if (now == 2) {
						return false;
					}
					if (v->op == 2) {
						tmp.push_back(v);
						now += now == 0;
					} else {
						++now;
						if (!dfs(v, now == 1 ? 2 : 1)) {
							return false;
						}
						tmp.insert(tmp.end(), v->son.begin(), v->son.end());
						delete v;
					}
				}
			}
			if (lim > 0) {
				if (now == 2) {
					return false;
				}
				if (lim == 1) {
					std::reverse(tmp.begin(), tmp.end());
				}
			}
			u->son.swap(tmp);
		} else {
			node *z = nullptr;
			if ((int)a[2].size() == 1) {
				z = a[2][0];
			} else if ((int)a[2].size() > 1) {
				z = new node(0);
				z->son = a[2];
			}
			std::vector<node *> tmp;
			for (int i = 0; i < (int)a[3].size(); ++i) {
				auto v = a[3][i];
				if (!dfs(v, i == 0 ? 2 : 1)) {
					return false;
				}
				tmp.insert(tmp.end(), v->son.begin(), v->son.end());
				delete v;
				if (i == 0 && z != nullptr) {
					tmp.push_back(z);
				}
			}
			if (tmp.empty() && z != nullptr) {
				tmp.push_back(z);
			}
			if (a[1].empty()) {
				if (lim == 1) {
					std::reverse(tmp.begin(), tmp.end());
				}
				u->type = 1;
				u->son.swap(tmp);
			} else if (lim) {
				node *z;
				if ((int)a[1].size() > 1) {
					z = new node(0);
					z->son = a[1];
				} else {
					z = a[1][0];
				}
				tmp.insert(tmp.begin(), z);
				if (lim == 1) {
					std::reverse(tmp.begin(), tmp.end());
				}
				u->type = 1;
				u->son.swap(tmp);
			} else {
				node *z;
				if ((int)tmp.size() > 1) {
					z = new node(1);
					z->son = tmp;
				} else {
					z = tmp[0];
				}
				u->son = a[1];
				u->son.push_back(z);
			}
		}
		return true;
	}

public:
	basic_PQ_tree(int _n) : n(_n), rt(new node(0)), p(n), ok(true) {
		for (int i = 0; i < n; ++i) {
			p[i] = new node(0);
			rt->son.push_back(p[i]);
		}
	}

	void insert(const std::vector<int> &a) {
		if (!ok) {
			return;
		}
		for (int i = 0; i < n; ++i) {
			p[i]->op = 1;
		}
		for (int i : a) {
			p[i]->op = 2;
		}
		init_op(rt);
		ok &= dfs(rt, 0);
	}

	bool valid() {
		return ok;
	}
};

template<int P>
class PQ_tree : public basic_PQ_tree {
	std::vector<int> fac;

	int calc(node *u) {
		if (u->son.empty()) {
			return 1;
		}
		int res = u->type ? 2 : fac[u->son.size()];
		for (auto v : u->son) {
			res = 1ll * res * calc(v) % P;
		}
		return res;
	}

public:
	PQ_tree(int _n) : basic_PQ_tree(_n), fac(n + 1) {
		fac[0] = 1;
		for (int i = 1; i <= n; ++i) {
			fac[i] = 1ll * fac[i - 1] * i % P;
		}
	}

	int get_ans() {
		return valid() ? calc(rt) : 0;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n, m;
	std::cin >> n >> m;
	PQ_tree<998244353> T(n);
	for (int i = 0; i < m; ++i) {
		int k;
		std::cin >> k;
		std::vector<int> id(k);
		for (int &x : id) {
			std::cin >> x;
			--x;
		}
		T.insert(id);
	}
	std::cout << T.get_ans() << "\n";
}