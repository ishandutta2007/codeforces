#include<bits/stdc++.h>

using namespace std;

const int MX = 400000;

struct {
	int l, r, debt, lSon, rSon;
	long long mask;
} t[2 * MX];

vector<int> G[MX];
int first[MX], last[MX], c[MX], id[MX];

void dfs(int v, int par = -1) {
	static int k = 0;
	
	first[v] = k;
	id[k++] = v;
	
	for (int u : G[v]) if (u != par) dfs(u, v);
	
	last[v] = k - 1;
}

int build_tree(int l, int r) {
	static int tw = 0;
	int v = ++tw;
	
	t[v].l = l;
	t[v].r = r;
	t[v].debt = -1;
	if (l == r) t[v].mask = 1ll << c[id[l]];
	else {
		t[v].lSon = build_tree(l, (l + r) / 2);
		t[v].rSon = build_tree((l + r) / 2 + 1, r);
		
		t[v].mask = t[t[v].lSon].mask | t[t[v].rSon].mask;
	}
	
	return v;
}

void update(int v, int l, int r, int c) {
	if (l <= t[v].l && t[v].r <= r) {
		t[v].mask = 1ll << c;
		t[v].debt = c;
		
		return;
	}
	
	if (t[v].debt != -1) {
		update(t[v].lSon, t[v].l, t[v].r, t[v].debt);
		update(t[v].rSon, t[v].l, t[v].r, t[v].debt);
		
		t[v].debt = -1;
	}
	
	if (t[t[v].lSon].r >= l) update(t[v].lSon, l, r, c);
	if (t[t[v].rSon].l <= r) update(t[v].rSon, l, r, c);
	
	t[v].mask = t[t[v].lSon].mask | t[t[v].rSon].mask;
}

long long query(int v, int l, int r) {
	if (l <= t[v].l && t[v].r <= r) return t[v].mask;
	if (t[v].debt != -1) return t[v].mask;
	
	long long res = 0;
	if (t[t[v].lSon].r >= l) res |= query(t[v].lSon, l, r);
	if (t[t[v].rSon].l <= r) res |= query(t[v].rSon, l, r);
	
	return res;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", c + i);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		
		u--;
		v--;
		
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs(0);
	
	build_tree(0, n - 1);
	
	for (int i = 0; i < m; i++) {
		int t, v;
		scanf("%d %d", &t, &v);
		
		v--;
		
		if (t == 1) {
			int c;
			scanf("%d", &c);
			
			update(1, first[v], last[v], c);
		}
		else {
			long long mask = query(1, first[v], last[v]);
			
			int ans = 0;
			while (mask) {
				ans += mask % 2;
				
				mask /= 2;
			}
			
			printf("%d\n", ans);
		}
	}
	
	return 0;
}