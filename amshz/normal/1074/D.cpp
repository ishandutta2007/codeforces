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

const int xn = 4e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int q, par[xn], sz[xn], a[xn], last, n;
unordered_map <int, int> mp;
vector <int> vec[xn];

int get_root(int v){
	if (par[v] == v)
		return v;
	return par[v] = get_root(par[v]);
}

int main(){
	InTheNameOfGod;

	for (int i = 0; i < xn; ++ i)
		par[i] = i, sz[i] = 1, vec[i].push_back(i);
	cin >> q;
	while (q --){
		int t, v, u, vv, uu, w;
		cin >> t >> v >> u;
		if (t == 1){
			cin >> w;
			v ^= last, u ^= last, w ^= last;
			if (u < v)
				swap(u, v);
			-- v;
			if (!mp[v])
				mp[v] = ++ n;
			if (!mp[u])
				mp[u] = ++ n;
			v = mp[v], u = mp[u];
			vv = get_root(v);
			uu = get_root(u);
			if (vv == uu)
				continue;
			if (sz[vv] < sz[uu])
				swap(vv, uu);
			w ^= a[v] ^ a[u];
			for (int x : vec[uu]){
				vec[vv].push_back(x);
				a[x] ^= w;
			}
			par[uu] = vv;
			sz[vv] += sz[uu];
		}
		else{
			v ^= last, u ^= last;
			if (u < v)
				swap(v, u);
			-- v;
			if (!mp[v])
				mp[v] = ++ n;
			if (!mp[u])
				mp[u] = ++ n;
			v = mp[v], u = mp[u];
			last = a[v] ^ a[u];
			if (get_root(v) != get_root(u))
				last = - 1;
			cout << last << endl;
			if (last == - 1)
				last = 1;
		}
	}

	return 0;
}