//khodaya khodet komak kon
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
 
const int xn = 5e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, par[xn], sz[xn], arshad[xn], root;
int st[xn], ft[xn], ptr, mH[xn];
ll d[xn], H[xn], ans[xn], c[xn];
vector <int> adj[xn], F[xn];

int get(int v, int h){
	int res = 0;
	int l = - 1, r = SZ(F[h]);
	while (r - l > 1){
		int mid = l + r >> 1;
		if (st[F[h][mid]] >= st[v])
			r = mid;
		else
			l = mid; 
	}
	res -= r;
	l = - 1, r = SZ(F[h]);
	while (r - l > 1){
		int mid = l + r >> 1;
		if (ft[F[h][mid]] <= ft[v])
			l = mid;
		else
			r = mid;
	}
	res += r;
	return res;
}
void update(int v, ll val){
	c[H[v]] += val;
	for (int u : adj[v])
		update(u, val);
}
void DFS2(int v){
	ans[v] = ans[par[v]] + c[H[v]] + H[v] - 1;
	if (!SZ(adj[v]))
		return;
	int mx = 0;
	for (int u : adj[v])
		if (u != arshad[v])
			update(u, H[v]), mx = max(mx, mH[u]);
	DFS2(arshad[v]);
	for (int i = H[v] + 1; i <= mx; ++ i)
		c[i] += H[v] * get(arshad[v], i);
	for (int u : adj[v]){
		if (u == arshad[v])
			continue;
		update(u, - H[v]);
		DFS2(u);
		update(u, H[v]);
	}
	for (int u : adj[v])
		if (u != arshad[v])
			update(u, - H[v]);
	for (int i = H[v] + 1; i <= mx; ++ i)
		c[i] -= H[v] * get(arshad[v], i);
}
void DFS(int v){
	sz[v] = 1;
	H[v] = H[par[v]] + 1;
	mH[v] = H[v];
	F[H[v]].push_back(v);
	st[v] = ptr ++;
	for (int u : adj[v]){
		DFS(u);
		sz[v] += sz[u];
		if (sz[u] > sz[arshad[v]])
			arshad[v] = u;
		mH[v] = max(mH[v], mH[u]);
	}
	ft[v] = ptr ++;
}

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 1; i <= n; ++ i){
		cin >> par[i];
		adj[par[i]].push_back(i);
		if (!par[i])
			root = i;
	}
	DFS(root), DFS2(root);
	for (int i = 1; i <= n; ++ i)
		cout << ans[i] << sep;
	cout << endl;
			
	return 0;
}