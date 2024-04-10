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
const int xn = 3e5 + 10;
const int xm = 20;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";

int n, m, qq, ted;
vector <pii> adj[xn];
vector <int> Matching;
bool flag[xn];

void Solve(){
	cin >> n >> m;
	for (int i = 1; i <= 3 * n; ++ i) adj[i].clear(), flag[i] = false;
	Matching.clear();
	for (int i = 1; i <= m; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].push_back({u, i});
		adj[u].push_back({v, i});
	}
	for (int v = 1; v <= n * 3; ++ v){
		flag[v] = true;
		for (pii u : adj[v]){
			if (u.A > v) continue;
			if (flag[u.A]){
				flag[u.A] = false;
				Matching.push_back(u.B);
				flag[v] = false;
				break;
			}
		}
	}
	ted = 0;
	for (int v = 1; v <= n * 3; ++ v) ted += flag[v];
	if (ted >= n){
		cout << "IndSet" << endl;
		ted = n;
		for (int v = 1; v <= 3 * n; ++ v){
			if (flag[v]) cout << v << sep, -- ted;
			if (!ted) break;
		}
		cout << endl;
		return;
	}
	cout << "Matching" << endl;
	for (int i = 0; i < n; ++ i) cout << Matching[i] << sep;
}

 
int main(){
	InTheNameOfGod;
	
	cin >> qq;
	while (qq --) Solve();
	
	return 0;
}