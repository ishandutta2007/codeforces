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
 
const ll md = 1e9 + 7;
const ll MD = md * 100;
const int xn = 1e5+10;
const int xlg = 22;
const int SQ = 233;
const int sq = 1e5+10;
const ll inf = 1e18+10;
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
 
 
int n, qq, Par[xn][xlg], Mx[xn][xlg], cnt = 0, S = 1, Start[xn], T, Finish[xn], h[xn];
vector <pii> adj[xn], vec;
vector <int> vc;
pii Q[xn];
bool mark[xn];
 
 
void DFS(int v){
	Start[v] = T ++;
	for (int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i].F, ind = adj[v][i].S;
		Par[u][0] = v;
		Mx[u][0] = ind;
		h[u] = h[v] + 1;
		DFS(u);
	}
	Finish[v] = T ++;
}
 
 
 
int main(){
	fast_io;
	
	cin >> n >> qq;
	int t, v, u, x;
	while (qq--){
		cin >> t;
		if (t == 1){
			cin >> v >> u;
			//if (v == 1 && u == 2 && n == 1e5) cout << cnt << endl;
			adj[u].push_back({v, cnt ++});
			mark[v] = true;
		}
		else if (t == 2){
			cin >> v;
			Q[S ++] = {v, cnt ++};
		}
		else{
			cin >> v >> x;
			vec.push_back({v, x});
			vc.push_back(cnt ++);
		}
	}
	
	for (int i = 1; i <= n; i++){
		if (mark[i]) continue;
		DFS(i);
	}
	
	for (int j = 1; j <= 21; j++){
		for (int i = 1; i <= n; i++){
			Par[i][j] = Par[Par[i][j - 1]][j - 1];
			Mx[i][j] = max(Mx[i][j - 1], Mx[Par[i][j - 1]][j - 1]);
		}
	}
	
	for (int i = 0; i < vec.size(); i++){
		int v = vec[i].F, x = vec[i].S;
		int u = Q[x].F, ind = vc[i];
		int uu = u;
		if (Start[v] > Start[u] || Finish[v] < Finish[u] || h[v] > h[u] || Q[x].S > ind){
			cout << "NO" << endl;
			continue;
		}
		int mx = -1;
		ll dist = h[u] - h[v];
		ll dis = dist;
		for (int j = 21; j >= 0; j--){
			if ((1 << j) > dist) continue;
			mx = max(mx, Mx[u][j]);
			u = Par[u][j];
			dist -= (1 << j);
		}
		if (mx < ind && Q[x].S > mx){
			cout << "YES" << endl;
			continue;
		}
		cout << "NO" << endl;
	}
	
	
	return 0;
}