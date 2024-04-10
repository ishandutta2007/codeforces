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
 
const int xn = 2e5 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int MOD = 1e9 + 7;
const int TM = 3;
const int BASE = 257;

int n, m, q, seg[2][xn << 2];
set <int> st[2][xn];
bool ans;

void build(int id, int l, int r, bool flag){
	if (r - l == 1){
		seg[flag][id] = inf;
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid, flag);
	build(id << 1 | 1, mid, r, flag);
	seg[flag][id] = inf;
}
void modify(int id, int l, int r, int pos, int val, bool flag){
	if (r - l == 1){
		seg[flag][id] = min(seg[flag][id], val);
		return;
	}
	int mid = l + r >> 1;
	if (pos < mid) modify(id << 1, l, mid, pos, val, flag);
	else modify(id << 1 | 1, mid, r, pos, val, flag);
	seg[flag][id] = min(seg[flag][id << 1], seg[flag][id << 1 | 1]);
}
int get(int id, int l, int r, int ql, int qr, bool flag){
	if (qr <= l || r <= ql) return inf;
	if (ql <= l && r <= qr) return seg[flag][id];
	int mid = l + r >> 1;
	return min(get(id << 1, l, mid, ql, qr, flag), get(id << 1 | 1, mid, r, ql, qr, flag));
}
 
int main(){
    InTheNameOfGod;
    
    cin >> n >> m >> q;
    for (int i = 0; i < 2; ++ i) build(1, 0, xn, i);
    while (q --){
    	int x, y;
    	cin >> x >> y;
    	bool flag = x % 2;
    	int X = x;
    	int Y = y;
    	x = (x + 1) / 2;
    	y = (y + 1) / 2;
    	if (flag){
    		int a = - get(1, 0, xn, x, n + 1, !flag);
    		modify(1, 0, xn, x, y, flag);
    		ans |= (a >= y);
		}
		else{
			int a = get(1, 0, xn, 1, x + 1, !flag);
			modify(1, 0, xn, x, - y, flag);
			ans |= (a <= y);
		}
		if (ans) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	
    return 0;
}