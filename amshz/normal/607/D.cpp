# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 2e5 + 10;
const int xm = 10 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n = 1, q, par[xn], zr[xn], seg[xn << 2], vl[xn];
int L[xn], R[xn], ptr, lazy[xn << 2], dx[xn];
vector <int> adj[xn];
pair <int, pii> Q[xn];

void DFS(int v){
	L[v] = ptr ++;
	R[v] = ptr;
	for (int u : adj[v]){
		par[u] = v;
		DFS(u);
		R[v] = R[u];
	}
}
void shift(int id, int l, int r){
	if (lazy[id] == 1)
		return;
	seg[id] = ll(seg[id]) * ll(lazy[id]) % mod;
	if (r - l > 1){
		lazy[id << 1] = ll(lazy[id << 1]) * ll(lazy[id]) % mod;
		lazy[id << 1 | 1] = ll(lazy[id << 1 | 1]) * ll(lazy[id]) % mod;
	}
	lazy[id] = 1;
}
void modify(int id, int l, int r, int pos, int val){
	shift(id, l, r);
	if (r - l == 1){
		seg[id] = (seg[id] + val) % mod;
		return;
	}
	int mid = l + r >> 1;
	if (pos < mid)
		modify(id << 1, l, mid, pos, val);
	else
		modify(id << 1 | 1, mid, r, pos, val);
	shift(id << 1, l, mid);
	shift(id << 1 | 1, mid, r);
	seg[id] = (seg[id << 1] + seg[id << 1 | 1]) % mod;
}
void update(int id, int l, int r, int ql, int qr, int val){
	shift(id, l, r);
	if (qr <= l || r <= ql)
		return;
	if (ql <= l && r <= qr){
		lazy[id] = ll(lazy[id]) * ll(val) % mod;
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(id << 1, l, mid, ql, qr, val);
	update(id << 1 | 1, mid, r, ql, qr, val);
	seg[id] = (seg[id << 1] + seg[id << 1 | 1]) % mod;
}
int get(int id, int l, int r, int ql, int qr){
	shift(id, l, r);
	if (qr <= l || r <= ql)
		return 0;
	if (ql <= l && r <= qr)
		return seg[id];
	int mid = l + r >> 1;
	return (get(id << 1, l, mid, ql, qr) + get(id << 1 | 1, mid, r, ql, qr)) % mod;
}
int get_zr(int ind){
	if (!ind) return 1;
	int x = get(1, 0, ptr, L[ind], L[ind] + 1);
	int y = power(vl[ind], mod - 2, mod);
	return ll(x) * ll(y) % mod;
}

int main(){
    InTheNameOfGod;
    
    cin >> vl[1] >> q;
    for (int i = 1; i <= q; ++ i){
    	cin >> Q[i].A;
    	if (Q[i].A == 1){
    		cin >> Q[i].B.A >> Q[i].B.B;
    		adj[Q[i].B.A].push_back(++ n);
    		dx[i] = n;
    		vl[n] = Q[i].B.B;
		}
		else
			cin >> Q[i].B.A;
	}
	DFS(1);
	fill(zr, zr + n + 1, 1);
	fill(lazy, lazy + (xn << 2), 1);
	modify(1, 0, ptr, L[1], vl[1]);
	for (int i = 1; i <= q; ++ i){
		if (Q[i].A == 1){
			int v = dx[i];
			int x = ll(vl[v]) * ll(get_zr(par[v])) % mod;
			int y = power(zr[par[v]], mod - 2, mod);
			++ zr[par[v]];
			y = ll(y) * ll(zr[par[v]]) % mod;
			modify(1, 0, ptr, L[v], x);
			update(1, 0, ptr, L[par[v]], R[par[v]], y);
		}
		else{
			int v = Q[i].B.A;
			int x = get(1, 0, ptr, L[v], R[v]);
			int y = get_zr(par[v]);
			y = power(y, mod - 2, mod);
			x = ll(x) * ll(y) % mod;
			cout << x << endl;
		}
	}
 
    return 0;
}