#include <bits/stdc++.h>

using namespace std;

struct twosat {
    int n;
    vector <vector <int> > G, R;
    vector <int> order, comp, ans;
    vector <bool> vis;

    twosat() {}
    twosat(int _n) : n(_n) {
        G.resize(n + n);
        R.resize(n + n);
        comp.resize(n + n);
        vis.resize(n + n);
        ans.resize(n);
        order.reserve(n + n);
    }

    void add_edge(int u, int v) {
        G[u].push_back(v);
        R[v].push_back(u);
    }

    /* 0-indexed, subtract if necessary */
    void add_clause(int u, bool fu, int v, bool fv) {
        add_edge(u << 1 | !fu, v << 1 | fv);
        add_edge(v << 1 | !fv, u << 1 | fu);
    }

    void dfs(int u) {
        vis[u] = true;
        for (const auto &v: G[u])
            if (!vis[v])    dfs(v);
        order.push_back(u);
    }

    void scc(int u, int id) {
        vis[u] = true, comp[u] = id;
        for (const auto &v: R[u])
            if (!vis[v])    scc(v, id);
    }

    bool run() {
        for (int i = 0; i < n + n; ++i) 
            if (!vis[i])    dfs(i);
        
        fill(vis.begin(), vis.end(), false);
        reverse(order.begin(), order.end());

        int cnt = 0;
        for (const auto &v: order)
            if (!vis[v])    scc(v, ++cnt);
        
        for (int i = 0; i < n; ++i) {
            if (comp[i << 1] == comp[i << 1 | 1])   return false;
            ans[i] = comp[i << 1] < comp[i << 1 | 1];
        }

        return true;
    }
};

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	
	twosat instance(n);
	for (int i = 1; i <= m; ++i) {
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		
		u--, v--;
		instance.add_clause(u, 0, v, c);
		instance.add_clause(u, 1, v, !c);
	}
	
	if (!instance.run()) {
		puts("Impossible");
	} else {
		vector <int> ans;
		for (int i = 0; i < n; ++i) {
			if (instance.ans[i]) {
				ans.push_back(i);
			}
		}
		
		printf("%lu\n", ans.size());
		for (auto v: ans)
			printf("%d ", v + 1);
		puts("");
	}

	return 0;
}