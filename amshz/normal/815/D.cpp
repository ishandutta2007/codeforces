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
 
const int xn = 5e5 + 10;
const int xm = 20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int TM = 3;
const int base = 257;

int n, a[xn], b[xn], c[xn], lazy[xn << 2], mn[xn << 2];
pii part[xn];
ll seg[xn << 2], ans, p, q, w;
vector <int> vec[xn];

void build(int id, int l, int r){
	seg[id] = ll(r - l) * w;
	if (r - l == 1) return;
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
}
void shift(int id, int l, int r){
	if (!lazy[id]) return;
	seg[id] = ll(r - l) * (w - lazy[id]);
	mn[id] = lazy[id];
	if (r - l > 1){
		lazy[id << 1] = lazy[id];
		lazy[id << 1 | 1] = lazy[id];
	}
	lazy[id] = 0;
}
int BS(int id, int l, int r, int val){
	shift(id, l, r);
	if (r - l == 1) return l;
	int mid = l + r >> 1;
	shift(id << 1, l, mid);
	shift(id << 1 | 1, mid, r);
	if (mn[id << 1] <= val) return BS(id << 1, l, mid, val);
	return BS(id << 1 | 1, mid, r, val);
}
void update(int id, int l, int r, int ql, int qr, int val){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql) return;
	if (ql <= l && r <= qr){
		lazy[id] = val;
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(id << 1, l, mid, ql, qr, val);
	update(id << 1 | 1, mid, r, ql, qr, val);
	mn[id] = min(mn[id << 1], mn[id << 1 | 1]);
	seg[id] = seg[id << 1] + seg[id << 1 | 1];
}
ll get(int id, int l, int r, int ql, int qr){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql) return 0;
	if (ql <= l && r <= qr) return seg[id];
	int mid = l + r >> 1;
	return get(id << 1, l, mid, ql, qr) + get(id << 1 | 1, mid, r, ql, qr);
}

int main(){
    InTheNameOfGod;
    
	cin >> n >> p >> q >> w;
	for (int i = 1; i <= n; ++ i){
		cin >> a[i] >> b[i] >> c[i];
		vec[a[i]].push_back(i);
	}
	for (int i = p; i >= 1; -- i){
		part[i] = part[i + 1];
		for (int x : vec[i]){
			part[i].A = max(part[i].A, b[x]);
			part[i].B = max(part[i].B, c[x]);
		}
	}
	build(1, 1, q + 1);
	for (int i = 1; i <= p; ++ i){
		int ind = q + 1;
		if (mn[1] <= part[i].B) ind = BS(1, 1, q + 1, part[i].B);
		ind = max(ind, part[i].A + 1);
		ans += get(1, 1, q + 1, part[i].A + 1, ind);
		ans += (w - part[i].B) * (q - ind + 1);
		for (int x : vec[i]){
			ind = b[x] + 1;
			if (mn[1] <= c[x]) ind = BS(1, 1, q + 1, c[x]);
			ind = min(ind, b[x] + 1);
			update(1, 1, q + 1, ind, b[x] + 1, c[x]);
		}
	}
	cout << ans << endl;
 
    return 0;
}