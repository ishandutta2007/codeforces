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

const int xn = 5e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int qq, n, cnt, d[xn];
vector <int> adj[xn];
string S;
bool flag;

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n;
		for (int i = 1; i <= n; ++ i)
			adj[i].clear(), d[i] = 0;
		for (int i = 0; i < n - 1; ++ i){
			int v, u;
			cin >> v >> u;
			adj[v].push_back(u);
			adj[u].push_back(v);
			++ d[v], ++ d[u];
		}
		cin >> S, S = '.' + S;
		flag = false;
		for (int v = 1; v <= n; ++ v)
			for (int u : adj[v])
				flag |= S[v] == 'W' && S[u] == 'W';
		if (n < 3){
			cout << "Draw" << endl;
			continue;
		}
		if (flag){
			cout << "White" << endl;
			continue;
		}
		for (int i = 1; i <= n; ++ i)
			flag |= 3 < d[i];
		if (flag){
			cout << "White" << endl;
			continue;
		}
		cnt = 0;
		for (int i = 1; i <= n; ++ i){
			cnt += S[i] == 'W';
			flag |= (S[i] == 'W' && 1 < d[i]);
		}
		if (n == 3 && cnt == 2){
			cout << "White" << endl;
			continue;
		}
		if (n < 4){
			cout << "Draw" << endl;
			continue;
		}
		if (flag){
			cout << "White" << endl;
			continue;
		}
		for (int i = 1; i <= n; ++ i)
			for (int u : adj[i])
				flag |= (S[i] == 'W' && 2 < d[u]);
		if (flag){
			cout << "White" << endl;
			continue;
		}
		for (int v = 1; v <= n; ++ v){
			if (d[v] < 3)
				continue;
			int ted = 0;
			for (int u : adj[v])
				ted += d[u] == 1;
			flag |= ted < 2;
		}
		if (flag){
			cout << "White" << endl;
			continue;
		}
		int ted = 0;
		for (int v = 1; v <= n; ++ v)
			ted += d[v] == 3;
		if (ted == 2){
			if (n % 2)
				cout << "White" << endl;
			else
				cout << "Draw" << endl;
			continue;
		}
		if (!cnt){
			cout << "Draw" << endl;
			continue;
		}
		if (ted && n % 2 == 0){
			cout << "White" << endl;
			continue;
		}
		if (!ted && cnt == 2 && n % 2){
			cout << "White" << endl;
			continue;
		}
		cout << "Draw" << endl;
	}

	return 0;
}