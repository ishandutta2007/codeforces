#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
struct blossom {
#define _rep(i, a, b) for(int i = (a); i < (b); i++)
    int n, m;
    VI mate;
    vector<VI> b;
    VI p, d, bl;
    vector<VI> g;
    blossom(int n) : n(n) {
        m = n + n / 2;
        mate.assign(n, -1);
        b.resize(m);
        p.resize(m);
        d.resize(m);
        bl.resize(m);
        g.assign(m, VI(m, -1));
    }
    void add_edge(int u, int v) {
        g[u][v] = u;
        g[v][u] = v;
    }
    void match(int u, int v) {
        g[u][v] = g[v][u] = -1;
        mate[u] = v;
        mate[v] = u;
    }
    VI trace(int x) {
        VI vx;
        while(true) {
            while(bl[x] != x) x = bl[x];
            if(!vx.empty() && vx.back() == x) break;
            vx.push_back(x);
            x = p[x];
        }
        return vx;
    }
    VI lift(VI vx) {
        VI A;
        int pz = -1;
        while(SZ(vx) >= 2) {
            int z = vx.back(); vx.pop_back();
            int w = vx.back();
            if(z < n) {
                A.push_back(z);
                pz = z;
                continue;
            }
            int i = (SZ(A) % 2 == 0 ? find(all(b[z]), g[z][w]) - b[z].begin() : 0);
            int j = (SZ(A) % 2 == 1 ? find(all(b[z]), g[z][pz]) - b[z].begin() : 0);
            int k = SZ(b[z]);
            int dif = (SZ(A) % 2 == 0 ? i % 2 == 1 : j % 2 == 0) ? 1 : k - 1;
            while(i != j) {
                vx.push_back(b[z][i]);
                i = (i + dif) % k;
            }
            vx.push_back(b[z][i]);
        }
        return A;
    }
    void contract(int c, int x, int y, VI &vx, VI &vy) {
        b[c].clear();
        int r = vx.back();
        while(!vx.empty() && !vy.empty() && vx.back() == vy.back()) {
            r = vx.back();
            vx.pop_back();
            vy.pop_back();
        }
        b[c].push_back(r);
        b[c].insert(b[c].end(), vx.rbegin(), vx.rend());
        b[c].insert(b[c].end(), all(vy));
        _rep(i, 0, c + 1) {
            g[c][i] = g[i][c] = -1;
        }
        for(int z : b[c]) {
            bl[z] = c;
            _rep(i, 0, c) {
                if(g[z][i] != -1) {
                    g[c][i] = z;
                    g[i][c] = g[i][z];
                }
            }
        }
    }
    int solve() {
        for(int ans = 0; ; ans++) {
            fill(all(d), 0);
            queue<int> Q;
            _rep(i, 0, m) bl[i] = i;
            _rep(i, 0, n) {
                if(mate[i] == -1) {
                    Q.push(i);
                    p[i] = i;
                    d[i] = 1;
                }
            }
            int c = n;
            bool aug = false;
            while(!Q.empty() && !aug) {
                int x = Q.front(); Q.pop();
                if(bl[x] != x) continue;
                _rep(y, 0, c) {
                    if(bl[y] == y && g[x][y] != -1) {
                        if(d[y] == 0) {
                            p[y] = x;
                            d[y] = 2;
                            p[mate[y]] = y;
                            d[mate[y]] = 1;
                            Q.push(mate[y]);
                        }else if(d[y] == 1) {
                            VI vx = trace(x);
                            VI vy = trace(y);
                            if(vx.back() == vy.back()) {
                                contract(c, x, y, vx, vy);
                                Q.push(c);
                                p[c] = p[b[c][0]];
                                d[c] = 1;
                                c++;
                            }else {
                                aug = true;
                                vx.insert(vx.begin(), y);
                                vy.insert(vy.begin(), x);
                                VI A = lift(vx);
                                VI B = lift(vy);
                                A.insert(A.end(), B.rbegin(), B.rend());
                                for(int i = 0; i < SZ(A); i += 2) {
                                    match(A[i], A[i + 1]);
                                    if(i + 2 < SZ(A)) add_edge(A[i + 1], A[i + 2]);
                                }
                            }
                            break;
                        }
                    }
                }
            }
            if(!aug) return ans;
        }
    }
};
const int N = 600105;
int n, m, a[N], nxt[N], fa[N], from[N], dir[N], U[N], V[N];
vector<array<int, 3>> edge;
vector<pii> e[N];
bool vis[N], ok[N], used[N];
int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
void uni(int u, int v) {
	u = find(u); v = find(v);
	fa[u] = v;
}
void add(int u, int v, int w) {
	U[w] = u; V[w] = v;
	e[u].emplace_back(v, w);
	e[v].emplace_back(u, w);
	uni(u, v);
}
VI vec;
bool flag;
void dfs(int u) {
	// printf("U %d\n", u);
	vis[u] = 1;
	vec.pb(u);
	for(auto [v, w] : e[u]) {
		if(w == from[u]) continue;
		if(!vis[v]) {
			// printf("set dir (%d %d)\n", w, v);
			dir[w] = v;
			from[v] = w;
			dfs(v);
		} else if(!flag) {
			// printf("find ancester! (%d %d %d)\n", u, v, w);
			dir[w] = v;
			flag = 1;
			int x = v;
			while(from[x]) {
				int to = dir[from[x]] ^ U[from[x]] ^ V[from[x]];
				x = dir[from[x]] = to;
			}
		}
	}
}

int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	m = *max_element(a + 1, a + n + 1);
	bool LZJ = n == 300000 && a[1] == 210;
	int sum = 0;
	rep(i, 1, n) fa[i] = i;
	if(m == 0) {
		rep(i, 1, n) printf("%d ", (i + 1) / 2);
		return 0;
	}
	for(int l = 1, r; l <= n; l = r + 1) {
		r = l;
		if(a[l]) continue;
		while(r < n && a[r + 1] == 0) r++;
		nxt[l] = r;
		if((r - l + 1) & 1) {
			if(l == 1) a[r] = a[r + 1];
			else if(r == n) a[l] = a[l - 1];
			else add(a[l - 1], a[r + 1], l);
		} else if(l != 1 && r != n) edge.pb({a[l - 1], a[r + 1], l});
	}
	int tot = n;
	rep(i, 1, n - 1) if(a[i] == a[i + 1] && a[i]) add(a[i], a[i], ++tot);
	rep(i, 1, m) if(!vis[i]) { // |E| >= |V|
		vec.clear(); flag = 0;
		dfs(i);
		if(flag) for(auto o : vec) ok[o] = 1;
	}
	// rep(i, 1, n) if(nxt[i] && (nxt[i] - i + 1) & 1) printf("%d ", dir[i]);
	// printf("\n");
	rep(i, 1, n) vis[i] = 0;
	// |E| = |V| - 1
	vec.clear();
	for(auto o : edge) {
		int u = o[0], v = o[1];
		// printf("(%d %d %d %d)\n", u, v, find(u), find(v));
		u = find(u); v = find(v);
		if(u == v || ok[u] || ok[v]) continue;
		vec.pb(u); vec.pb(v);
	}
	sort(all(vec));
	vec.erase(unique(all(vec)), vec.end());
	int i_hate_this_problem = SZ(vec);
	assert(SZ(vec) <= 600);
	blossom B(i_hate_this_problem + 1);
	map<pii, int> M;
	map<int, pii> MM;
	for(auto o : edge) {
		int u = o[0], v = o[1], w = o[2];
		MM[w] = mp(u, v);
		u = find(u); v = find(v);
		if(u == v || ok[u] || ok[v] || M.count(mp(u, v)) > 0) continue;
		u = lower_bound(all(vec), u) - vec.begin() + 1;
		v = lower_bound(all(vec), v) - vec.begin() + 1;
		assert(max(u, v) <= i_hate_this_problem);
		M[mp(u, v)] = M[mp(v, u)] = w;
		B.add_edge(u, v);
		// printf("add %d %d\n", u, v);
	}
	B.solve();
	rep(i, 1, i_hate_this_problem) if(~B.mate[i] && i < B.mate[i]) {
		int u = i, v = B.mate[i], l = M[mp(u, v)];
		// printf("match %d %d\n", u, v);
		a[l] = a[l - 1];
		a[nxt[l]] = a[nxt[l] + 1];
		// printf("[%d %d]\n", l, nxt[l]);
		// for(auto why : vec) printf("%d ", why); printf("\n");
		// printf("%d %d %d %d\n", u, v, vec[u - 1], vec[v - 1]);
		int _u, _v; tie(_u, _v) = MM[l];
		assert(vis[_u] == 0); from[_u] = 0; dfs(_u);
		// for(auto why : vec) printf("%d ", why); printf("\n");
		// printf("%d %d %d %d\n", u, v, vec[u - 1], vec[v - 1]);
		assert(vis[_v] == 0);from[_v] = 0; dfs(_v);
	}
	rep(i, 1, n) {
		if(nxt[i] && a[i] == 0) {
			if((nxt[i] - i + 1) & 1) {
				// printf("!!! %d %d %d\n", i, dir[i], a[i - 1]);
				if(dir[i] == a[i - 1]) a[i] = a[i - 1];
				else a[nxt[i]] = a[nxt[i] + 1];
			}
		}
	}
	int ptr = 1;
	rep(i, 1, n - 1) if(a[i] && a[i] == a[i + 1]) used[a[i + 1]] = 1;
	for(int l = 1, r; l <= n; l = r + 1) {
		r = l;
		if(a[l]) continue;
		while(r < n && a[r + 1] == 0) r++;
		assert((r - l + 1) % 2 == 0);
		for(int i = l; i <= r; i += 2) {
			while(used[ptr]) ptr++;
			a[i] = a[i + 1] = ptr;
			used[ptr] = 1;
		}
	}
	rep(i, 1, n) printf("%d ", a[i]);
	return 0;
}
/*
14
2 0 1 0 3 1 0 0 4 5 0 4 0 6

17
2 0 3 2 0 1 0 3 1 0 0 4 5 0 4 0 6

20
2 0 3 2 0 1 0 3 1 0 0 4 5 0 4 0 6 7 0 8

23
2 0 3 2 0 1 0 3 1 0 0 4 5 0 4 0 6 8 0 7 0 0 4

13
5 0 2 0 1 0 3 0 7 0 5 0 6
*/