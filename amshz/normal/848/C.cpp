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
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int SQ = 320;
const int sq = 500 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e14 + 10;
const int MOD = 1e9 + 7;
const int TM = 1e7;
const int BASE = 257;

int n, m, num[xn], f[xn], L[xn], ptr;
ll a[xn], b[xn], ans, dp[xn];
pii last[xn];
pll lazy[sq][sq];
set <int> st[2][xn];

void upd1(int x, int y, int val){ for (int i = y / SQ + 1; i <= x / SQ; ++ i) lazy[x / SQ][i].A += val;}
void upd2(int x, int y, int val){ for (int i = x / SQ; i < y / SQ; ++ i) lazy[x / SQ][i].B += val;}
void update(int pos, int val){
	if (num[pos] == val) return;
	int x = last[pos].A;
	int y = last[pos].B;
	if (y != n + 1){
		upd1(y, pos, - y);
		upd1(y, x, y);
		last[y].A = x;
	}
	if (x){
		upd2(x, pos, - x);
		upd2(x, y, x);
		last[x].B = y;
	}
	upd1(pos, x, - pos);
	upd2(pos, y, - pos);
	x = *st[1][val].lower_bound(- pos);
	y = *st[0][val].lower_bound(pos);
	x = - x;
	if (x){
		upd2(x, y, - x);
		upd2(x, pos, x);
		last[x].B = pos;
	}
	if (y <= n){
		upd1(y, x, - y);
		upd1(y, pos, y);
		last[y].A = pos;
	}
	upd1(pos, x, pos);
	upd2(pos, y, pos);
	last[pos] = {x, y};
	st[0][num[pos]].erase(pos);
	st[1][num[pos]].erase(- pos);
	num[pos] = val;
	st[0][val].insert(pos);
	st[1][val].insert(- pos);
}

int get(int l, int r){
	ans = 0;
	if (l / SQ < r / SQ - 1){
		int id2 = r / SQ - 1;
		int id1 = l / SQ + 1;
		for (int i = id1; i <= id2; ++ i){
			ans -= lazy[i][id1].A;
			ans += lazy[i][id2].B;
		}
	}
	++ ptr;
	for (int i = l; i <= r;){
		if (i % SQ == 0 && i + SQ <= r && i != l) i += SQ;
		else{
			dp[i] = ptr;
			if (last[i].A >= l && dp[last[i].A] != ptr) ans -= last[i].A;
			if (last[i].B > r) ans += i;
			++ i;
		}
	}
	++ ptr;
	for (int i = r; i >= l;){
		if (i % SQ == SQ - 1 && i != r && i - SQ >= l) i -= SQ;
		else{
			dp[i] = ptr;
			if (last[i].B <= r && dp[last[i].B] != ptr) ans += last[i].B;
			if (last[i].A < l) ans -= i;
			-- i;
		}
	}
	cout << ans << endl;
}

int main(){
    InTheNameOfGod;
    
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) cin >> num[i];
    for (int i = 1; i <= n; ++ i){
    	last[i].A = L[num[i]];
    	L[num[i]] = i;
    	f[i] = n + 1;
	}
	for (int i = n; i >= 1; -- i){
		last[i].B = f[num[i]];
		f[num[i]] = i;
	}
	for (int i = 1; i <= n; ++ i){
		st[0][i].insert(0);
		st[0][i].insert(n + 1);
		st[1][i].insert(0);
		st[1][i].insert(- n - 1);
		st[0][num[i]].insert(i);
		st[1][num[i]].insert(- i);
		upd1(i, last[i].A, i);
		upd2(i, last[i].B, i);
	}
	while (m --){
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) update(x, y);
		else get(x, y);
	}
    
    return 0;
}