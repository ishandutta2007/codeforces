#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
inline void NO() {
	puts("0");
	exit(0);
}
int n, vis[105], fact[105];
namespace PQ {
	const int V = 50005;
	struct Node {
		int ty; // 0 for P, 1 for Q
		bool full, empty;
		vector<int> son;
	} tr[V];
	int tot, rt;
	inline int newnode(int ty) {
		tr[++tot].ty = ty;
		return tot;
	}
	inline bool isleaf(int u) {
		return u >= 1 && u <= n;
	}
	inline void Init() {
		tot = 0;
		rt = n + 1;
		for (int i = 1; i <= n; i++) tr[rt].son.push_back(newnode(1));
		newnode(0);
	}
	void fix(int u) {
		vector<int> nson;
		for (int v : tr[u].son) {
			fix(v);
			while (tr[v].son.size() == 1) v = tr[v].son[0];
			if (isleaf(v) || !tr[v].son.empty()) nson.push_back(v);
		}
		tr[u].son.swap(nson);
	}
	void dfs(int u) {
		if (isleaf(u)) {
			tr[u].full = vis[u];
			tr[u].empty = !vis[u];
			return;
		}
		tr[u].full = tr[u].empty = 1;
		for (int v : tr[u].son) {
			dfs(v);
			tr[u].full &= tr[v].full;
			tr[u].empty &= tr[v].empty;
		}
	}
	vector<int> split(int u) {
		if (tr[u].full || tr[u].empty) return {u};
		vector<int> nson;
		if (tr[u].ty) {
			if (tr[tr[u].son[0]].empty || tr[tr[u].son.back()].full) reverse(tr[u].son.begin(), tr[u].son.end());
			int l = V, r = -1;
			for (int i = 0; i < (int)tr[u].son.size(); i++) if (!tr[tr[u].son[i]].empty) {
				l = min(l, i);
				r = max(r, i);
			}
			if (l) NO();
			for (int i = 0; i < (int)tr[u].son.size(); i++) {
				int v = tr[u].son[i];
				if (!tr[v].full && i >= l && i < r) NO();
				if (tr[v].full || tr[v].empty) nson.push_back(v);
				else {
					vector<int> cur = split(v);
					nson.insert(nson.end(), cur.begin(), cur.end());
				}
			}
		} else {
			int x0 = newnode(0), x1 = newnode(0);
			bool flag = 0;
			nson.push_back(x1);
			for (int v : tr[u].son) {
				if (!tr[v].empty) {
					if (!tr[v].full) {
						if (flag) NO();
						flag = 1;
						vector<int> cur = split(v);
						nson.insert(nson.end(), cur.begin(), cur.end());
					} else tr[x1].son.push_back(v);
				} else tr[x0].son.push_back(v);
			}
			nson.push_back(x0);
		}
		return nson;
	}
	void work(int u) {
		if (tr[u].full || tr[u].empty) return;
		if (tr[u].ty) {
			int l = V, r = -1;
			for (int i = 0; i < (int)tr[u].son.size(); i++) if (!tr[tr[u].son[i]].empty) {
				l = min(l, i);
				r = max(r, i);
			}
			if (l == r) {
				work(tr[u].son[l]);
				return;
			}
			vector<int> nson;
			for (int i = 0; i < (int)tr[u].son.size(); i++) {
				int v = tr[u].son[i];
				if (!tr[v].full && i > l && i < r) NO();
				if (tr[v].full || tr[v].empty) nson.push_back(v);
				else {
					vector<int> cur = split(v);
					if (i == l) reverse(cur.begin(), cur.end());
					nson.insert(nson.end(), cur.begin(), cur.end());
				}
			}
			tr[u].son.swap(nson);
		} else {
			int tot = 0;
			for (int v : tr[u].son) tot += !tr[v].empty;
			if (tot == 1) {
				for (int v : tr[u].son) if (!tr[v].empty) {
					work(v);
					return;
				}
			}
			vector<int> nson;
			int x0 = newnode(1), x1 = newnode(0), cnt = 0;
			nson.push_back(x0);
			for (int v : tr[u].son) {
				if (tr[v].empty) nson.push_back(v);
				else {
					if (tr[v].full) tr[x1].son.push_back(v);
					else {
						cnt++;
						if (cnt > 2) NO();
						vector<int> cur = split(v);
						if (cnt == 1) reverse(cur.begin(), cur.end());
						tr[x0].son.insert(tr[x0].son.end(), cur.begin(), cur.end());
						if (cnt == 1) tr[x0].son.push_back(x1);
					}
				}
			}
			if (!cnt) nson.push_back(x1);
			tr[u].son.swap(nson);
		}
	}
	void add() {
		dfs(rt);
		work(rt);
		fix(rt);
		while (tr[rt].son.size() == 1) rt = tr[rt].son[0];
	}
	int findans(int u = rt) {
		if (isleaf(u)) return 1;
		int res = (tr[u].ty ? 2 : fact[tr[u].son.size()]);
		for (int v : tr[u].son) res = 1ll * res * findans(v) % mod;
		return res;
	}
}
int main() {
	int m;
	scanf("%d%d", &n, &m);
	for (int i = fact[0] = 1; i <= n; i++) fact[i] = 1ll * fact[i - 1] * i % mod;
	PQ::Init();
	while (m--) {
		for (int i = 1; i <= n; i++) vis[i] = 0;
		int c;
		scanf("%d", &c);
		while (c--) {
			int x;
			scanf("%d", &x);
			vis[x] = 1;
		}
		PQ::add();
	}
	printf("%d\n", PQ::findans());
	return 0;
}