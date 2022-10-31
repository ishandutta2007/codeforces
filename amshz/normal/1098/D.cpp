//khodaya khodet komak kon
# include <bits/stdc++.h>
# pragma GCC optimize("O2")
//# pragma GCC optimize("Ofast")
# pragma GCC optimize("unroll-loops")
 
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
 
const int xn = 5e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244853;
const int base = 257;
 
int n, q, a[xn], ptr, tb[xn], pt[xn], ans[xn << 2], res;
ll seg[xn << 2], lazy[xn << 2];
char c[xn];
vector <int> compress, vec[xn];
unordered_map <int, int> mp;

void shift(int id, int l, int r){
	if (!lazy[id])
		return;
	seg[id] += lazy[id];
	if (r - l > 1){
		lazy[lc] += lazy[id];
		lazy[rc] += lazy[id];
	}
	lazy[id] = 0;
}
void update(int id, int l, int r, int ql, int qr, int val){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql)
		return;
	if (ql <= l && r <= qr && seg[id] + val <= 0 && seg[id] <= 0){
		lazy[id] += val;
		shift(id, l, r);
		return;
	}
	if (r - l == 1){
		seg[id] += val;
		ans[id] = seg[id] > 0;
		return;
	}
	int mid = l + r >> 1;
	update(lc, l, mid, ql, qr, val);
	update(rc, mid, r, ql, qr, val);
	seg[id] = max(seg[lc], seg[rc]);
	ans[id] = ans[lc] + ans[rc];
}

int main(){
	InTheNameOfGod;
 
	cin >> q;
	for (int i = 0; i < q; ++ i){
		cin >> c[i] >> a[i];
		compress.push_back(a[i]);
	}
	sort(all(compress));
	for (int i = 0; i < SZ(compress); ++ i)
		if (!i || compress[i] != compress[i - 1])
			tb[ptr] = compress[i], mp[compress[i]] = ptr ++;
	for (int i = 0; i < q; ++ i){
		int x = mp[a[i]];
		if (c[i] == '+'){
			if (pt[x] == SZ(vec[x]))
				vec[x].push_back(0);
			++ pt[x];
		}
		else
			-- pt[x];
	}
	for (int i = 0; i < ptr; ++ i)
		for (int j = 0; j < SZ(vec[i]); ++ j)
			vec[i][j] = n ++;
	memset(pt, 0, sizeof pt);
	for (int i = 0; i < q; ++ i){
		int x = mp[a[i]];
		if (c[i] == '+'){
			int ind = vec[x][pt[x] ++];
			update(1, 0, n, ind, ind + 1, a[i]);
			update(1, 0, n, ind + 1, n, - a[i] * 2);
			++ res;
		}
		else{
			int ind = vec[x][-- pt[x]];
			update(1, 0, n, ind, ind + 1, - a[i]);
			update(1, 0, n, ind + 1, n, a[i] * 2);
			-- res;
		}
		cout << res - ans[1] << endl;
	}
 
	return 0;
}