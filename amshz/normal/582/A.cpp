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
const int xn = 25e4 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = SQ + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";

int n, num[xn], ptr = 1;
vector <int> vec;
bool Mark[xn];
unordered_map <int, int> cnt;

bool cmp(int i, int j){
	return i > j;
}

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 0; i < n * n; ++ i) cin >> num[i], ++ cnt[num[i]];
	sort(num, num + n * n, cmp);
	vec.push_back(num[0]);
	-- cnt[num[0]];
	while (ptr < n * n){
		while (cnt[num[ptr]] == 0 && ptr < n * n) ++ ptr;
		if (ptr == n * n) break;
		for (int x : vec){
			int g = __gcd(num[ptr], x);
			cnt[g] -= 2;
		}
		vec.push_back(num[ptr]);
		-- cnt[num[ptr]];
		++ ptr;
	}
	for (int x : vec) cout << x << sep;
	cout << endl;
	
	return 0;
}