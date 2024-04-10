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
 
const int xn = 3e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ll mod = 1e9 + 7;
const int base = 257;

int n, m;
ll dist[2][xn], D[xn], sz[xn], mx = - INF, res[2] = {- INF, - INF}, a, b, c, d;
vector <pair <ll, ll> > adj[xn], vec[2];
bool flag, f[xn];

void DFS(int v, int ind, int par = - 1){
	sz[v] = 1;
	for (pii u : adj[v]){
		if (u.A == par) continue;
		dist[ind][u.A] = dist[ind][v] + u.B;
		DFS(u.A, ind, v);
		f[v] |= f[u.A];
	}
	for (pii u : adj[v]){
		if (u.A == par) continue;
		sz[v] += sz[u.A];
		if (!f[u.A] && !ind && f[v]){
			D[v] += sz[u.A];
			vec[0].push_back({dist[0][v], dist[0][u.A]});
			vec[1].push_back({dist[1][v], dist[1][u.A]});
		}
	}
	flag |= (D[v] > 1);
	if (!D[v] && !ind && f[v]){
		vec[0].push_back({dist[0][v], - INF});
		vec[1].push_back({dist[1][v], - INF});
	}
}

int main(){
    InTheNameOfGod;
    
    cin >> n >> m;
    for (int i = 0; i < n - 1; ++ i){
    	int v, u, w;
    	cin >> v >> u >> w;
    	adj[v].push_back({u, w});
    	adj[u].push_back({v, w});
	}
	DFS(n, 1);
	memset(f, false, sizeof f);
	memset(D, 0, sizeof D);
	flag = false;
	f[n] = true;
	DFS(1, 0);
	if (flag) mx = INF;
	reverse(all(vec[0]));
	reverse(all(vec[1]));
	for (int i = 0; i < vec[0].size(); ++ i){
		if (i) a = vec[0][i - 1].A;
		if (i) b = vec[0][i - 1].B;
		if (!i) a = b = - INF;
		c = vec[1][i].A;
		d = vec[1][i].B;
		res[1] = max(res[1], b);
		mx = max(mx, c + res[0]);
		mx = max(mx, c + res[1]);
		res[0] = max(res[0], a);
		mx = max(mx, d + res[0]);
		mx = max(mx, d + res[1]);
	}
	if (mx < 0) mx = INF;
	while (m --){
		cin >> a;
		cout << min(dist[0][n], mx + a) << endl;
	}
	
    return 0;
}