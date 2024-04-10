// khodaya khodet komak kon
# include <bits/stdc++.h>
# pragma GCC optimize("O2")
 
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
# define lc                                              id << 1
# define rc                                              lc | 1
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e5 + 10;
const int xm = 10 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, q, a[xn], stm[xn], S, par[xm][xn];
int H[xn], ftm[xn], k, mx, last, root;
ll dp[2][xn];
set <pii> st;
vector <int> adj[xn];
bool flag, mark[xn];

void DFS2(int v){
	ll sum1 = 0, sum0 = 0, d = 0;
	for (int u : adj[v]){
		DFS2(u);
		sum0 += dp[0][u];
		sum1 += dp[1][u];
		d = max(d, dp[1][u] - dp[0][u]);
	}
	if (mark[v]){
		dp[1][v] = inf;
		dp[0][v] = sum1;
	}
	else{
		dp[0][v] = min(1 + sum0, sum1 - d);
		dp[1][v] = min(1 + sum0, sum1);
	}
}
void DFS(int v){
	stm[v] = S ++;
	for (int u : adj[v]){
		if (u == par[0][v])
			continue;
		par[0][u] = v;
		H[u] = H[v] + 1;
		DFS(u);
	}
	ftm[v] = S ++;
}
int LCA(int v, int u){
	if (H[v] > H[u])
		swap(v, u);
	for (int i = xm - 1; i >= 0; -- i)
		if ((1 << i) <= H[u] - H[v])
			u = par[i][u];
	if (v == u)
		return v;
	for (int i = xm - 1; i >= 0; -- i)
		if (par[i][v] != par[i][u])
			v = par[i][v], u = par[i][u];
	return par[0][v];
}
bool cmp(int v, int u){ return stm[v] < stm[u];}

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 0; i < n - 1; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	DFS(1);
	for (int i = 1; i <= n; ++ i)
		adj[i].clear();
	for (int i = 1; i < xm; ++ i)
		for (int v = 1; v <= n; ++ v)
			par[i][v] = par[i - 1][par[i - 1][v]];
	cin >> q;
	while (q --){
		cin >> k;
		for (int i = 1; i <= k; ++ i)
			cin >> a[i];
		sort(a + 1, a + k + 1, cmp);
		st.clear(), flag = false, mx = - 1;
		for (int i = 1; i <= k; ++ i){
			int v = a[i], u = a[i + 1];
			st.insert({stm[v], v});
			if (i < k){
				st.insert({stm[LCA(v, u)], LCA(v, u)});
				flag |= (v == par[0][u]);
			}
			if (mx > ftm[v])
				st.insert({stm[par[0][v]], par[0][v]});
			mx = max(mx, ftm[v]);
		}
		if (flag){
			cout << - 1 << endl;
			continue;
		}
		for (int i = 1; i <= k; ++ i)
			mark[a[i]] = true;
		last = 0, root = st.begin() -> B;
		for (pii x : st){
			int v = x.B;
			if (v != root)
				adj[LCA(last, v)].push_back(v);
			last = v;
		}
		DFS2(root);
		for (int i = 1; i <= k; ++ i)
			mark[a[i]] = false;
		for (pii x : st)
			adj[x.B].clear();
		if (dp[0][root] > n)
			cout << - 1 << endl;
		else
			cout << dp[0][root] << endl;
	}
	
	return 0;
}