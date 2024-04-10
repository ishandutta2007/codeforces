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
const int xm = 1e3 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, m, a[xn], L[xn], R[xn], ted, primes[xm];
int P[xn], ans[xm], lazy[xn << 2], q, ptr, ptr2;
bool mark[xm];
vector <int> adj[xn];
bitset <xm> seg[xn << 2], bs[2][xm], B[2];

void DFS(int v, int par = - 1){
	P[ptr] = v;
	L[v] = ptr ++;
	R[v] = ptr;
	for (int u : adj[v]){
		if (u == par)
			continue;
		DFS(u, v);
		R[v] = R[u];
	}
}
void build(int id, int l, int r){
	if (r - l == 1){
		seg[id][a[P[l]] % m] = 1;
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
	seg[id] = (seg[id << 1] | seg[id << 1 | 1]);
}
void shift(int id, int l, int r){
	if (!lazy[id])
		return;
	B[0] = bs[1][lazy[id]];
	B[1] = bs[0][m - lazy[id]];
	B[0] &= seg[id];
	B[1] &= seg[id];
	B[1] = B[1] << lazy[id];
	B[0] = B[0] >> (m - lazy[id]);
	seg[id] = (B[0] | B[1]);
	if (r - l > 1){
		lazy[id << 1] = (lazy[id << 1] + lazy[id]) % m;
		lazy[id << 1 | 1] = (lazy[id << 1 | 1] + lazy[id]) % m;
	}
	lazy[id] = 0;
}
void update(int id, int l, int r, int ql, int qr, int val){
	shift(id, l, r);
	if (qr <= l || r <= ql)
		return;
	if (ql <= l && r <= qr){
		lazy[id] = (lazy[id] + val) % m;
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(id << 1, l, mid, ql, qr, val);
	update(id << 1 | 1, mid, r, ql, qr, val);
	seg[id] = (seg[id << 1] | seg[id << 1 | 1]);
}
void get(int id, int l, int r, int ql, int qr){
	shift(id, l, r);
	if (qr <= l || r <= ql)
		return;
	if (ql <= l && r <= qr){
		for (int i = 0; i < ptr2; ++ i){
			int x = primes[i];
			ans[i] += seg[id][x];
		}
		return;
	}
	int mid = l + r >> 1;
	get(id << 1, l, mid, ql, qr);
	get(id << 1 | 1, mid, r, ql, qr);
}

int main(){
    InTheNameOfGod;
    
   	cin >> n >> m;
    for (int i = 2; i < m; ++ i){
    	if (mark[i])
    		continue;
    	primes[ptr2 ++] = i;
    	for (int j = i + i; j < m; j += i)
    		mark[j] = true;
	}
    for (int i = 1; i < m; ++ i){
    	bs[0][i] = bs[0][i - 1];
    	bs[0][i][i - 1] = 1;
	}
	for (int i = 1; i < m; ++ i){
		bs[1][i] = bs[1][i - 1];
		bs[1][i][m - i] = 1;
	}
   	for (int i = 1; i <= n; ++ i)
   		cin >> a[i];
   	for (int i = 0; i < n - 1; ++ i){
   		int v, u;
   		cin >> v >> u;
   		adj[v].push_back(u);
   		adj[u].push_back(v);
	}
   	DFS(1);
   	build(1, 0, ptr);
   	cin >> q;
   	while (q --){
   		int t, v, x;
   		cin >> t >> v;
   		if (t == 1){
   			cin >> x;
   			update(1, 0, ptr, L[v], R[v], x);
		}
		else{
			for (int i = 0; i < ptr2; ++ i)
				ans[i] = 0;
			get(1, 0, ptr, L[v], R[v]);
			ted = 0;
			for (int i = 0; i < ptr2; ++ i)
				ted += (ans[i] > 0);
			cout << ted << endl;
		}
	}

    return 0;
}