//khodaya khodet komak kon
# include <bits/stdc++.h>

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
# define fast_io                                         ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 256;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 9;//998244353;
const int base = 257;

int n, m, H[xn], par[xn];
int stm[xn], ftm[xn], TM;
pii f[xn];
vector <int> adj[xn], vec[3], V;
vector <pii> E;
bool mark[xn];

void DFS(int v){
	mark[v] = true;
	stm[v] = TM ++;
	for (int u : adj[v]){
		if (mark[u])
			continue;
		par[u] = v;
		H[u] = H[v] + 1;
		DFS(u);
	}
	ftm[v] = TM;
}
bool is_jad(int v, int u){
	return stm[v] <= stm[u] && ftm[u] <= ftm[v];
}
void add(int id, bool f = false){
	if (f)
		reverse(all(V));
	for (int x : V)
		vec[id].push_back(x);
}
void PRINT(pii e1, pii e2){
	if (H[e2.B] < H[e1.B])
		swap(e1, e2);
	int v1 = e1.A, u1 = e1.B;
	int v2 = e2.A, u2 = e2.B;
	cout << "YES" << endl;
	int w = v2;
	while (!is_jad(w, v1))
		w = par[w];
	int ptv = w;
	vec[0].push_back(w);
	while (ptv != u2){
		ptv = par[ptv];
		vec[0].push_back(ptv);
	}
	V.clear();
	ptv = v1;
	while (ptv != w){
		ptv = par[ptv];
		V.push_back(ptv);
	}
	add(1, 1);
	vec[1].push_back(v1);
	vec[1].push_back(u1);
	V.clear();
	ptv = u2;
	while (ptv != u1){
		V.push_back(ptv);
		ptv = par[ptv];
	}
	add(1, 1);
	V.clear();
	ptv = v2;
	while (ptv != w){
		ptv = par[ptv];
		V.push_back(ptv);
	}
	add(2, 1);
	vec[2].push_back(v2);
	vec[2].push_back(u2);
	for (int i = 0; i < 3; ++ i){
		cout << SZ(vec[i]) << sep;
		for (int v : vec[i])
			cout << v << sep;
		cout << endl;
	}
}

int main(){
	fast_io;

	cin >> n >> m;
	while (m --){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
		E.push_back({v, u});
	}
	for (int i = 1; i <= n; ++ i)
		if (!mark[i])
			DFS(i);
	for (pii e : E){
		int v = e.A, u = e.B;
		if (H[v] < H[u])
			swap(v, u);
		if (H[v] == H[u] + 1)
			continue;
		int ptv = v;
		while (ptv != u){
			if (f[ptv].A){
				PRINT(f[ptv], {v, u});
				return 0;
			}
			f[ptv] = {v, u};
			ptv = par[ptv];
		}
	}
	kill("NO");

	return 0;
}