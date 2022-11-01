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
const int xn = 5e6 + 10;
const int xm = 1e5 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int MOD[4] = {1000000009, 1000000007, 987654319, 999999937};
const int TM = 3;
const int BASE = 257;

ll n, num[xm], part[2][xm], ans, flag, s, t, col[xn][2], ptr = 1, cnt[xn];

void upd(ll v, ll bit, ll val){
	if (bit == -1) return;
	flag = ((t & (1LL << bit)) > 0);
	cnt[col[v][flag]] += val;
	upd(col[v][flag], bit - 1, val);
}
void get(ll v, ll bit, ll res){
	if (bit == -1){
		ans = max(ans, res);
		return;
	}
	flag = (t & (1LL << bit));
	if (cnt[col[v][1 - (flag > 0)]] > 0) get(col[v][1 - (flag > 0)], bit - 1, res + (1LL << bit));
	else get(col[v][(flag > 0)], bit - 1, res);
}
void add(ll v, ll bit){
	if (bit == -1) return;
	flag = 0;
	if ((t & (1LL << bit)) > 0) flag = 1;
	if (!col[v][flag]) col[v][flag] = ++ ptr;
	add(col[v][flag], bit - 1);
}

int main(){
    InTheNameOfGod;
    
    cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> num[i], part[0][i] = part[0][i - 1] ^ num[i];
    for (int i = n; i >= 1; -- i) part[1][i] = part[1][i + 1] ^ num[i];
    for (int i = 1; i <= n + 1; ++ i) t = part[1][i], add(1, 40);
    for (int i = 1; i <= n + 1; ++ i) t = part[1][i], upd(1, 40, 1);
	for (int i = 0; i <= n; ++ i){
		t = part[0][i];
		get(1, 40, 0);
		t = part[1][i + 1];
		upd(1, 40, -1);
	}
	cout << ans << endl;
	
    return 0;
}