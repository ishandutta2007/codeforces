//khodaya khodet komak kon
# include <bits/stdc++.h>
 
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
# define fast_io                                         ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;
 
int qq, n, a[xn], b[xn], cnt[xn], mx, root, mark[xn];
vector <int> adj[xn];
bool ans;
 
void DFS(int v){
	mark[v] = 1;
	for (int u : adj[v]){
		ans |= mark[u] == 1;
		if (!mark[u])
			DFS(u);
	}
	mark[v] = 2;
}
 
int main(){
	fast_io;
 
	cin >> qq;
	while (qq --){
		cin >> n;
		for (int i = 1; i <= n; ++ i){
			cnt[i] = 0;
			adj[i].clear();
			mark[i] = 0;
		}
		for (int i = 1; i <= n; ++ i){
			cin >> a[i];
			++ cnt[a[i]];
		}
		for (int i = 1; i <= n; ++ i)
			cin >> b[i];
		mx = 0;
		for (int i = 1; i <= n; ++ i)
			mx = max(mx, cnt[i]);
		for (int i = 1; i <= n; ++ i)
			if (mx == cnt[i])
				root = i;
		for (int i = 1; i <= n; ++ i)
			if (a[i] != root && b[i] != root)
				adj[a[i]].push_back(b[i]);
		ans = false;
		for (int i = 1; i <= n; ++ i)
			if (!mark[i])
				DFS(i);
		if (ans)
			cout << "WA" << endl;
		else
			cout << "AC" << endl;
	}
 
	return 0;
}