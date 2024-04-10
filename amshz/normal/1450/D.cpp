//khodaya khodet komak kon
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
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 3e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int qq, n, a[xn], cnt[xn], last, l, r, seg[xn << 2];
bool ans[xn];

void build(int id, int l, int r){
	if (r - l == 1){
		seg[id] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
	seg[id] = min(seg[lc], seg[rc]);
}
int get(int id, int l, int r, int ql, int qr){
	if (qr <= l || r <= ql)
		return inf;
	if (ql <= l && r <= qr)
		return seg[id];
	int mid = l + r >> 1;
	return min(get(lc, l, mid, ql, qr), get(rc, mid, r, ql, qr));
}

int main(){
	InTheNameOfGod;
	
	cin >> qq;
	while (qq --){
		cin >> n;
		for (int i = 1; i <= n; ++ i)
			cin >> a[i], ++ cnt[a[i]], ans[i] = false;
		build(1, 1, n + 1);
		l = 0, r = n + 1, last = 0;
		while (l < r - 1){
			ans[r - l - 1] = (get(1, 1, n + 1, l + 1, r) == last + 1);
			if (a[l + 1] == last + 1){
				++ last, ++ l;
				-- cnt[a[l]];
			}
			else if (a[r - 1] == last + 1){
				++ last, -- r;
				-- cnt[a[r]];
			}
			else
				break;
		}
		for (int i = l + 1; i < r; ++ i)
			-- cnt[a[i]];
		ans[1] = true;
		for (int i = 1; i <= n; ++ i)
			++ cnt[a[i]];
		for (int i = 1; i <= n; ++ i)
			ans[1] &= (cnt[i] == 1);
		for (int i = 1; i <= n; ++ i)
			-- cnt[a[i]];
		for (int i = 1; i <= n; ++ i)
			cout << ans[i];
		cout << endl;
	}
			
	return 0;
}