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

const int xn = 1e6 + 10;
const int xm = 2e5 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, q, a[xn], ord[xn], par[xn], sz[xn], b[xn];
vector <int> vec[xn];
bool p[xn];
unordered_map <int, bool> mp[xm];

int get_root(int v){
	if (v == par[v])
		return v;
	return par[v] = get_root(par[v]);
}
void merge(int v, int u){
	v = get_root(v);
	u = get_root(u);
	if (v == u)
		return;
	par[u] = v;
	sz[v] += sz[u];
}

int main(){
	fast_io;

	cin >> n >> q;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i], par[i] = i, sz[i] = 1, ord[a[i]] = i;
	for (int i = 2; i < xn; ++ i){
		int last = - 1;
		for (int j = i; j < xn; j += i){
			if (last != - 1 && ord[j])
				merge(last, ord[j]);
			if (ord[j])
				last = ord[j];
			if (i < j)
				p[j] = true;
			if (!p[i])
				vec[j].push_back(i);
		}
	}
	for (int i = 1; i <= n; ++ i){
		int rt = get_root(i);
		for (int x : vec[a[i]])
			b[x] = rt;
	}
	for (int i = 1; i <= n; ++ i){
		int rt = get_root(i);
		for (int j = 0; j < SZ(vec[a[i] + 1]); ++ j){
			int v = vec[a[i] + 1][j];
			if (!b[v])
				continue;
			v = b[v];
			mp[v][rt] = true;
			for (int k = 0; k < j; ++ k){
				int u = vec[a[i] + 1][k];
				if (!b[u])
					continue;
				u = b[u];
				v = get_root(v);
				u = get_root(u);
				mp[v][u] = true;
			}
		}
	}
	while (q --){
		int s, t;
		cin >> s >> t;
		s = get_root(s);
		t = get_root(t);
		if (s == t)
			cout << 0 << endl;
		else if (mp[s][t] || mp[t][s])
			cout << 1 << endl;
		else
			cout << 2 << endl;
	}

	return 0;
}