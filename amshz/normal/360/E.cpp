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

const int xn = 2e4 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

ll n, m, k, s1, s2, f, dist[2][xn], W[xn];
ppp E[xn];
set <pll> st;
vector <pii> adj[xn];
bool mark[xn];

void dijktra(int s, int id){
	for (int i = 1; i <= n; ++ i)
		dist[id][i] = INF, mark[i] = false;
	dist[id][s] = 0;
	for (int i = 1; i <= n; ++ i)
		st.insert({dist[id][i], i});
	while (SZ(st)){
		int v = st.begin() -> B;
		st.erase(st.begin());
		mark[v] = true;
		for (pii u : adj[v]){
			if (mark[u.A])
				continue;
			st.erase({dist[id][u.A], u.A});
			dist[id][u.A] = min(dist[id][u.A], dist[id][v] + W[u.B]);
			st.insert({dist[id][u.A], u.A});
		}
	}
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> m >> k >> s1 >> s2 >> f;
	for (int i = 0; i < m; ++ i){
		int v, u;
		cin >> v >> u >> W[i];
		adj[v].push_back({u, i});
	}
	for (int i = 0; i < k; ++ i){
		int v, u, l, r;
		cin >> v >> u >> l >> r;
		E[i] = {{v, u}, {l, r}}, W[i + m] = r;
		adj[v].push_back({u, i + m});
	}
	for (int t = 0; t < k; ++ t){
		dijktra(s1, 0), dijktra(s2, 1);
		for (int i = 0; i < k; ++ i)
			if (dist[0][E[i].A.A] < dist[1][E[i].A.A])
				W[i + m] = E[i].B.A;
	}
	if (dist[0][f] < dist[1][f])
		cout << "WIN" << endl;
	else if (dist[0][f] == dist[1][f])
		cout << "DRAW" << endl;
	else
		kill("LOSE");
	for (int i = 0; i < k; ++ i)
		cout << W[i + m] << sep;
	cout << endl;

	return 0;
}