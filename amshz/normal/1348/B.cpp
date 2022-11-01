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
typedef pair <ll , ll >                                  pll;
 
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
const int xn = 1e2 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = SQ + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";

int qq, n, k, num[xn];
set <int> st;
vector <int> vec;

int main(){
	InTheNameOfGod;
	
	cin >> qq;
	while (qq --){
		cin >> n >> k;
		for (int i = 0; i < n; ++ i) cin >> num[i];
		st.clear(), vec.clear();
		for (int i = 0; i < n; ++ i) st.insert(num[i]);
		if (SZ(st) > k){
			cout << -1 << endl;
			continue;
		}
		for (int x : st) vec.push_back(x);
		while (SZ(vec) < k) vec.push_back(num[0]);
		cout << n * k << endl;
		for (int i = 0; i < n; ++ i)
			for (int x : vec) cout << x << sep;
		cout << endl;
	}
	
	
	return 0;
}