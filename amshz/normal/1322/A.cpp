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
typedef pair <ll, ll>                     pii;
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
 
const ll md = 1e9 + 7;//998244353;
const int xn = 1e6 + 10;
const int xm = -20 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";

int n, ted[2], flag[xn], S, ptr, ans, part[xn], last[xn];
string a;

int main(){
	InTheNameOfGod;
	
	cin >> n >> a;
	for (int i = 0; i < n; ++ i){
		if (a[i] == '(') ++ ted[0];
		else ++ ted[1];
	}
	if (ted[0] != ted[1]) Kill(-1);
	int x = n - 1;
	for (int i = 0; i < n; ++ i){
		if (a[i] == ')') -- S;
		else ++ S;
		part[i] = S;
	}
	for (int i = n - 1; i >= 0; -- i){
		if (part[i] == 0) x = i;
		last[i] = x;
	}
	for (int i = 0; i < n; ++ i){
		if (part[i] < 0){
			ans += last[i] - i + 1;
			i = last[i];
		}
	}
	cout << ans << endl;
	
	return 0;
}