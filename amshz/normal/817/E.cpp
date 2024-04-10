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
 
const int xn = 3e6 + 10;
const int xm = 32;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int q, sz[xn], ptr = 1;
pii col[xn];

void add(int id, int x, int bit){
	++ sz[id];
	if (!bit) return;
	if (!col[id].A)
		col[id].A = ++ ptr;
	if (!col[id].B)
		col[id].B = ++ ptr;
	if ((x & (1 << (bit - 1))))
		add(col[id].B, x, bit - 1);
	else
		add(col[id].A, x, bit - 1);
}
void remove(int id, int x, int bit){
	-- sz[id];
	if (!bit) return;
	if ((x & (1 << (bit - 1))))
		remove(col[id].B, x, bit - 1);
	else
		remove(col[id].A, x, bit - 1);
}
int solve(int id, int bit, int res, int x, int y){
	if (!bit) return sz[id];
	if (!col[id].A)
		col[id].A = ++ ptr;
	if (!col[id].B)
		col[id].B = ++ ptr;
	if (res + (1 << (bit - 1)) >= y){
		if ((x & (1 << (bit - 1))))
			return solve(col[id].B, bit - 1, res, x, y);
		else
			return solve(col[id].A, bit - 1, res, x, y);
	}
	else{
		if ((x & (1 << (bit - 1))))
			return sz[col[id].B] + solve(col[id].A, bit - 1, res + (1 << (bit - 1)), x, y);
		else
			return sz[col[id].A] + solve(col[id].B, bit - 1, res + (1 << (bit - 1)), x, y);
	}
}
 
int main(){
	InTheNameOfGod;
	
	cin >> q;
	while (q --){
		int t, x, y;
		cin >> t >> x;
		if (t == 1) add(1, x, 30);
		else if (t == 2) remove(1, x, 30);
		else{
			cin >> y;
			cout << solve(1, 30, 0, x, y) << endl;
		}
	}
	
	return 0;
}