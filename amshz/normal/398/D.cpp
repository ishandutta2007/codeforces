# include <bits/stdc++.h>
 
///*
// ordered_set 
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
//*/
 
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
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 5e5 + 10;
const int xm = - 20 + 10;
const int SQ = 800;
const int sq = 500 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e14 + 10;
const int MOD = 1e9 + 7;
const int TM = 1e7;
const int BASE = 257;

int n, m, q, d[xn], t, ans[xn], ptr = 1, col[xn];
pii E[xn];
vector <int> vec;
vector <pii> adj[xn], G[xn];
char c[xn];
bool mark[xn], flag[xn];
map <pii, int> mp;

void add(int v){
	flag[v] = true;
	for (pii u : G[v])
		if (mark[u.B]) ++ ans[u.A];
}
void remove(int v){
	flag[v] = false;
	for (pii u : G[v])
		if (mark[u.B]) -- ans[u.A];
}
int get(int v){
	if (d[v] >= SQ) return ans[v];
	int res = 0;
	for (pii u : adj[v])
		if (mark[u.B]) res += flag[u.A];
	return res;
}

int main(){
    InTheNameOfGod;
    
    cin >> n >> m >> q >> t;
    while (t --){
    	int v;
    	cin >> v;
    	vec.push_back(v);
	}
	for (int i = 0; i < m; ++ i){
		int v, u;
		cin >> v >> u;
		if (u < v) swap(v, u);
		mp[{v, u}] = ptr;
		mark[ptr] = true;
		adj[v].push_back({u, ptr});
		adj[u].push_back({v, ptr ++});
		++ d[v];
		++ d[u];
	}
	for (int i = 0; i < q; ++ i){
		int v, u;
		cin >> c[i] >> v;
		E[i].A = v;
		if (c[i] == 'A' || c[i] == 'D'){
			cin >> u;
			E[i].B = u;
			if (u < v) swap(v, u);
			if (mp[{v, u}]){
				col[i] = mp[{v, u}];
				continue;
			}
			++ d[v];
			++ d[u];
			mp[{v, u}] = ptr;
			adj[v].push_back({u, ptr});
			adj[u].push_back({v, ptr});
			col[i] = ptr ++;
		}
	}
	for (int i = 1; i <= n; ++ i){
		for (pii v : adj[i]){
			if (d[v.A] < SQ) continue;
			G[i].push_back(v);
		}
	}
	for (int v : vec) add(v);
	for (int i = 0; i < q; ++ i){
		if (c[i] == 'O') add(E[i].A);
		else if (c[i] == 'F') remove(E[i].A);
		else if (c[i] == 'A'){
			if (d[E[i].A] >= SQ) ans[E[i].A] += flag[E[i].B];
			if (d[E[i].B] >= SQ) ans[E[i].B] += flag[E[i].A];
			mark[col[i]] = true;
		}
		else if (c[i] == 'D'){
			if (d[E[i].A] >= SQ) ans[E[i].A] -= flag[E[i].B];
			if (d[E[i].B] >= SQ) ans[E[i].B] -= flag[E[i].A];
			mark[col[i]] = false;
		}
		else cout << get(E[i].A) << endl;
	}
    
    return 0;
}