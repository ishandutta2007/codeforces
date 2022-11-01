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

const int xn = 5e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, m, k, H[xn], par[xn], bdg[3];
vector <int> adj[xn], leaf;
bool mark[xn];

void DFS(int v){
	mark[v] = true;
	int ted = 0;
	for (int u : adj[v]){
		if (mark[u])
			continue;
		++ ted;
		H[u] = H[v] + 1;
		par[u] = v;
		DFS(u);
	}
	if (!ted)
		leaf.push_back(v);
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> m >> k;
	while (m --){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	H[1] = 1, DFS(1);
	for (int v : leaf){
		if (H[v] < (n + k - 1) / k)
			continue;
		cout << "PATH" << endl;
		cout << H[v] << endl;
		int res = v;
		while (res){
			cout << res << sep;
			res = par[res];
		}
		cout << endl;
		return 0;
	}
	cout << "CYCLES" << endl;
	leaf.resize(k);
	for (int v : leaf){
		int pt = 0;
		for (int u : adj[v])
			if (u != par[v])
				bdg[pt ++] = u;
		int p1 = bdg[0], p2 = bdg[1];
		if ((H[v] - H[p1] + 1) % 3){
			cout << H[v] - H[p1] + 1 << endl;
			int res = v;
			while (H[res] >= H[p1]){
				cout << res << sep;
				res = par[res];
			}
			cout << endl;
			continue;
		}
		if ((H[v] - H[p2] + 1) % 3){
			cout << H[v] - H[p2] + 1 << endl;
			int res = v;
			while (H[res] >= H[p2]){
				cout << res << sep;
				res = par[res];
			}
			cout << endl;
			continue;
		}
		if (H[p1] < H[p2])
			swap(p1, p2);
		cout << H[p1] - H[p2] + 2 << endl;
		cout << v << sep;
		int res = p1;
		while (H[res] >= H[p2]){
			cout << res << sep;
			res = par[res];
		}
		cout << endl;
	}

	return 0;
}