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
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, q, dist[xn], lazy[xn << 2], stime[xn];
int ptr, L[xn], R[xn], ans[xn];
vector <pii> adj[xn], Q[xn];
pii seg[xn << 2];
bool mark[xn];

void modify(int id, int l, int r, int pos, int val){
	if (r - l == 1){
		seg[id].A = val;
		seg[id].B = ll(val) * ll(val) % mod;
		return;
	}
	int mid = l + r >> 1;
	if (pos < mid) modify(id << 1, l, mid, pos, val);
	else modify(id << 1 | 1, mid, r, pos, val);
	seg[id].A = (seg[id << 1].A + seg[id << 1 | 1].A) % mod;
	seg[id].B = (seg[id << 1].B + seg[id << 1 | 1].B) % mod;
}
void shift(int id, int l, int r){
	if (!lazy[id]) return;
	seg[id].B = (seg[id].B + ll(r - l) * ll(lazy[id]) % mod * ll(lazy[id]) % mod) % mod;
	seg[id].B = (seg[id].B + 2LL * ll(lazy[id]) * ll(seg[id].A) % mod) % mod;
	seg[id].A = (seg[id].A + ll(r - l) * ll(lazy[id]) % mod) % mod;
	if (r - l > 1){
		lazy[id << 1] = (lazy[id << 1] + lazy[id]) % mod;
		lazy[id << 1 | 1] = (lazy[id << 1 | 1] + lazy[id]) % mod;
	}
	lazy[id] = 0;
}
void update(int id, int l, int r, int ql, int qr, int val){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql) return;
	if (ql <= l && r <= qr){
		lazy[id] = (lazy[id] + val) % mod;
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(id << 1, l, mid, ql, qr, val);
	update(id << 1 | 1, mid, r, ql, qr, val);
	seg[id].A = (seg[id << 1].A + seg[id << 1 | 1].A) % mod;
	seg[id].B = (seg[id << 1].B + seg[id << 1 | 1].B) % mod;
}
int get(int id, int l, int r, int ql, int qr){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql) return 0;
	if (ql <= l && r <= qr) return seg[id].B;
	int mid = l + r >> 1;
	return (get(id << 1, l, mid, ql, qr) + get(id << 1 | 1, mid, r, ql, qr)) % mod;
}
void DFS2(int v){
	mark[v] = true;
	for (pii x : Q[v]){
		ans[x.B] = get(1, 0, ptr, L[x.A], R[x.A]) * 2LL % mod;
		ans[x.B] = (ans[x.B] - seg[1].B + mod) % mod;
	}
	for (pii u : adj[v]){
		if (mark[u.A])
			continue;
		update(1, 0, ptr, 0, ptr, u.B);
		update(1, 0, ptr, L[u.A], R[u.A], (- u.B - u.B + mod + mod) % mod);
		DFS2(u.A);
		update(1, 0, ptr, 0, ptr, (mod - u.B) % mod);
		update(1, 0, ptr, L[u.A], R[u.A], u.B * 2LL % mod);
	}
}
void DFS(int v){
	mark[v] = true;
	L[v] = ptr ++;
	R[v] = ptr;
	for (pii u : adj[v]){
		if (mark[u.A])
			continue;
		dist[u.A] = (dist[v] + u.B) % mod;
		DFS(u.A);
		R[v] = R[u.A];
	}
}

int main(){
    InTheNameOfGod;
    
	cin >> n;
	for (int i = 0; i < n - 1; ++ i){
		int v, u, w;
		cin >> v >> u >> w;
		adj[v].push_back({u, w});
		adj[u].push_back({v, w});
	}
	DFS(1);
	for (int i = 1; i <= n; ++ i)
		modify(1, 0, ptr, L[i], dist[i]);
	cin >> q;
	for (int i = 1; i <= q; ++ i){
		int v, u;
		cin >> v >> u;
		Q[v].push_back({u, i});
	}
	memset(mark, false, sizeof mark);
	DFS2(1);
	for (int i = 1; i <= q; ++ i)
		cout << ans[i] << endl;
 
    return 0;
}