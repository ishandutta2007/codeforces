// khodaya khodet komak kon
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
typedef pair <ll, ll>                                    pll;
typedef pair <pll,  ll>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 3e4 + 10;
const int xm = - 20;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 257;
 
ll n, q, match[xn], seg[xn << 2][3][3];
ll p[4][6][3], fact[4];
pll P[xn], a[xn], b[xn];

ll solve(int l, int r){
	if (r - l > 3)
		return - INF;
	if (r == l)
		return 0;
	ll ans = - INF;
	for (int i = 0; i < fact[r - l]; ++ i){
		bool flag = true;
		ll res = 0;
		for (int j = l; j < r; ++ j){
			flag &= (match[j] != l + p[r - l][i][j - l]);
			res += a[j].A * b[l + p[r - l][i][j - l]].A;
		}
		if (flag)
			ans = max(ans, res);
	}
	return ans;
}
void merge(int id, int l, int r){
	int mid = l + r >> 1;
	for (int i = 0; i < 3; ++ i){
		for (int j = 0; j < 3; ++ j){
			seg[id][i][j] = - INF;
			if (i + j > r - l)
				continue;
			if (r - l - i - j < 4){
				seg[id][i][j] = solve(l + i, r - j);
				continue;
			}
			for (int ii = 0; ii < 3; ++ ii)
				for (int jj = 0; jj < 3; ++ jj)
					seg[id][i][j] = max(seg[id][i][j], seg[lc][i][ii] + seg[rc][jj][j] + solve(mid - ii, mid + jj));
		}
	}
}
void build(int id, int l, int r){
	if (r - l == 1){
		for (int i = 0; i < 3; ++ i)
			for (int j = 0; j < 3; ++ j)
				seg[id][i][j] = - INF;
		seg[id][1][0] = seg[id][0][1] = 0;
		seg[id][0][0] = solve(l, r);
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid);
	build(rc, mid, r);
	merge(id, l, r);
}
void modify(int id, int l, int r, int pos){
	if (r - l == 1){
		seg[id][0][0] = solve(l, r);
		return;
	}
	int mid = l + r >> 1;
	if (pos < mid)
		modify(lc, l, mid, pos);
	else
		modify(rc, mid, r, pos);
	merge(id, l, r);
}

int main(){
	InTheNameOfGod;
	
	fact[1] = 1, fact[2] = 2, fact[3] = 6;
	p[1][0][0] = 0;
	p[2][0][0] = 0, p[2][0][1] = 1;
	p[2][1][0] = 1, p[2][1][1] = 0;
	p[3][0][0] = 0, p[3][0][1] = 1, p[3][0][2] = 2;
	p[3][1][0] = 0, p[3][1][1] = 2, p[3][1][2] = 1;
	p[3][2][0] = 1, p[3][2][1] = 0, p[3][2][2] = 2;
	p[3][3][0] = 1, p[3][3][1] = 2, p[3][3][2] = 0;
	p[3][4][0] = 2, p[3][4][1] = 0, p[3][4][2] = 1;
	p[3][5][0] = 2, p[3][5][1] = 1, p[3][5][2] = 0;
	cin >> n >> q;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i].A, a[i].B = i;
	for (int i = 1; i <= n; ++ i)
		cin >> b[i].A, b[i].B = i;
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; ++ i)
		P[a[i].B].A = P[b[i].B].B = i;
	for (int i = 1; i <= n; ++ i)
		match[P[i].A] = P[i].B;
	build(1, 1, n + 1);
	while (q --){
		int x, y;
		cin >> x >> y;
		swap(match[P[x].A], match[P[y].A]);
		modify(1, 1, n + 1, P[x].A);
		modify(1, 1, n + 1, P[y].A);
		cout << seg[1][0][0] << endl;
	}
			
	return 0;
}