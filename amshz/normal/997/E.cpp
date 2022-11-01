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
 
const int xn = 1.2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, q, a[xn], sk1[xn], sk2[xn], pt1 = 1, pt2 = 1;
ll ans[xn], sum[xn << 2];
pll lazy[xn << 2], seg[xn << 2];
vector <pii> query[xn];

void build(int id, int l, int r){
	seg[id] = {1, r - l};
	if (r - l == 1)
		return;
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
}
void shift(int id, int l, int r){
	seg[id].A += lazy[id].A;
	sum[id] += seg[id].B * lazy[id].B;
	if (r - l > 1){
		lazy[lc].A += lazy[id].A;
		lazy[rc].A += lazy[id].A;
		if (seg[id].A == seg[lc].A + lazy[lc].A)
			lazy[lc].B += lazy[id].B;
		if (seg[id].A == seg[rc].A + lazy[rc].A)
			lazy[rc].B += lazy[id].B;
	}
	lazy[id] = {0, 0};
}
void update(int ql, int qr, ll val, int id = 1, int l = 1, int r = n + 1){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql)
		return;
	if (ql <= l && r <= qr){
		lazy[id].A += val;
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(ql, qr, val, lc, l, mid);
	update(ql, qr, val, rc, mid, r);
	sum[id] = sum[lc] + sum[rc];
	seg[id] = {min(seg[lc].A, seg[rc].A), 0};
	if (seg[lc].A == seg[id].A)
		seg[id].B += seg[lc].B;
	if (seg[rc].A == seg[id].A)
		seg[id].B += seg[rc].B;
}
ll get(int id, int l, int r, int ql, int qr){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql)
		return 0;
	if (ql <= l && r <= qr)
		return sum[id];
	int mid = l + r >> 1;
	return get(lc, l, mid, ql, qr) + get(rc, mid, r, ql, qr);
}

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	cin >> q;
	for (int i = 0; i < q; ++ i){
		int l, r;
		cin >> l >> r;
		query[r].push_back({l, i});
	}
	build(1, 1, n + 1);
	for (int i = 1; i <= n; ++ i){
		update(1, i + 1, - 1);
		while (pt1 > 1 && a[sk1[pt1 - 1]] < a[i])
			update(sk1[pt1 - 2] + 1, sk1[pt1 - 1] + 1, a[i] - a[sk1[pt1 - 1]]), -- pt1;
		while (pt2 > 1 && a[sk2[pt2 - 1]] > a[i])
			update(sk2[pt2 - 2] + 1, sk2[pt2 - 1] + 1, a[sk2[pt2 - 1]] - a[i]), -- pt2;
		sk2[pt2 ++] = sk1[pt1 ++] = i, ++ lazy[1].B;
		for (pii x : query[i])
			ans[x.B] = get(1, 1, n + 1, x.A, i + 1);
	}
	for (int i = 0; i < q; ++ i)
		cout << ans[i] << endl;
	
	return 0;
}