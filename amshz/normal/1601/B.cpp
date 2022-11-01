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

const int xn = 3e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, a[xn], b[xn], dist[xn];
pii par[xn];
priority_queue <pii> pq;
vector <pii> adj[xn];
vector <int> ans;

int main(){
	fast_io;

	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	for (int i = 1; i <= n; ++ i)
		cin >> b[i];
	for (int i = 0; i < n; ++ i)
		adj[i].push_back({i + 1, 0});
	for (int i = 1; i <= n; ++ i){
		int v = i + b[i];
		v = v - a[v];
		adj[i].push_back({v, 1});
	}
	for (int i = 0; i <= n; ++ i)
		dist[i] = inf;
	dist[n] = 0;
	pq.push({0, n});
	while (SZ(pq)){
		int v = pq.top().B;
		pq.pop();
		for (pii u : adj[v])
			if (dist[v] + u.B < dist[u.A])
				dist[u.A] = dist[v] + u.B, pq.push({- dist[u.A], u.A}), par[u.A] = {v, u.B};
	}
	if (dist[0] == inf)
		kill(- 1);
	cout << dist[0] << endl;
	int res = 0;
	while (res < n){
		ans.push_back(res);
		while (!par[res].B)
			res = par[res].A;
		res = par[res].A;
	}
	reverse(all(ans));
	for (int v : ans)
		cout << v << sep;
	cout << endl;

	return 0;
}