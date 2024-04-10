#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<vector<int>> gr;
vector<bitset<1000>> t;
vector<int> tAdd, ta, tar, a, b;
int n, m, d;
bitset<1000> pri, ans;

inline void TRonAR(int v, int p, int pv) {
	ta[v] = p;
	tar[v] = p;
	for(int i = 0, lim = sz(gr[v]); i < lim; i++) {
	    int to = gr[v][i];
		if(to != pv) {
			TRonAR(to, tar[v]+1, v);
			tar[v] = tar[to];
		}
	}
}

inline void build(int v, int vl, int vr) {
	if(vl == vr) {
		t[v].reset();
		t[v].set(b[vl]);
		return;
	}
	int vm = (vl + vr) >> 1;
	build(v*2+1, vl, vm);
	build(v*2+2, vm+1, vr);
	t[v] = t[v*2+1] | t[v*2+2];
}

inline void push(int v, int vl, int vr) {
    tAdd[v] %= m;
	if(tAdd[v]) {
		if(vl != vr) {
			tAdd[v*2+1] = (tAdd[v*2+1] + tAdd[v]) % m;
			tAdd[v*2+2] = (tAdd[v*2+2] + tAdd[v]) % m;
		}
		t[v] = (((t[v] << tAdd[v]) | (t[v] >> (m - tAdd[v]))) << d) >> d;
		tAdd[v] = 0;
	}
}

inline void add(int v, int vl, int vr, int l, int r, int val) {
	push(v, vl, vr);
	if(r < vl || vr < l)
		return;
	if(l <= vl && vr <= r) {
		tAdd[v] = val;
		push(v, vl, vr);
		return;
	}
	int vm = (vl + vr) >> 1;
	add(v*2+1, vl, vm, l, r, val);
	add(v*2+2, vm+1, vr, l, r, val);
	t[v] = t[v*2+1] | t[v*2+2];
}

inline void que(int v, int vl, int vr, int l, int r) {
	push(v, vl, vr);
	if(r < vl || vr < l)
		return;
	if(l <= vl && vr <= r) {
		ans |= t[v];
		return;
	}
	int vm = (vl + vr) >> 1;
	que(v*2+1, vl, vm, l, r);
	que(v*2+2, vm+1, vr, l, r);
}

int main() {
	scanf("%d%d", &n, &m);
	d = 1000 - m;
	a.resize(n);
	for(int i = 0; i < n; i++)
	    scanf("%d", &a[i]);
	gr.resize(n);
	for(int i = 1; i < n; i++) {
		int u, v;
	    scanf("%d%d", &u, &v);
		--u; --v;
		gr[u].pb(v);
		gr[v].pb(u);
	}
	int q;
	scanf("%d", &q);
	t.resize(4*n);
	tAdd.resize(4*n, 0);
	ta.resize(n);
	tar.resize(n);
	TRonAR(0, 0, -1);
	b.resize(n);
	for(int i = 0; i < n; i++)
		b[ta[i]] = a[i] % m;
	build(0, 0, n-1);
	pri.set();
	pri.reset(0);
	pri.reset(1);
	for(int i = 2; i * i < 1000; i++)
		for(int j = i * i; j < 1000; j += i)
			pri.reset(j);
	for(int i = 0; i < q; i++) {
		int type;
		scanf("%d", &type);
		if(type == 1) {
			int v, x;
			scanf("%d%d", &v, &x);
			--v;
			add(0, 0, n-1, ta[v], tar[v], x % m);
		} else {
			int v;
			scanf("%d", &v);
			--v;
			ans.reset();
			que(0, 0, n-1, ta[v], tar[v]);
			printf("%d\n", (pri & ans).count());
		}
	}
}