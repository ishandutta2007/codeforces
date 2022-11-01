# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <pii, int> ppp;
 
# define A first
# define B second
# define endl '\n'
# define sep ' '
# define pb push_back
# define InTheNameOfGod ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 19 + 10;
const int xm = 7e5 + 10;
const int SQ = 320;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}


int n, m;
ll dp[xm][xn], ans;
bool adj[xn][xn];


int main(){
	InTheNameOfGod;
	
	cin >> n >> m;
	for (int i = 0; i < m; i ++){
		int v, u;
		cin >> v >> u;
		v --, u --;
		adj[v][u] = adj[u][v] = true;
	}
	for (int i = 0; i < n; i ++) dp[1 << i][i] = 1;
	for (int mask = 0; mask < 1 << n; mask ++){
		int s = __builtin_ctz(mask);
		for (int v = 0; v < n; v ++)
			for (int u = s + 1; u < n; u ++)
				if ((mask&(1 << u)) == 0 && adj[v][u]) 
					dp[mask | (1 << u)][u] += dp[mask][v];
	}
	for (int mask = 0; mask < 1 << n; mask ++){
		if (__builtin_popcount(mask) < 3) continue;
		int s = __builtin_ctz(mask);
		for (int v = 0; v < n; v ++)
			if (mask&(1 << v) && adj[v][s]) 
				ans += dp[mask][v];;
	}
	cout << ans / 2 << endl;
	
	return 0;
}