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
typedef pair <ll , ll >                                  pll;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;//998244353;
const int xn = 1e3 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
string abc = "abcdefghijklmnopqrstuvwxyz";


int n, m, dist[xn * xn], t;
ll x, y, p;
vector <int> adj[xn * xn];
string s[xn];
queue <int> q;

int f(int i, int j){
	return i * m + j;
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> m >> t;
	for (int i = 0; i < n; ++ i) cin >> s[i];
	memset(dist, -1, sizeof dist);
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < m; ++ j){
			if (i && s[i - 1][j] == s[i][j]) dist[f(i, j)] = 0;
			if (i < n - 1 && s[i + 1][j] == s[i][j]) dist[f(i, j)] = 0;
			if (j && s[i][j - 1] == s[i][j]) dist[f(i, j)] = 0;
			if (j < m - 1 && s[i][j + 1] == s[i][j]) dist[f(i, j)] = 0;
			int v = f(i, j);
			if (i) adj[v].push_back(f(i - 1, j));
			if (i < n - 1) adj[v].push_back(f(i + 1, j));
			if (j) adj[v].push_back(f(i, j - 1));
			if (j < m - 1) adj[v].push_back(f(i, j + 1));
			if (dist[v] != -1) q.push(v);
		}
	}
	while (q.size()){
		int v = q.front();
		q.pop();
		for (int u : adj[v]){
			if (dist[u] != -1) continue;
			q.push(u);
			dist[u] = dist[v] + 1;
		}
	}
	while (t --){
		cin >> x >> y >> p;
		-- x, -- y;
		int flag = s[x][y] - '0';
		if (dist[f(x, y)] == -1) cout << flag << endl;
		else if (p < dist[f(x, y)]) cout << flag << endl;
		else cout << (flag + (p - dist[f(x, y)])) % 2 << endl;
	}
	
	return 0;
}