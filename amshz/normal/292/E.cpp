# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e5 + 10;
const int xm = 10 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, q, a[xn], b[xn], seg[xn << 2], lazy[xn << 2];

void build(int id, int l, int r){
	if (r - l == 1){
		seg[id] = b[l];
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
	seg[id] = seg[id << 1];
}
void shift(int id, int l, int r){
	if (!lazy[id])
		return;
	seg[id] = a[lazy[id]];
	if (r - l > 1){
		int mid = l + r >> 1;
		lazy[id << 1] = lazy[id];
		lazy[id << 1 | 1] = lazy[id] + mid - l;
	}
	lazy[id] = 0;
}
void update(int id, int l, int r, int ql, int qr, int ind){
	shift(id, l, r);
	if (qr <= l || r <= ql)
		return;
	if (ql <= l && r <= qr){
		lazy[id] = ind + l - ql;
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(id << 1, l, mid, ql, qr, ind);
	update(id << 1 | 1, mid, r, ql, qr, ind);
	seg[id] = seg[id << 1];
}
int get(int id, int l, int r, int pos){
	shift(id, l, r);
	if (r - l == 1)
		return seg[id];
	int mid = l + r >> 1;
	if (pos < mid)
		return get(id << 1, l, mid, pos);
	return get(id << 1 | 1, mid, r, pos);
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> q;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	for (int i = 1; i <= n; ++ i)
		cin >> b[i];
	build(1, 1, n + 1);
	while (q --){
		int t, x, y, k;
		cin >> t;
		if (t == 1){
			cin >> x >> y >> k;
			update(1, 1, n + 1, y, y + k, x);
		}
		else{
			cin >> x;
			cout << get(1, 1, n + 1, x) << endl;
		}
	}
	
	return 0;
}