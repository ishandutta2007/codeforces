# include <bits/stdc++.h>
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
typedef pair <ll , ll >                                  pll;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;//998244353;
const int xn = 2e5 + 10;
const int xm = 4e5 + 10;
const int SQ = 320;
const int sq = SQ + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";

int n, m, par[xn], sz[xn];
pii Root, D, GG[xn];
vector <int> adj[xn], vec;
vector <pii> ans;
bool Mark[xn], flag;
pair <bool, bool> G[xn];

int get_root(int v){
	if (v == par[v]) return v;
	return par[v] = get_root(par[v]);
}
void merge(int v, int u){
	v = get_root(v);
	u = get_root(u);
	if (v == u) return;
	if (sz[u] > sz[v]) swap(v, u);
	sz[v] += sz[u];
	par[u] = v;
}
void DFS(int v, int P = -1){
	Mark[v] = true;
	if (P != -1) ans.push_back({P, v}), merge(v, P);
	for (int u : adj[v])
		if (!Mark[u])	DFS(u, v);
}
bool cmp(int v, int u){
	return (G[v].A + G[v].B < G[u].A + G[u].B);
}


int main(){
	InTheNameOfGod;
	
	cin >> n >> m;
	for (int i = 0; i < m; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	cin >> Root.A >> Root.B >> D.A >> D.B;
	for (int v = 1; v <= n; ++ v) par[v] = v;
	Mark[Root.A] = Mark[Root.B] = true;
	for (int v = 1; v <= n; ++ v){
		if (Mark[v]) continue;
		DFS(v);
		vec.push_back(get_root(v));
	}
	memset(Mark, false, sizeof Mark);
	for (int u : adj[Root.A]){
		G[get_root(u)].A = true;
		GG[get_root(u)].A = u; 
	}
	for (int u : adj[Root.B]){
		G[get_root(u)].B = true;
		GG[get_root(u)].B = u;
	}
	sort(all(vec), cmp);
	for (int v : vec){
		if (G[v].A && !G[v].B){
			ans.push_back({Root.A, GG[v].A});
			-- D.A;
			if (D.A < 0) kill("No");
			continue;
		}
		if (!G[v].A && G[v].B){
			ans.push_back({Root.B, GG[v].B});
			-- D.B;
			if (D.B < 0) kill("No");
			continue;
		}
		if (!G[v].A && !G[v].B) kill("No");
		if (flag){
			if (D.A < D.B){
				ans.push_back({Root.B, GG[v].B});
				-- D.B;
				if (D.B < 0) kill("No");
			}
			else{
				ans.push_back({Root.A, GG[v].A});
				-- D.A;
				if (D.A < 0) kill("No");
			}
		}
		else{
			ans.push_back({Root.B, GG[v].B});
			-- D.B;
			if (D.B < 0) kill("No");
		
			ans.push_back({Root.A, GG[v].A});
			-- D.A;
			if (D.A < 0) kill("No");
			flag = true;
		}
	}
	if (!flag){
		ans.push_back({Root.A, Root.B});
		-- D.B, -- D.A;
		if (D.A < 0 || D.B < 0) kill("No");
		flag = true;
	}
	cout << "Yes" << endl;
	for (pii e : ans)
		cout << e.A << sep << e.B << endl;
	
	
	return 0;
}