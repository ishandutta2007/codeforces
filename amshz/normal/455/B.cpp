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
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

//const ll md = 1e9 + 7;//998244353;
const int xn = 1e5 + 10;
const int xm = 1e2 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int MOD = 1e9 + 7;
const int TM = 3;
const int Base = 257;

int n, k, col[xn][26], ptr = 1, d[xn];
string s[xn], t;
pair <bool, bool> dp[xn];

void DFS(int v){
	for (int c = 0; c < 26; ++ c){
		int u = col[v][c];
		if (!u) continue;
		DFS(u);
		++ d[v];
		dp[v].A |= !dp[u].A;
		dp[v].B |= !dp[u].B;
	}
	if (!d[v]) dp[v] = {false, true};
}
void add(int v, int ind){
	if (ind == SZ(t)) return;
	if (!col[v][t[ind] - 'a']) col[v][t[ind] - 'a'] = ++ ptr;
	add(col[v][t[ind] - 'a'], ind + 1);
}

int main(){
    InTheNameOfGod;
    
    cin >> n >> k;
    for (int i = 0; i < n; ++ i) cin >> s[i], t = s[i], add(1, 0);
    DFS(1);
    if (!dp[1].A || (dp[1].A && !dp[1].B && k % 2 == 0)) kill("Second");
    kill("First");
	
    return 0;
}