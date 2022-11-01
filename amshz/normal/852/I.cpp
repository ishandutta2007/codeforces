# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
 
# define A first
# define B second
# define endl '\n'
# define sep ' '
# define pb push_back
# define InTheNameOfGod ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 2e5 + 10;
const int xm = 2e1 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
 
int n, f[xn], a[xn], Tree[xn], S, St[xn], End[xn], par[xn][xm], H[xn], q, Order[xn], ptr, adj[xn], lca[xn], Root = 1;
ll cnt[xn], ans[xn], ted;
vector <int> G[xn], Vec;
pii Q[xn];
unordered_map <int, int> mp;
bool Mark[xn], flag[xn];
 
void DFS(int v){
	Mark[v] = true;
	St[v] = S;
	Tree[S] = v;
	S ++;
	for (int u : G[v]){
		if (Mark[u]) continue;
		par[u][0] = v;
		H[u] = H[v] + 1;
		DFS(u);
	}
	End[v] = S;
	Tree[S] = v;
	S ++;
}
int LCA(int v, int u){
	if (H[v] > H[u]) swap(v, u);
	int d = H[u] - H[v];
	for (int i = 20; i >= 0; i --){
		if ((1 << i) > d) continue;
		u = par[u][i];
		d = H[u] - H[v];
	}
	if (v == u) return v;
	for (int i = 20; i >= 0; i --){
		if ((1 << i) > H[v]) continue;
		if (par[v][i] == par[u][i]) continue;
		v = par[v][i];
		u = par[u][i];
	}
	return par[v][0];
}
 
bool cmp(int i, int j){
	if (Q[i].A / SQ != Q[j].A / SQ) return Q[i].A / SQ < Q[j].A / SQ;
	return Q[i].B < Q[j].B;
}
 
void Compress(){
	for (int i = 1; i <= n; i ++) if (f[i]) a[i] += 1e9;
	for (int i = 1; i <= n; i ++){
		if (f[i]) adj[i] = a[i] - 1e9;
		else adj[i] = a[i] + 1e9;
		Vec.push_back(a[i]);
		Vec.push_back(adj[i]);
	}
	S = 0;
	sort(Vec.begin(), Vec.end());
	for (int i = 0; i < Vec.size(); i ++)
		if (i == 0 || Vec[i] != Vec[i - 1]) mp[Vec[i]] = S ++;
	for (int i = 1; i <= n; i ++) a[i] = mp[a[i]], adj[i] = mp[adj[i]];
}
 
void Solve(int ind){
	memset(cnt, 0, sizeof cnt);
	memset(Mark, false, sizeof Mark);
	int j = Order[ptr];
	while (ptr < q && Q[j].B < ind + SQ && Q[j].A / SQ == ind / SQ){
		ted = 0;
		for (int i = Q[j].A; i <= Q[j].B; i ++){
			int v = Tree[i];
			if (Mark[v]){
				cnt[a[v]] --;
				ted -= cnt[adj[v]];
				Mark[v] = false;
				continue;
			}
			cnt[a[v]] ++;
			ted += cnt[adj[v]];
			Mark[v] = true;
		}
		if (flag[j]) ted += cnt[adj[lca[j]]];
		ans[j] = ted;
		for (int i = Q[j].A; i <= Q[j].B; i ++){
			int v = Tree[i];
			if (Mark[v] == false){
				cnt[a[v]] ++;
				Mark[v] = true;
				continue;
			}
			cnt[a[v]] --;
			Mark[v] = false;
		}
		ptr ++;
		j = Order[ptr];
	}
	ted = 0;
	for (int i = ind + SQ; i < 2 * n; i ++){
		int v = Tree[i];
		if (Mark[v]){
			cnt[a[v]] --;
			ted -= cnt[adj[v]];
			Mark[v] = false;
		}
		else{
			cnt[a[v]] ++;
			ted += cnt[adj[v]];
			Mark[v] = true;
		}
		j = Order[ptr];
		while (ptr < q && Q[j].B == i && Q[j].A / SQ == ind / SQ){
			ans[j] = ted;
			for (int k = Q[j].A; k < ind + SQ; k ++){
				int u = Tree[k];
				if (Mark[u]){
					cnt[a[u]] --;
					ans[j] -= cnt[adj[u]];
					Mark[u] = false;
				}
				else{
					cnt[a[u]] ++;
					ans[j] += cnt[adj[u]];
					Mark[u] = true;
				}
			}
			if (flag[j]) ans[j] += cnt[adj[lca[j]]];
			for (int k = Q[j].A; k < ind + SQ; k ++){
				int u = Tree[k];
				if (Mark[u] == false){
					cnt[a[u]] ++;
					Mark[u] = true;
				}
				else{
					cnt[a[u]] --;
					Mark[u] = false;
				}
			}
			ptr ++;
			j = Order[ptr];
		}
	}
}
 
int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> f[i];
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 0; i < n - 1; i ++){
		int v, u;
		cin >> v >> u;
		G[v].push_back(u);
		G[u].push_back(v);
	}
	Root = n;
	DFS(Root);
	for (int j = 1; j <= 20; j ++){
		for (int i = 1; i <= n; i ++){
			if ((1 << j) > H[i]) continue;
			par[i][j] = par[par[i][j - 1]][j - 1];
		}
	}
	Compress();
	cin >> q;
	for (int i = 0; i < q; i ++){
		int v, u;
		cin >> v >> u;
		if (St[v] > St[u]) swap(v, u);
		lca[i] = LCA(v, u);
		if (lca[i] == v){
			Q[i].A = St[v];
			Q[i].B = St[u];
		}
		else{
			Q[i].A = End[v];
			Q[i].B = St[u];
			flag[i] = true;
		}
		Order[i] = i;
	}
	sort(Order, Order + q, cmp);
	for (int i = 0; i < 2 * n; i += SQ) Solve(i);
	for (int i = 0; i < q; i ++) cout << ans[i] << endl;
	return 0;
}