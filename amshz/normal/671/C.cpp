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
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, a[xn], last[2][xn], cnt[xn], lst;
int mn[xn << 2], mx[xn << 2], lazy[xn << 2];
ll seg[xn << 2], ans;
vector <int> magh[xn];

void build(int id, int l, int r){
	if (r - l == 1){
		mx[id] = lst;
		for (int x : magh[a[l]]){
			if (cnt[x])
				mx[id] = max(mx[id], x);
			++ cnt[x];
		}
		lst = mn[id] = seg[id] = mx[id];
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
	mn[id] = min(mn[lc], mn[rc]);
	mx[id] = max(mx[lc], mx[rc]);
	seg[id] = seg[lc] + seg[rc];
}
void shift(int id, int l, int r){
	if (!lazy[id])
		return;
	mn[id] = mx[id] = lazy[id];
	seg[id] = 1LL * (r - l) * lazy[id];
	if (r - l > 1)
		lazy[lc] = lazy[rc] = lazy[id];
	lazy[id] = 0;
}
void update(int id, int l, int r, int ql, int qr, int val){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql || mn[id] >= val)
		return;
	if (ql <= l && r <= qr && mx[id] <= val){
		lazy[id] = val;
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(lc, l, mid, ql, qr, val);
	update(rc, mid, r, ql, qr, val);
	mn[id] = min(mn[lc], mn[rc]);
	mx[id] = max(mx[lc], mx[rc]);
	seg[id] = seg[lc] + seg[rc];
}
ll get(int id, int l, int r, int ql, int qr){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql)
		return 0;
	if (ql <= l && r <= qr)
		return seg[id];
	int mid = l + r >> 1;
	return get(lc, l, mid, ql, qr) + get(rc, mid, r, ql, qr);
}

int main(){
	InTheNameOfGod;
	
	for (int i = 1; i < xn; ++ i){
		for (int j = i; j < xn; j += i)
			magh[j].push_back(i);
		last[0][i] = inf;
	}
	cin >> n;
	for (int i = 1; i <= n; ++ i){
		cin >> a[i];
		for (int x : magh[a[i]]){
			last[0][x] = min(last[0][x], i);
			last[1][x] = max(last[1][x], i);
		}
	}
	build(1, 0, n);
	for (int i = n; i >= 1; -- i){
		ans += get(1, 0, n, 0, i);
		for (int x : magh[a[i]]){
			if (last[1][x] > i)
				update(1, 0, n, 0, n, x);
			else
				update(1, 0, n, last[0][x], n, x);
		}
	}
	cout << ans << endl;

	return 0;
}