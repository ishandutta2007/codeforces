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
 
const int xn = 4e6 + 10;
const int xm = 1e3 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 2e9 + 10;
const ll INF = 1e18 + 10;
const int MOD = 1e9 + 7;
const int TM = 3;
const int BASE = 257;
 
ll qq, h, g, a[xn], ans;
vector <int> vec;
 
void remove(int v){
	if (!a[v]) return;
	int l = v << 1;
	int r = v << 1 | 1;
	a[v] = max(a[l], a[r]);
	if (a[l] > a[r]) remove(l);
	else remove(r);
}
bool check(int v){
	int l = v << 1;
	int r = v << 1 | 1;
	if (!a[l] && !a[r]) return v >= 1 << g;
	if (a[l] > a[r]) return check(l);
	return check(r);
}
void DFS(int v){
	if (!a[v]) return;
	while (check(v)){
		vec.push_back(v);
		ans -= a[v];
		remove(v);
	}
	int l = v << 1;
	int r = v << 1 | 1;
	DFS(l), DFS(r);
}
 
int main(){
    InTheNameOfGod;
    
    cin >> qq;
    while (qq --){
    	cin >> h >> g, ans = 0;
    	for (int i = 1; i < 1 << h; ++ i) cin >> a[i], ans += a[i];
    	vec.clear(), DFS(1);
    	cout << ans << endl;
    	for (int v : vec) cout << v << sep;
    	cout << endl;
    	fill(a, a + (1 << h), 0);
	}
	
    return 0;
}