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

const int xn = 1e3 + 10;
const int xm = 1e5 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, m, par[xn], sz[xn];
ppi E[xm];
vector <int> ans, V;

int get_root(int v){
	if (v == par[v])
		return v;
	return par[v] = get_root(par[v]);
}
bool merge(int v, int u){
	v = get_root(v);
	u = get_root(u);
	if (v == u)
		return 0;
	if (sz[v] < sz[u])
		swap(v, u);
	par[u] = v;
	sz[v] += sz[u];
	return 1;
}
void bld(){
	for (int i = 1; i <= n; ++ i)
		par[i] = i, sz[i] = 1;
}

int main(){
	fast_io;

	cin >> n >> m;
	bld();
	for (int i = 1; i <= m; ++ i){
		int v, u, t = 0;
		char c;
		cin >> v >> u >> c;
		if (c == 'M')
			t = 1;
		E[i] = {{v, u}, t};
		if (t)
			merge(v, u);
	}
	for (int i = 1; i <= m; ++ i)
		if (!E[i].B && merge(E[i].A.A, E[i].A.B))
			ans.push_back(i);
	for (int i = 1; i <= n; ++ i)
		if (get_root(i) != get_root(1))
			kill(- 1);
	bld();
	for (int x : ans)
		merge(E[x].A.A, E[x].A.B);
	for (int i = 1; i <= m; ++ i)
		if (!E[i].B && merge(E[i].A.A, E[i].A.B))
			V.push_back(i);
	for (int i = SZ(ans); i <= SZ(ans) + SZ(V); ++ i){
		if (i + i != n - 1)
			continue;
		bld();
		while (SZ(ans) < i)
			ans.push_back(V.back()), V.pop_back();
		for (int x : ans)
			merge(E[x].A.A, E[x].A.B);
		for (int j = 1; j <= m; ++ j)
			if (E[j].B && merge(E[j].A.A, E[j].A.B))
				ans.push_back(j);
		cout << SZ(ans) << endl;
		sort(all(ans));
		for (int x : ans)
			cout << x << sep;
		cout << endl;
		return 0;
	}
	kill(- 1);

	return 0;
}