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

int n, f[xn], cyc[xn], ptr;
vector <int> adj[xn], vec, barg[xn];
vector <pii> ans;
bool mark[xn];

void DFS(int v){
	mark[v] = true;
	if (SZ(adj[v]) == 1)
		barg[ptr].push_back(v);
	for (int u : adj[v])
		if (!mark[u])
			DFS(u);
}

int main(){
	fast_io;

	cin >> n;
	for (int i = 1; i <= n; ++ i){
		cin >> f[i];
		adj[i].push_back(f[i]);
		adj[f[i]].push_back(i);
	}
	for (int v = 1; v <= n; ++ v){
		if (mark[v])
			continue;
		int res = v;
		mark[v] = true;
		vec.clear();
		vec.push_back(v);
		while (!mark[f[res]])
			res = f[res], mark[res] = true, vec.push_back(res);
		for (int x : vec)
			mark[x] = false;
		cyc[++ ptr] = res;
		DFS(res);
	}
	if (ptr == 1){
		cout << SZ(barg[1]) << endl;
		for (int x : barg[1])
			cout << cyc[1] << sep << x << endl;
		return 0;
	}
	for (int i = 1; i <= ptr; ++ i){
		int j = i + 1;
		if (i == ptr)
			j = 1;
		if (SZ(barg[j]))
			ans.push_back({cyc[i], barg[j].back()}), barg[j].pop_back();
		else
			ans.push_back({cyc[i], cyc[j]});
	}
	for (int i = 1; i <= ptr; ++ i)
		for (int x : barg[i])
			ans.push_back({cyc[i], x});
	cout << SZ(ans) << endl;
	for (pii x : ans)
		cout << x.A << sep << x.B << endl;

	return 0;
}