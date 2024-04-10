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
const int xn = 1e5 + 10;
const int xm = 5e3 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e10 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";

int n, q, par[xm], num[xn], mx[xm], seg[xn << 2];
double dp[xm][xm], ans;
pair <pii, double> Q[xm];
vector <int> adj[xm];

void Build(int id, int l, int r){
	if (r - l == 1){
		seg[id] = num[l];
		return;
	}
	int mid = l + r >> 1;
	Build(id << 1, l, mid);
	Build(id << 1 | 1, mid, r);
	seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
}
int Get(int id, int l, int r, int ql, int qr){
	if (qr <= l || r <= ql) return 0;
	if (ql <= l && r <= qr) return seg[id];
	int mid = l + r >> 1;
	return max(Get(id << 1, l, mid, ql, qr), Get(id << 1 | 1, mid, r, ql, qr));
}
void DFS(int v){
	for (int u : adj[v]) DFS(u);
	for (int i = 0; i < xm; ++ i) dp[v][i] = 1;
	for (int u : adj[v]) for (int i = 0; i < xm; ++ i) dp[v][i] *= dp[u][min(xm - 1, mx[v] - mx[u] + i)];
	for (int i = xm - 1; i >= 0; -- i){
		dp[v][i] *= 1 - Q[v].B;
		if (i) dp[v][i] += Q[v].B * dp[v][i - 1];
	}
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> q;
	for (int i = 1; i <= n; ++ i) cin >> num[i];
	for (int i = 1; i <= q; ++ i) cin >> Q[i].A.A >> Q[i].A.B >> Q[i].B;
	Q[0] = {{1, n}, 0};
	for (int i = 1; i <= q; ++ i){
		for (int j = 1; j <= q; ++ j){
			if (i == j || Q[j].A.A > Q[i].A.A || Q[j].A.B < Q[i].A.B) continue;
			if (Q[i].A.A == Q[j].A.A && Q[i].A.B == Q[j].A.B && i < j) continue;
			if (Q[par[i]].A.B - Q[par[i]].A.A >= Q[j].A.B - Q[j].A.A) par[i] = j;
		}
		adj[par[i]].push_back(i);
	}
	Build(1, 1, n + 1);
	for (int i = 0; i <= q; ++ i) mx[i] = Get(1, 1, n + 1, Q[i].A.A, Q[i].A.B + 1);
	DFS(0);
	ans = dp[0][0] * mx[0];
	for (int i = 1; i < xm; ++ i) ans += (i + mx[0]) * (dp[0][i] - dp[0][i - 1]);
	cout << fixed << setprecision(9) << ans << endl;
	
	return 0;
}