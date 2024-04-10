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
typedef pair <ll, ll>                                    pll;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, f[xn], sz[xn], ptr;
string s;
vector <int> adj[xn];
vector <pii> ans;

void DFS(int v){
	sz[v] = 1;
	for (int u : adj[v]){
		DFS(u);
		sz[v] += sz[u];
	}
}

int main(){
    InTheNameOfGod;
    
    cin >> s;
    n = SZ(s);
    for (int i = 1; i < n; ++ i){
    	while (ptr && s[ptr] != s[i]) ptr = f[ptr];
    	if (s[ptr] == s[i]) ++ ptr;
    	f[i + 1] = ptr;
	}
	for (int i = 1; i <= n; ++ i)
		adj[f[i]].push_back(i);
	DFS(0);
	ptr = n;
	while (ptr){
		ans.push_back({ptr, sz[ptr]});
		ptr = f[ptr];
	}
	cout << SZ(ans) << endl;
	reverse(all(ans));
	for (pii x : ans)
		cout << x.A << sep << x.B << endl;

    return 0;
}