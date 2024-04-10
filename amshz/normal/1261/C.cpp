# include <bits/stdc++.h>
 
using namespace std;
 
/*
// ordered_set 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/
 
typedef long long                         ll;
typedef long double                       ld;
typedef pair <int, int>                   pii;
typedef pair <pii, int>                   ppi;
typedef pair <pii, pii>                   pip;
 
# define A                                first
# define B                                second
# define endl                             '\n'
# define sep                              ' '
# define all(x)                           x.begin(), x.end()
# define Kill(x)                          return cout << x << endl, 0
# define SZ(x)                            int(x.size())
# define InTheNameOfGod                   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 998244353;
const int xn = 4e6;
const int xm = 20;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";
 

int n, m, dist[2][xn], mx, ted, t;
string a[xn];
bool flag[xn];
queue <int> q;
vector <int> adj[xn], H[xn];

int f(int i, int j){return i * (m + 2) + j;}

bool Check(int T){
	for (int i = 0; i <= n + 1; ++ i) for (int j = 0; j <= m + 1; ++ j) dist[1][f(i, j)] = -1;
	for (int i = T; i <= mx; ++ i) for (int v : H[i]) q.push(v), dist[1][v] = 0;
	t = 0;
	while (q.size()){
		int v = q.front();
		q.pop();
		if (dist[1][v] <= T) t += flag[v];
		for (int u : adj[v]){
			if (dist[1][u] != -1) continue;
			dist[1][u] = dist[1][v] + 1;
			q.push(u);
		}
	}
	return t == ted;
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) cin >> a[i], a[i] = '.' + a[i] + '.';
	for (int i = 0; i <= m + 1; ++ i) a[n + 1] += '.', a[0] += '.';
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j)
			for (int k = -1; k <= 1; ++ k)
				for (int l = -1; l <= 1; ++ l)
					if ((k != 0 || l != 0))
						adj[f(i, j)].push_back(f(i + k, j + l));
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j)
			if (a[i][j] == 'X')
				for (int k : adj[f(i, j)])
					flag[f(i, j)] |= (a[k / (m + 2)][k % (m + 2)] == '.');
	for (int i = 0; i <= n + 1; ++ i) for (int j = 0; j <= m + 1; ++ j) dist[0][f(i, j)] = -1;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j)
			if (flag[f(i, j)]) q.push(f(i, j)), dist[0][f(i, j)] = 0, ++ ted;
	while (q.size()){
		int v = q.front();
		q.pop();
		if (a[v / (m + 2)][v % (m + 2)] == 'X'){	
			H[dist[0][v]].push_back(v);
			mx = max(mx, dist[0][v]);
		}
		for (int u : adj[v]){
			if (dist[0][u] != -1) continue;
			dist[0][u] = dist[0][v] + 1;
			q.push(u);
		}
	}
	
	int L = 0, R = mx + 1, Mid;
	while (R - L > 1){
		Mid = (L + R) / 2;
		if (Check(Mid)) L = Mid;
		else R = Mid;
	}
	cout << L << endl;
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= m; ++ j){
			if (dist[0][f(i, j)] >= L && a[i][j] == 'X') cout << 'X';
			else cout << '.';
		}
		cout << endl;
	}
	
	return 0;
}