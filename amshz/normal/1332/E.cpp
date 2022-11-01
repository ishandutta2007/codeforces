# include <bits/stdc++.h>
 
using namespace std;

/*
// ordered_set 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/
 
typedef long long          ll;
typedef long double        ld;
typedef pair <int, int>    pii;
typedef pair <pii, int>    ppi;
typedef pair <pii, pii>    pip;
 
# define A                                first
# define B                                second
# define endl                             '\n'
# define sep                              ' '
# define all(x)                           x.begin(), x.end()
# define Kill(x)                          return cout << x << endl, 0
# define SZ(x)                            int(x.size())
# define InTheNameOfGod                   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 998244353;
const int xn = -20 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;

ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 100 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 100 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";

ll n, m, L, R, A, B;

int main(){
	InTheNameOfGod;
	
	cin >> n >> m >> L >> R;
	A = n * m, B = (R - L + 1) / 2, B %= md;
	if (n % 2 && m % 2)		Kill(power(R - L + 1, A));
	if ((L % 2) != (R % 2)) 	Kill(zarb(power(B, A), power(2, A - 1)));
	cout << zarb(power(2, md - 2), jaam(power(jaam(zarb(2, B), 1), A), 1)) << endl;
	
	return 0;
}