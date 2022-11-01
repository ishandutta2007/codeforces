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
 
const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, qq, m, seg[xn << 2], lazy[xn << 2];
pii a[xn];
string s, t;
bool flag;

void build(int id, int l, int r){
	lazy[id] = 0;
	if (r - l == 1){
		seg[id] = t[l] - '0';
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
	seg[id] = seg[lc] + seg[rc];
}
void shift(int id, int l, int r){
	if (!lazy[id])
		return;
	if (lazy[id] == 1)
		seg[id] = r - l;
	else
		seg[id] = 0;
	if (r - l > 1)
		lazy[lc] = lazy[rc] = lazy[id];
	lazy[id] = 0;
}
void update(int id, int l, int r, int ql, int qr, int val){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql)
		return;
	if (ql <= l && r <= qr){
		lazy[id] = val;
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(lc, l, mid, ql, qr, val);
	update(rc, mid, r, ql, qr, val);
	seg[id] = seg[lc] + seg[rc];
}
int get(int id, int l, int r, int ql, int qr){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql)
		return 0;
	if (ql <= l && r <= qr)
		return seg[id];
	int mid = l + r >> 1;
	return get(lc, l, mid, ql, qr) + get(rc, mid, r, ql, qr);
}
void check(int id, int l, int r){
	shift(id, l, r);
	if (r - l == 1){
		if (seg[id])
			flag &= (s[l] == '1');
		else
			flag &= (s[l] == '0');
		return;
	}
	int mid = l + r >> 1;
	check(lc, l, mid), check(rc, mid, r);
}

int main(){
	InTheNameOfGod;
	
	cin >> qq;
	while (qq --){
		cin >> n >> m >> s >> t;
		for (int i = 0; i < m; ++ i)
			cin >> a[i].A >> a[i].B;
		build(1, 0, n), flag = true;
		for (int i = m - 1; i >= 0; -- i){
			int l = a[i].A - 1, r = a[i].B;
			int cnt = get(1, 0, n, l, r);
			if (cnt + cnt == r - l)
				flag = false;
			if (cnt + cnt < r - l)
				update(1, 0, n, l, r, 2);
			else
				update(1, 0, n, l, r, 1);
		}
		check(1, 0, n);
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
			
	return 0;
}