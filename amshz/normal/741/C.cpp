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
 
const int xn = 2e5 + 10;
const int xm = 10 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, ptr[xn];
bool mark[xn], ans[xn];
vector <pair <int, pii> > adj[xn];

void DFS(int v){
	while (ptr[v] < adj[v].size()){
		pair <int, pii> u = adj[v][ptr[v]];
		if (mark[u.B.A]){
			++ ptr[v];
			continue;
		}
		mark[u.B.A] = true;
		ans[u.B.A] = u.B.B;
		++ ptr[v];
		DFS(u.A);
	}
}

int main(){
    InTheNameOfGod;
    
    cin >> n;
    for (int i = 1; i <= n; ++ i){
    	int v, u;
    	cin >> v >> u;
    	adj[v].push_back({u, {i, 0}});
    	adj[u].push_back({v, {i, 1}});
	}
	for (int i = 1; i <= n + n; i += 2){
		adj[i].push_back({i + 1, {n + i / 2 + 1, 0}});
		adj[i + 1].push_back({i, {n + i / 2 + 1, 1}});
	}
	for (int i = 1; i <= n + n; ++ i)
		DFS(i);
	for (int i = 1; i <= n; ++ i){
		if (ans[i])
			cout << "1 2" << endl;
		else
			cout << "2 1" << endl;
	}
 
    return 0;
}