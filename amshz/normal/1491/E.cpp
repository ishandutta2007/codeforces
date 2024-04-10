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

const int xn = 2e5 + 10;
const int xm = 17 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, f[xn], id[xn], sz[xn];
ppi last;
bool mark[xn];
vector <pii> adj[xn];

void plant(int v, int s, int p = - 1){
	sz[v] = 1;
	for (pii u : adj[v]){
		if (mark[u.B] || u.A == p)
			continue;
		plant(u.A, s, v);
		sz[v] += sz[u.A];
		if (id[sz[u.A]] >= id[s] - 2)
			last = {{v, u.A}, u.B};
	}
}
bool solve(int v, int s = n){
	if (!id[s])
		return false;
	if (s == 1)
		return true;
	last = {{- 1, - 1}, - 1};
	plant(v, s);
	if (last.B == - 1)
		return false;
	mark[last.B] = true;
	int x = sz[last.A.B], u = last.A.A;
	bool fl = solve(last.A.B, x);
	fl &= solve(u, s - x);
	return fl;
}

int main(){
	InTheNameOfGod;

	f[0] = f[1] = 1, id[1] = 5;
	for (int i = 2; i < xm; ++ i)
		f[i] = f[i - 1] + f[i - 2], id[f[i]] = i + 4;
	cin >> n;
	for (int i = 0; i < n - 1; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].push_back({u, i});
		adj[u].push_back({v, i});
	}
	if (solve(1))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}