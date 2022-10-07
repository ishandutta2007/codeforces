#include <bits/stdc++.h>

const int N = 300005;

int q;

struct AC_Automaton {
	static const int C = 26;

	int cnt, rt;
	int son[N][C];
	int c[N];

	int trans[N][C];
	int fail[N];
	int sc[N];

	int new_node() {
		++cnt;
		std::fill(son[cnt], son[cnt] + C, 0);
		std::fill(trans[cnt], trans[cnt] + C, 0);
		fail[cnt] = 0;
		c[cnt] = 0;
		sc[cnt] = 0;
		return cnt;
	}

	AC_Automaton() : cnt(0) {}

	int merge_trie(int u, int v) {
		if (!u || !v) {
			return u | v;
		}
		c[u] += c[v];
		for (int i = 0; i < C; ++i) {
			son[u][i] = merge_trie(son[u][i], son[v][i]);
		}
		return u;
	}

	void build(int rt) {
		std::vector<int> Q;
		fail[rt] = 0;
		for (int i = 0; i < C; ++i) {
			if (!son[rt][i]) {
				trans[rt][i] = rt;
			} else {
				trans[rt][i] = son[rt][i];
				fail[trans[rt][i]] = rt;
				Q.push_back(trans[rt][i]);
			}
		}
		for (int k = 0; k < (int)Q.size(); ++k) {
			int u = Q[k];
			sc[u] = sc[fail[u]] + c[u];
			for (int i = 0; i < C; ++i) {
				int v = son[u][i];
				if (v) {
					trans[u][i] = v;
					fail[v] = trans[fail[u]][i];
					Q.push_back(v);
				} else {
					trans[u][i] = trans[fail[u]][i];
				}
			}
		}
	}

	int insert(const std::string &a) {
		int rt = new_node();
		int u = rt;
		for (int i = 0; i < (int)a.size(); ++i) {
			if (!son[u][a[i] - 'a']) {
				son[u][a[i] - 'a'] = new_node();
			}
			u = son[u][a[i] - 'a'];
		}
		++c[u];
		build(rt);
		return rt;
	}

	int merge(int u, int v) {
		int t = merge_trie(u, v);
		build(t);
		return t;
	}

	long long count(int u, const std::string &S) {
		long long ans = 0;
		for (int i = 0; i < (int)S.size(); ++i) {
			u = trans[u][S[i] - 'a'];
			ans += sc[u];
		}
		return ans;
	}
} T;

struct Stack {
	int top, rt[N], sz[N];

	Stack() : top(0) {}

	void merge() {
		while (top > 1 && sz[top] == sz[top - 1]) {
			--top;
			rt[top] = T.merge(rt[top], rt[top + 1]);
			sz[top] += sz[top + 1];
		}
	}

	void push(const std::string &s) {
		rt[++top] = T.insert(s);
		sz[top] = 1;
		merge();
	}

	long long count(const std::string &s) {
		long long res = 0;
		for (int i = 1; i <= top; ++i) {
			res += T.count(rt[i], s);
		}
		return res;
	}
} S1, S2;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> q;
	while (q--) {
		int op;
		std::string s;
		std::cin >> op >> s;
		if (op == 1) {
			S1.push(s);
		} else if (op == 2) {
			S2.push(s);
		} else {
			std::cout << S1.count(s) - S2.count(s) << std::endl;
		}
	}
}