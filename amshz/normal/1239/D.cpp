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

const int xn = 1e6 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int qq, n, m, col[xn], ptr, sz[xn];
vector <int> adj[2][xn], mellat;
bool mark[xn];

void DFS(int v){
	mark[v] = true;
	for (int u : adj[0][v])
		if (!mark[u])
			DFS(u);
	mellat.push_back(v);
}
void SFD(int v, int c){
	mark[v] = true;
	col[v] = c;
	++ sz[c];
	for (int u : adj[1][v])
		if (!mark[u])
			SFD(u, c);
}

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n >> m;
		for (int i = 1; i <= n; ++ i){
			adj[0][i].clear();
			adj[1][i].clear();
			mark[i] = false;
			sz[i] = 0;
		}
		mellat.clear();
		while (m --){
			int v, u;
			cin >> v >> u;
			adj[0][v].push_back(u);
			adj[1][u].push_back(v);
		}
		for (int i = 1; i <= n; ++ i)
			if (!mark[i])
				DFS(i);
		fill(mark, mark + n + 1, false);
		reverse(all(mellat));
		for (int v : mellat)
			if (!mark[v])
				SFD(v, ++ ptr);
		if (sz[ptr] == n){
			cout << "No" << endl;
			continue;
		}
		cout << "Yes" << endl;
		cout << sz[ptr] << sep << n - sz[ptr] << endl;
		for (int i = 1; i <= n; ++ i)
			if (col[i] == ptr)
				cout << i << sep;
		cout << endl;
		for (int i = 1; i <= n; ++ i)
			if (col[i] != ptr)
				cout << i << sep;
		cout << endl;
	}

	return 0;
}