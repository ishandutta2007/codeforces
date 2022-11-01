# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 3e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int qq, n, a[xn], part[xn], mx;
vector <int> adj[xn];

int main(){
    InTheNameOfGod;
    
	cin >> qq;
	while (qq --){
		cin >> n;
		for (int i = 1; i <= n; ++ i){
			part[i] = inf;
			adj[i].clear();
			adj[i].push_back(0);
		}
		for (int i = 1; i <= n; ++ i){
			cin >> a[i];
			adj[a[i]].push_back(i);
		}
		for (int i = 1; i <= n; ++ i) adj[i].push_back(n + 1);
		for (int i = 1; i <= n; ++ i){
			if (adj[i].size() < 2) continue;
			mx = 0;
			for (int j = 1; j < adj[i].size(); ++ j) mx = max(mx, adj[i][j] - adj[i][j - 1]);
			part[mx] = min(part[mx], i);
		}
		for (int i = 2; i <= n; ++ i) part[i] = min(part[i], part[i - 1]);
		for (int i = 1; i <= n; ++ i){
			if (part[i] == inf) cout << - 1 << sep;
			else cout << part[i] << sep;
		}
		cout << endl;
	}
 
    return 0;
}