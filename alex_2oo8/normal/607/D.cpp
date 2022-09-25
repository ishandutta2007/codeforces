#include<bits/stdc++.h>

#define pow ololo

using namespace std;

const int MX = 300000, md = 1000000007;

struct {
	int l, r, lSon, rSon, mult, sum;
} t[4 * MX];

vector<int> G[MX];
int pos[MX], last[MX];

long long pow(long long x, int p) {
	long long r = 1;
	while (p) {
		if (p % 2) r = (r * x) % md;
		
		x = (x * x) % md;
		p /= 2;
	}
	
	return r;
}

void dfs(int v) {
	static int t = 0;
	
	pos[v] = t++;
	
	for (int u : G[v]) dfs(u);
	
	last[v] = t - 1;
}

int build_tree(int l, int r) {
	static int tw = 0;
	int v = ++tw;
	
	t[v].l = l;
	t[v].r = r;
	t[v].mult = 1;
	t[v].sum = 0;
	if (l < r) {
		t[v].lSon = build_tree(l, (l + r) / 2);
		t[v].rSon = build_tree((l + r) / 2 + 1, r);
	}
	
	return v;
}

void add(int v, int x, int delta) {
	if (t[v].l == t[v].r) {
		t[v].sum = t[v].mult * 1ll * delta % md;
		
		return;
	}
	
	if (x <= t[t[v].lSon].r) add(t[v].lSon, x, delta);
	else add(t[v].rSon, x, delta);
	
	t[v].sum = t[v].mult * 1ll * (t[t[v].lSon].sum + t[t[v].rSon].sum) % md;
}

void mult(int v, int l, int r, int p) {
	if (l <= t[v].l && t[v].r <= r) {
		t[v].mult = (t[v].mult * 1ll * p) % md;
		t[v].sum = (t[v].sum * 1ll * p) % md;
		
		return;
	}
	
	if (t[t[v].lSon].r >= l) mult(t[v].lSon, l, r, p);
	if (t[t[v].rSon].l <= r) mult(t[v].rSon, l, r, p);
	
	t[v].sum = t[v].mult * 1ll * (t[t[v].lSon].sum + t[t[v].rSon].sum) % md;
}

int query(int v, int l, int r) {
	if (l <= t[v].l && t[v].r <= r) return t[v].sum;
	
	int res = 0;
	if (t[t[v].lSon].r >= l) res += query(t[v].lSon, l, r);
	if (t[t[v].rSon].l <= r) res += query(t[v].rSon, l, r);
	
	return t[v].mult * 1ll * res % md;
}

int prod(int v, int x) {
	if (t[v].l == t[v].r) return t[v].mult;
	
	if (x <= t[t[v].lSon].r) return t[v].mult * 1ll * prod(t[v].lSon, x) % md;
	else return t[v].mult * 1ll * prod(t[v].rSon, x) % md;
}

int T[MX], p[MX], v[MX], s[MX], inv[MX];

int main() {
	int v1, q, n = 1;
	scanf("%d %d", &v1, &q);
	for (int i = 0; i < q; i++) {
		scanf("%d", T + i);
		if (T[i] == 1) {
			scanf("%d %d", p + i, v + i);
			p[i]--;
			
			G[p[i]].push_back(n++);
		}
		else {
			scanf("%d", v + i);
			v[i]--;
		}
	}
	
	for (int i = 0; i < n; i++) s[i] = 1;
	
	dfs(0);
	
	build_tree(0, n - 1);
	
	inv[1] = 1;
	for (int i = 2; i < n; i++) inv[i] = md - ((md / i) * 1ll * inv[md % i]) % md;
	
	add(1, pos[0], v1);
	
	for (int i = 0, k = 1; i < q; i++)
		if (T[i] == 1) {
			mult(1, pos[p[i]], last[p[i]], (inv[s[p[i]]] * 1ll * (s[p[i]] + 1)) % md);
			s[p[i]]++;
			
			add(1, pos[k++], v[i]);
		}
		else {
			int ans = query(1, pos[v[i]], last[v[i]]);
			ans = (ans * pow(prod(1, pos[v[i]]), md - 2)) % md;
			ans = (s[v[i]] * 1ll * ans) % md;
			printf("%d\n", ans);
		}
	
	return 0;
}