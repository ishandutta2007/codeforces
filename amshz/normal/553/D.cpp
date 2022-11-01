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

const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, m, k, a[xn], b[xn], d[xn];
bool mark[xn];
queue <int> q;
vector <int> adj[xn];
set <int> st;

bool check(ld t){
	for (int v = 1; v <= n; ++ v){
		ld x = t * d[v];
		int y = x;
		if (y < x)
			++ y;
		b[v] = d[v] - y + 1;
		mark[v] = false;
	}
	for (int i = 1; i <= k; ++ i)
		mark[a[i]] = true, q.push(a[i]);
	while (SZ(q)){
		int v = q.front();
		q.pop();
		for (int u : adj[v]){
			if (mark[u])
				continue;
			-- b[u];
			if (!b[u])
				q.push(u), mark[u] = true;
		}
	}
	st.clear();
	for (int i = 1; i <= n; ++ i)
		if (!mark[i])
			st.insert(i);
	if (SZ(st))
		return true;
	return false;
}

int main(){
	fast_io;

	cin >> n >> m >> k;
	for (int i = 1; i <= k; ++ i)
		cin >> a[i];
	while (m --){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
		++ d[v], ++ d[u];
	}
	int qq = 50;
	ld l = 0, r = 1;
	while (qq --){
		ld md = (l + r) / 2;
		if (check(md))
			l = md;
		else
			r = md;
	}
	check(l);
	cout << SZ(st) << endl;
	for (int x : st)
		cout << x << sep;
	cout << endl;

	return 0;
}