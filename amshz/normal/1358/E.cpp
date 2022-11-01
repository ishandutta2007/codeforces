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
typedef pair <ld, ld>                                  pll;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;//998244353;
const int xn = 5e5 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
string abc = "abcdefghijklmnopqrstuvwxyz";

ll n, num[xn], part[xn], x, pmn[xn], NSF;

int main(){
    InTheNameOfGod;
    
    cin >> n;
    NSF = (n + 1) / 2;
    for (int i = 1; i <= NSF; ++ i)	cin >> num[i];
    cin >> x;
    for (int i = NSF + 1; i <= n; ++ i)	num[i] = x;
    for (int i = 1; i <= n; ++ i)	part[i] = part[i - 1] + num[i];
    for (int i = NSF; i <= n; ++ i)	part[i] -= part[i - NSF];
    pmn[NSF - 1] = INF;
    for (int i = NSF; i <= n; ++ i)	pmn[i] = min(pmn[i - 1], part[i]);
    for (ll i = NSF; i <= n; ++ i) if (pmn[n - i + NSF] + x * (i - NSF) > 0)	kill(i);
    kill(-1);
    
    return 0;
}