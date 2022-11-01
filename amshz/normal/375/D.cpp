# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const int md = 1e9;
const int xn = 1e5 + 10;
const int xm = 1e6 + 10;
const int SQ = 320;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
 
 
ll power(ll a, ll b){return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll jaam(int a, int b){return (a + b) % md;}
ll menha(int a, int b){return (a - b + md) % md;}
ll zarb(int a, int b){return (1LL * a * b) % md;}


int n, m, P[xn], a[xn], Root = 1, Start[xn], S, R[xn], cnt[xn], ted[xn], ans[xn];
vector <int> adj[xn], vec[xn];
pair <pii, pii> Q[xn];
bool Mark[xn];


void DFS(int v){
	Mark[v] = true;
	P[S] = a[v];
	Start[v] = S ++;
	R[v] = Start[v];
	for (int u : adj[v]){
		if (Mark[u]) continue;
		DFS(u);
		R[v] = R[u];
	}
}


void Solve(int ind){
	memset(cnt, 0, sizeof cnt);
	memset(ted, 0, sizeof ted);
	for (int i = ind; i < n; i ++){
		cnt[a[i]] ++;
		ted[cnt[a[i]]] ++;
		for (int j : vec[i]){
			if (Q[j].F.F / SQ != ind / SQ) continue;
			for (int k = ind; k < Q[j].F.F; k ++){
				ted[cnt[a[k]]] --;
				cnt[a[k]] --;
			}
			ans[j] = ted[Q[j].S.F];
			for (int k = ind; k < Q[j].F.F; k ++){
				cnt[a[k]] ++;
				ted[cnt[a[k]]] ++;
			}
		}
	}
}
int main(){
	fast_io;
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 0; i < n - 1; i ++){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	DFS(Root);
	for (int i = 0; i < n; i ++) a[i] = P[i];
	for (int i = 0; i < m; i ++){
		int v, k;
		cin >> v >> k;
		Q[i].F.F = Start[v];
		Q[i].F.S = R[v];
		Q[i].S.F = k;
		Q[i].S.S = i;
		vec[Q[i].F.S].push_back(i);
	}
	for (int i = 0; i < n; i += SQ) Solve(i);
	for (int i = 0; i < m; i ++) cout << ans[i] << endl;
	
	return 0;
}