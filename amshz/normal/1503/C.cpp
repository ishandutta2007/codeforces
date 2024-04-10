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
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

ll n, seg[2][xn << 2], dp[xn], ps[xn], ans = INF;
pll a[xn];

void build(int id, int l, int r){
	seg[0][id] = seg[1][id] = INF;
	if (r - l == 1)
		return;
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
}
void update(int id, int l, int r, int ql, int qr, int t, ll val){
	if (qr <= l || r <= ql || qr <= ql)
		return;
	if (ql <= l && r <= qr){
		seg[t][id] = min(seg[t][id], val);
		return;
	}
	int mid = l + r >> 1;
	update(lc, l, mid, ql, qr, t, val);
	update(rc, mid, r, ql, qr, t, val);
}
ll get(int id, int l, int r, int pos, int t){
	if (r - l == 1)
		return seg[t][id];
	int mid = l + r >> 1;
	if (pos < mid)
		return min(seg[t][id], get(lc, l, mid, pos, t));
	return min(seg[t][id], get(rc, mid, r, pos, t));
}

int main(){
	InTheNameOfGod;

	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i].A >> a[i].B;
	sort(a + 1, a + n + 1);
	for (int i = n; i >= 1; -- i)
		ps[i] = ps[i + 1] + a[i].B;
	build(1, 1, n + 1);
	for (int i = 1; i <= n; ++ i){
		if (i == 1)
			dp[1] = ps[2];
		else{
			dp[i] = get(1, 1, n + 1, i, 1) + a[i].A - a[i].B;
			dp[i] = min(dp[i], get(1, 1, n + 1, i, 0) - a[i].B);
		}
		ans = min(ans, dp[i] + max(a[i].B, a[n].A - a[i].A));
		int l = i, r = n + 1;
		while (r - l > 1){
			int mid = l + r >> 1;
			if (a[mid].A - a[i].A < a[i].B)
				l = mid;
			else
				r = mid;
		}
		update(1, 1, n + 1, r, n + 1, 1, dp[i] - a[i].A);
		update(1, 1, n + 1, i + 1, r, 0, dp[i] + a[i].B);
	}
	cout << ans << endl;
			
	return 0;
}