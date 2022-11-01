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
 
const ll md = 998244353;
const int xn = 2e3 + 10;
const int xm = 2e5 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";

ll n, num[xn][xn], D[xn][xn], fact[xn], ans, pos[xn][xn], ted[xn];
pii seg[xn * 4], cnt[xn][xn];
bool flag[xn];

void update(int id, int L, int R, int index, ll val){
	if (R - L == 1){
		ted[index] += val;
		if (val == 2) ++ seg[id].A;
		if (ted[index] == 3) ++ seg[id].B;
		return;
	}
	int Mid = (L + R) / 2;
	if (index < Mid) update(id * 2, L, Mid, index, val);
	else update(id * 2 + 1, Mid, R, index, val);
	seg[id].A = seg[id * 2].A + seg[id * 2 + 1].A;
	seg[id].B = seg[id * 2].B + seg[id * 2 + 1].B;
}
pii get(int id, int L, int R, int ql, int qr){
	if (qr <= L || R <= ql) return {0, 0};
	if (ql <= L && R <= qr) return seg[id];
	int Mid = (L + R) / 2;
	pii a = get(id * 2, L, Mid, ql, qr);
	pii b = get(id * 2 + 1, Mid, R, ql, qr);
	return {a.A + b.A, a.B + b.B};
}

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j)	cin >> num[i][j], pos[i][num[i][j]] = j;
	fact[0] = 1;
	for (ll i = 1; i < xn; ++ i) 	fact[i] = zarb(fact[i - 1], i);
	D[1][0] = D[0][0] = 1;
	for (ll i = 2; i < xn; ++ i){
		for (ll j = 0; j <= i; ++ j){
			if (j == 0) D[i][j] = fact[i];
			else{
				D[i][j] = zarb(i - j, D[i - 1][j - 1]);
				if (j > 1) D[i][j] = jaam(D[i][j], zarb(j - 1, D[i - 1][j - 2]));
			}
		}
	}
	for (int i = 1; i <= n; ++ i){
		memset(seg, 0, sizeof seg);
		memset(ted, 0, sizeof ted);
		for (int j = n; j >= 1; -- j){
			cnt[i][j] = get(1, 0, xn, 0, num[i][j]);
			update(1, 0, xn, num[i][j], 2);
			update(1, 0, xn, num[i - 1][j], 1);
		}
	}
	ll s = 0;
	for (int j = 1; j <= n; ++ j){
		s = jaam(s, zarb(cnt[1][j].A, fact[n - j]));
	}
	ans = jaam(ans, zarb(power(D[n][n], n - 1), s));
	for (int i = 2; i <= n; ++ i){
		memset(flag, false, sizeof flag);
		s = 0;
		ll k = n;
		for (int j = 1; j <= n; ++ j){
			s = jaam(s, zarb(D[n - j][k - 1 - !flag[num[i - 1][j]]], cnt[i][j].B));
			if (num[i - 1][j] < num[i][j] && pos[i][num[i - 1][j]] > j) s = jaam(s, zarb(D[n - j][k - !flag[num[i - 1][j]]], cnt[i][j].A - cnt[i][j].B - 1));
			else s = jaam(s, zarb(D[n - j][k - !flag[num[i - 1][j]]], cnt[i][j].A - cnt[i][j].B));
			if (!flag[num[i - 1][j]]) -- k;
			flag[num[i - 1][j]] = true;
			if (!flag[num[i][j]]) -- k;
			flag[num[i][j]] = true;
		}
		ans = jaam(ans, zarb(s, power(D[n][n], n - i)));
	}
	cout << ans << endl;
	
	return 0;
}