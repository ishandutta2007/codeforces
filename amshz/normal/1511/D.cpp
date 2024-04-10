// khodaya khodet komak kon
// Maybe on the Moon
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
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, k, pt[xn];
bool mark[xn];
vector <pii> adj[xn];
vector <int> tr;

void DFS(int v){
	while (pt[v] < SZ(adj[v])){
		int u = adj[v][pt[v]].A, id = adj[v][pt[v]].B;
		++ pt[v];
		if (mark[id])
			continue;
		mark[id] = true;
		DFS(u);
	}
	tr.push_back(v);
}

int main(){
	//InTheNameOfGod;

	cin >> n >> k;
	for (int i = 0; i < k; ++ i)
		for (int j = 0; j < k; ++ j)
			adj[i].push_back({j, i * k + j});
	DFS(0), tr.pop_back();
	for (int i = 0; i < n; ++ i)
		cout << char('a' + tr[i % SZ(tr)]);
	cout << endl;

	return 0;
}