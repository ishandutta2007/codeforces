
#include <bits/stdc++.h>

using namespace std;

const int MX = 500000, md = 998244353;

int tw;
struct {
	int val, p, lSon, rSon, add, size;
} t[MX];

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> dist;

int newNode(int v) {
	t[tw].val = v;
	t[tw].p = dist(gen);
	t[tw].size = 1;
	t[tw].lSon = t[tw].rSon = t[tw].add = 0;
	
	return tw++;
}

void add(int v, int x) {
	t[v].val += x;
	t[v].add += x;
}

void push(int v) {
	add(t[v].lSon, t[v].add);
	add(t[v].rSon, t[v].add);
	t[v].add = 0;
}

// L - < t
// R - >= t
void split(int v, int y, int& L, int& R) {
	L = R = v;
	
	if (v == 0) return;
	
	push(v);
	
	if (t[v].val < y) {
		split(t[v].rSon, y, t[v].rSon, R);
	}
	else {
		split(t[v].lSon, y, L, t[v].lSon);
	}
	
	t[v].size = 1 + t[t[v].lSon].size + t[t[v].rSon].size;
}

int merge(int l, int r) {
	if (l == 0 || r == 0) return l + r;
	
	if (t[l].p > t[r].p) {
		push(l);
		t[l].size += t[r].size;
		t[l].rSon = merge(t[l].rSon, r);
		return l;
	}
	else {
		push(r);
		t[r].size += t[l].size;
		t[r].lSon = merge(l, t[r].lSon);
		return r;
	}
}

int f[MX], inv[MX], fInv[MX];

int main() {
	f[0] = f[1] = fInv[0] = fInv[1] = inv[1] = 1;
	for (int i = 2; i < MX; i++) {
		inv[i] = md - (md / i) * 1LL * inv[md % i] % md;
		f[i] = f[i - 1] * 1LL * i % md;
		fInv[i] = fInv[i - 1] * 1LL * inv[i] % md;
	}
	
	int T;
	ignore = scanf("%d", &T);
	while (T--) {
		int n, m;
		ignore = scanf("%d %d", &n, &m);
		
		tw = 1;
		
		int root = 0;
		for (int i = 0, x, y; i < m; i++) {
			ignore = scanf("%d %d", &x, &y);
			
			int L, R, M;
			split(root, y, L, R);
			split(L, y - 1, L, M);
			
			add(R, 1);
			
			root = merge(L, merge(newNode(y), R));
		}
		
		int k = t[root].size;
		
		int ans = f[2 * n - k - 1] * 1LL * fInv[n] % md * fInv[n - k - 1] % md;
		printf("%d\n", ans);
	}
	
	return 0;
}