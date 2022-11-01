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
const int xm = 1e6 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";


int n, m, last[4][xn][xn], a[xn], cnt, ans;
vector <int> vec[2][xm], adj[xm];
string s[xn];
bool flag = true, Mark[xm], fl1, fl2;

int F(int i, int j){
	return i * m + j;
}

void DFS(int v){
	Mark[v] = true;
	a[v] = cnt;
	for (int u : adj[v]){
		if (Mark[u]) continue;
		DFS(u);
	}
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> m;
	for (int i = 0; i < n; ++ i){
		cin >> s[i];
		for (int j = 0; j < m; ++ j){
			if (s[i][j] == '#') vec[0][i].push_back(j), vec[1][j].push_back(i);
		}
	}
	for (int i = 0; i < n; ++ i){
		for (int j = 1; j < SZ(vec[0][i]); ++ j){
			int v = vec[0][i][j - 1], u = vec[0][i][j];
			v = F(i, v);
			u = F(i, u);
			adj[v].push_back(u);
			adj[u].push_back(v);
		}
	}
	for (int i = 0; i < m; ++ i){
		for (int j = 1; j < SZ(vec[1][i]); ++ j){
			int v = vec[1][i][j - 1], u = vec[1][i][j];
			v = F(v, i);
			u = F(u, i);
			adj[v].push_back(u);
			adj[u].push_back(v);
		}
	}
	for (int i = 0; i < n * m; ++ i){
		if (Mark[i] || s[i / m][i % m] == '.') continue;
		++ cnt;
		DFS(i);
	}
	for (int i = 0; i < n * m; ++ i){
		if (s[i / m][i % m] == '#') continue;
		vector <int> V;
		int L = -1, R = SZ(vec[0][i / m]), Mid;
		while (R - L > 1){
			Mid = (L + R) / 2;
			if (vec[0][i / m][Mid] < i % m) L = Mid;
			else R = Mid;
		}
		if (L != -1){
			int v = vec[0][i / m][L];
			v = F(i / m, v);
			V.push_back(a[v]);
		}
		if (R < SZ(vec[0][i / m])){
			int v = vec[0][i / m][R];
			v = F(i / m, v);
			V.push_back(a[v]);
		}
		for (int j = 1; j < SZ(V); ++ j) flag &= (V[j] != V[j - 1]);
		V.clear();
		L = -1, R = SZ(vec[1][i % m]), Mid;
		while (R - L > 1){
			Mid = (L + R) / 2;
			if (vec[1][i % m][Mid] < i / m) L = Mid;
			else R = Mid;
		}
		if (L != -1){
			int v = vec[1][i % m][L];
			v = F(v, i % m);
			V.push_back(a[v]);
		}
		if (R < SZ(vec[1][i % m])){
			int v = vec[1][i % m][R];
			v = F(v, i % m);
			V.push_back(a[v]);
		}
		for (int j = 1; j < SZ(V); ++ j) flag &= (V[j] != V[j - 1]);
	}
	for (int i = 0; i < n; ++ i){
		fl1 |= (SZ(vec[0][i]) == 0);
	}
	for (int j = 0; j < m; ++ j){
		fl2 |= (SZ(vec[1][j]) == 0);
	}
	flag &= (fl1 == fl2);
	if (flag) cout << cnt << endl;
	else cout << -1 << endl;
	
	return 0;
}