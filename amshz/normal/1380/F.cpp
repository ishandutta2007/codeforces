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
typedef pair <ll, ll>                                    pll;
typedef pair <pll, pll>                                  ppp;
 
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
 
const int xn = 5e5 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int MOD = 998244353;
const int TM = 3;
const int BASE = 257;

ll n, m, num[xn];
string s;
ppp seg[xn << 2], tohi = {{0, 0}, {0, 0}};

ppp merge(ppp x, ppp y, int mid, int l, int r){
	ppp z = tohi;
	bool fl1 = (mid - l == 1), fl2 = (r - mid == 1);
	z.A.A = (z.A.A + x.A.A * y.A.A) % MOD;
	if (num[mid - 1] == 1) z.A.A = (z.A.A + x.A.B * y.B.A % MOD * (9LL - num[mid])) % MOD;
	z.A.B = (z.A.B + x.A.A * y.A.B) % MOD;
	if (num[mid - 1] == 1 && !fl2) z.A.B = (z.A.B + x.A.B * y.B.B % MOD * (9LL - num[mid])) % MOD;
	z.B.A = (z.B.A + x.B.A * y.A.A) % MOD;
	if (num[mid - 1] == 1 && !fl1) z.B.A = (z.B.A + x.B.B * y.B.A % MOD * (9LL - num[mid])) % MOD;
	z.B.B = (z.B.B + x.B.A * y.A.B) % MOD;
	if (num[mid - 1] == 1 && !fl1 && !fl2) z.B.B = (z.B.B + x.B.B * y.B.B % MOD * (9LL - num[mid])) % MOD;
	return z;
}
void build(int id, int l, int r){
	if (r - l == 1){
		seg[id].A.A = num[l] + 1;
		seg[id].B.A = seg[id].A.B = seg[id].B.B = 1;
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
	seg[id] = merge(seg[id << 1], seg[id << 1 | 1], mid, l, r);
}
void modify(int id, int l, int r, int pos){
	if (r - l == 1){
		seg[id].A.A = num[l] + 1;
		return;
	}
	int mid = l + r >> 1;
	if (pos < mid) modify(id << 1, l, mid, pos);
	else modify(id << 1 | 1, mid, r, pos);
	seg[id] = merge(seg[id << 1], seg[id << 1 | 1], mid, l, r);
}

int main(){
    InTheNameOfGod;
    
    cin >> n >> m >> s;
    for (int i = 0; i < n; ++ i) num[i] = s[i] - '0';
    build(1, 0, n);
    while (m --){
    	int x, y;
    	cin >> x >> y;
    	num[x - 1] = y;
    	modify(1, 0, n, x - 1);
    	cout << seg[1].A.A << endl;
	}
	
    return 0;
}