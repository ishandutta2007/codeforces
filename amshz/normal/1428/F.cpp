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
 
const int xn = 5e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

ll n, parti[xn], ans, x, y, ptr, part[xn], res;
string s;
pll dp[2][xn];

void build(int l, int r){
	if (r - l == 1){
		ans += s[l] - '0';
		return;
	}
	int mid = l + r >> 1;
	dp[1][mid - 1].A = dp[1][mid - 1].B = 0;
	x = y = 0;
	for (int i = mid; i < r; ++ i){
		if (s[i] == '1')
			dp[1][i].A = dp[1][i - 1].A + 1;
		else
			dp[1][i].A = 0;
		dp[1][i].B = max(dp[1][i - 1].B, dp[1][i].A);
		if (dp[1][i].A == i - mid + 1)
			++ y;
	}
	dp[0][mid].A = dp[0][mid].B = 0;
	for (int i = mid - 1; i >= l; -- i){
		if (s[i] == '1')
			dp[0][i].A = dp[0][i + 1].A + 1;
		else
			dp[0][i].A = 0;
		dp[0][i].B = max(dp[0][i + 1].B, dp[0][i].A);
		if (dp[0][i].A == mid - i)
			++ x;
	}
	for (int i = 1; i <= x; ++ i)
		ans += parti[i + y] - parti[i];
	part[r] = 0;
	for (int i = r - 1; i >= mid; -- i)
		part[i] = part[i + 1] + dp[1][i].B;
	ptr = mid + y;
	for (int i = mid - 1; i >= l; -- i){
		res = max(dp[0][i].B, x + y);
		if (mid - i < x) res = max(dp[0][i].B, mid - i + y);
		while (ptr < r && dp[1][ptr].B <= res) ++ ptr;
		ans += (ptr - mid - y) * res + part[ptr];
	}
	part[l - 1] = 0;
	for (int i = l; i < mid; ++ i)
		part[i] = part[i - 1] + dp[0][i].B;
	ptr = mid - 1 - x;
	for (int i = mid; i < r; ++ i){
		if (dp[1][i].A != i - mid + 1) break;
		res = max(dp[1][i].B, x + i - mid + 1LL);
		while (ptr >= l && dp[0][ptr].B <= res) -- ptr;
		ans += (mid - ptr - 1 - x) * res + part[ptr];
	}
	build(l, mid);
	build(mid, r);
}

int main(){
    InTheNameOfGod;
    
	cin >> n >> s;
	s = '.' + s;
	for (ll i = 1; i < xn; ++ i)
		parti[i] = parti[i - 1] + i;
	build(1, n + 1);
	cout << ans << endl;

    return 0;
}