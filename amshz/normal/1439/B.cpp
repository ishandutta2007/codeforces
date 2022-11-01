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
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int SQ = 450;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int qq, n, m, k, d[xn], ptr, a[xn], p[xn];
set <pii> st;
vector <int> adj[xn], adj2[xn], vec;
bool flag, mark[xn];

int main(){
	InTheNameOfGod;
	
	cin >> qq;
	while (qq --){
		cin >> n >> m >> k;
		for (int i = 1; i <= n; ++ i)
			adj[i].clear(), mark[i] = false, d[i] = 0, adj2[i].clear();
		while (m --){
			int v, u;
			cin >> v >> u;
			adj[v].push_back(u);
			adj[u].push_back(v);
			++ d[v], ++ d[u];
		}
		st.clear();
		for (int i = 1; i <= n; ++ i)
			st.insert({d[i], i});
		ptr = 0;
		flag = true;
		while (SZ(st)){
			int v = st.begin() -> B;
			mark[v] = true;
			p[v] = ptr;
			a[ptr ++] = v;
			if (d[v] >= k)
				break;
			st.erase(st.begin());
			for (int u : adj[v]){
				if (mark[u])
					continue;
				st.erase({d[u], u});
				-- d[u];
				st.insert({d[u], u});
			}
		}
		if (!SZ(st)) flag = false;
		if (flag){
			cout << 1 << sep << SZ(st) << endl;
			for (pii v : st)
				cout << v.B << sep;
			cout << endl;
			continue;
		}
		for (int i = 0; i < ptr; ++ i)
			for (int u : adj[a[i]])
				if (p[u] > i)
					adj2[a[i]].push_back(u);
		for (int i = 1; i <= n; ++ i)
			mark[i] = false;
		for (int i = 0; i < ptr; ++ i){
			int v = a[i];
			if (d[v] != k - 1 || k > SQ)
				continue;
			vec.clear();
			for (int u : adj2[v]){
				vec.push_back(u);
				mark[u] = true;
			}
			vec.push_back(v);
			int ted = 0;
			for (int v : vec)
				for (int u : adj2[v])
					ted += (mark[u]);
			for (int v : vec)
				mark[v] = false;
			if (ted == (k - 1) * (k) / 2){
				cout << 2 << endl;
				for (int v : vec)
					cout << v << sep;
				cout << endl;
				flag = true;
				break;
			}
		}
		if (!flag)
			cout << - 1 << endl;
	}
	
	return 0;
}