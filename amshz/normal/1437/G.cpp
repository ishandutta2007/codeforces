//khodaya khodet komak kon
# include <bits/stdc++.h>
# pragma GCC optimize ("O2")
# pragma GCC optimize ("unroll-loops")

/*
// ordered_set 
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/

using namespace std;

typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;

# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 6e5 + 10;
const int xm = - 20 + 10;
const int sq = 300;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e6 + 7;//998244353;
const int base = 257;
const int SIG = 26;

int n, a[xn], F[xn], nxt[SIG][xn], tim, q, t[xn];
int ahoq[xn], ptr, ans, stm[xn], ftm[xn], col[xn];
int seg[xn << 2], hvy[xn], sz[xn], head[xn];
pii b[xn];
string S;
vector <int> adj[xn], vec[xn];
set <pii> st[xn];

void build_aho(){
	int L = 0, R = 0;
	for (int i = 0; i < SIG; ++ i)
		if (nxt[i][0])
			ahoq[R ++] = nxt[i][0];
	while (L < R){
		int v = ahoq[L ++];
		adj[F[v]].push_back(v);
		for (int i = 0; i < SIG; ++ i){
			if (nxt[i][v])
				F[nxt[i][v]] = nxt[i][F[v]], ahoq[R ++] = nxt[i][v];
			else
				nxt[i][v] = nxt[i][F[v]];
		}
	}
}
void HLD(int v){
	sz[v] = 1;
	hvy[v] = - 1;
	for (int u : adj[v]){
		HLD(u);
		sz[v] += sz[u];
		if (hvy[v] == - 1 || sz[u] > sz[hvy[v]])
			hvy[v] = u;
	}
}
void DFS(int v){
	stm[v] = tim ++;
	if (hvy[v] != - 1){
		head[hvy[v]] = head[v];
		DFS(hvy[v]);
	}
	for (int u : adj[v])
		if (u != hvy[v])
			head[u] = u, DFS(u);
	ftm[v] = tim;
}
void update(int id, int l, int r, int pos, int x, int y){
	if (r - l == 1){
		st[pos].erase({- a[x], x});
		a[x] = y;
		st[pos].insert({- a[x], x});
		seg[id] = - (st[pos].begin() -> A);
		return;
	}
	int mid = l + r >> 1;
	if (pos < mid)
		update(lc, l, mid, pos, x, y);
	else
		update(rc, mid, r, pos, x, y);
	seg[id] = max(seg[lc], seg[rc]);
}
int get(int id, int l, int r, int ql, int qr){
	if (qr <= l || r <= ql || qr <= ql)
		return - 1;
	if (ql <= l && r <= qr)
		return seg[id];
	int mid = l + r >> 1;
	return max(get(lc, l, mid, ql, qr), get(rc, mid, r, ql, qr));
}

int main(){
	InTheNameOfGod;

	cin >> n >> q;
	for (int i = 1; i <= n; ++ i){
		cin >> S;
		int v = 0;
		for (int j = 0; j < SZ(S); ++ j){
			int c = S[j] - 'a';
			if (!nxt[c][v])
				nxt[c][v] = ++ ptr;
			v = nxt[c][v];
		}
		col[i] = v;
	}
	for (int i = 0; i < q; ++ i){
		int x, y;
		cin >> t[i];
		if (t[i] == 1){
			cin >> x >> y;
			b[i] = {x, y};
		}
		else{
			cin >> S;
			int v = 0;
			for (int j = 0; j < SZ(S); ++ j){
				int c = S[j] - 'a';
				if (!nxt[c][v])
					nxt[c][v] = ++ ptr;
				v = nxt[c][v];
				vec[i].push_back(v);
			}
		}
	}
	build_aho(), HLD(0), DFS(0);
	memset(seg, - 1, sizeof seg);
	for (int i = 1; i <= n; ++ i)
		update(1, 0, tim, stm[col[i]], i, 0);
	for (int i = 0; i < q; ++ i){
		if (t[i] == 1){
			int x = b[i].A, y = b[i].B;
			update(1, 0, tim, stm[col[x]], x, y);
		}
		else{
			ans = - 1;
			for (int v : vec[i]){
				int u = v;
				while (u){
					ans = max(ans, get(1, 0, tim, stm[head[u]], stm[u] + 1));
					u = F[head[u]];
				}
			}
			cout << ans << endl;
		}
	}

	return 0;
}