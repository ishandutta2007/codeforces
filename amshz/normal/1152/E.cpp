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
typedef pair <ll, ll>                                    pll;
typedef pair <pll, pll>                                  ppp;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 2e5 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int MOD = 998244353;
const int TM = 3;
const int BASE = 257;

int n, m, a[xn], b[xn], tab[xn], S, ptr[xn], d[xn];
unordered_map <int, int> mp;
vector <int> vec, tour;
vector <pii> adj[xn];
bool mark[xn];

void DFS(int v){
	while (ptr[v] < SZ(adj[v])){
		pii u = adj[v][ptr[v]];
		++ ptr[v];
		if (mark[u.B]) continue;
		mark[u.B] = true;
		DFS(u.A);
	}
	tour.push_back(tab[v]);
}

int main(){
    InTheNameOfGod;
    
    cin >> n, -- n;
    for (int i = 0; i < n; ++ i) cin >> a[i], vec.push_back(a[i]);
    for (int i = 0; i < n; ++ i) cin >> b[i], vec.push_back(b[i]);
    for (int i = 0; i < n; ++ i) if (b[i] < a[i]) kill(- 1);
    Sort(vec);
    for (int i = 0; i < SZ(vec); ++ i){
    	if (!i || vec[i] != vec[i - 1]){
    		mp[vec[i]] = ++ S;
    		tab[S] = vec[i];
		}
	}
	for (int i = 0; i < n; ++ i){
		adj[mp[a[i]]].push_back({mp[b[i]], i});
		adj[mp[b[i]]].push_back({mp[a[i]], i});
		++ d[mp[a[i]]];
		++ d[mp[b[i]]];
	}
	vec.clear();
	for (int i = 1; i <= S; ++ i) if (d[i] % 2) vec.push_back(i);
	if (SZ(vec) > 2) kill(- 1);
	vec.push_back(1);
	DFS(vec.front());
	if (SZ(tour) != n + 1) kill(- 1);
	for (int v : tour) cout << v << sep;
	cout << endl;
	
    return 0;
}