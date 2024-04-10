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

const ll md = 101111111111;
const int xn = 2e7 + 10;
const int xm = 1e6 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int MOD[4] = {1000000009, 1000000007, 987654319, 999999937};
const int TM = 3;
const int BASE = 257;

ll n, num[xm], part[xm], ans, flag, flg, k, col[xn][2], ptr = 1, cnt[xn], t;


void get(ll v, ll bit){
	if (bit == -1 || !v) return;
	flag = ((k & (1LL << bit)) > 0);
	flg = ((t & (1LL << bit)) > 0);
	if (!flag) ans += cnt[col[v][1 - flg]];
	get(col[v][flag ^ flg], bit - 1);
}
void add(ll v, ll bit){
	if (bit == -1) return;
	flag = ((t & (1LL << bit)) > 0);
	if (!col[v][flag]) col[v][flag] = ++ ptr;
	++ cnt[col[v][flag]];
	add(col[v][flag], bit - 1);
}

int main(){
    InTheNameOfGod;
    
    cin >> n >> k;
    -- k;
    for (int i = 1; i <= n; ++ i) cin >> num[i], part[i];
    add(1, 32);
    for (int i = 1; i <= n; ++ i){
    	t = part[i] = part[i - 1] ^ num[i];
    	get(1, 32), add(1, 32);
	}
	cout << ans << endl;
	
    return 0;
}