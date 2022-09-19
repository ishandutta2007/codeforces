// vaziat meshki-ghermeze !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld pi = acos(-1);
const ll Mod = 1000000007LL;
const int N = 1e5 + 10;
const ll Inf = 2242545357980376863LL;
const int Log = 20;

vector<int> G[N];

int sp[N][Log];
int T = 2, st[N], fn[N], dep[N];
void DFS(int u, int p, int d = 0){
	st[u] = T++;
	dep[u] = d;
	sp[u][0] = p;
	for(int l = 1; l < Log; l++)
		sp[u][l] = sp[sp[u][l - 1]][l - 1];
	for(auto adj : G[u])
		if(adj != p)
			DFS(adj, u, d + 1);
	fn[u] = T;
}

int LCA(int u, int v){
	if(dep[u] < dep[v]) swap(u, v);
	int h = dep[u] - dep[v];
	for(int i = 0; i < Log; i++)
		if(h >> i & 1)
			u = sp[u][i];
	if(u == v)
		return u;
	for(int l = Log - 1; l >= 0; l--)
		if(sp[u][l] != sp[v][l])
			u = sp[u][l], v = sp[v][l];
	return sp[u][0];
}

ll fen[N];
void Add(int idx, ll x){
	for(; idx < N; idx += (idx & (-idx)))
		fen[idx] += x;
}
ll Get(int idx){
	ll res = 0;
	for(; idx; idx -= (idx & (-idx)))
		res += fen[idx];
	return res;
}
void Add_Node(int u, int x){
	Add(st[u], x);
	Add(fn[u], -x);
}
ll GT(int u){
	return Get(st[u]);
}

int a[N];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n >> q;
	int u, v;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	DFS(1, 0, 0);
	for(int i = 1; i <= n; i++){
		a[i] = abs(a[i]);
		Add_Node(i, a[i]);
	}
	int t, x;
	for(int i = 0; i < q; i++){
		cin >> t;
		if(t == 1){
			cin >> u >> x; x = abs(x);
 			Add_Node(u, -a[u]);
 			a[u] = x;
 			Add_Node(u, a[u]);
		} else {
			cin >> u >> v;
			int lc = LCA(u, v);
			ll sm = GT(u) + GT(v) - 2 * GT(lc) + a[lc];
			sm *= 2;
			sm -= a[u] + a[v];
			cout << sm << '\n';
		}
	}
	return 0;
}