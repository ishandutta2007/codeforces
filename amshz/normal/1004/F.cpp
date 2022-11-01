# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, ll>                                  pii;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

struct node{
	bool istohi = false;
	ll ans = 0;
	vector <pii> vec[2];
};

int n, m, val, a[xn], ptr;
ll sum;
node seg[xn << 2], tohi;

node merge(node v, node u){
	node w;
	if (v.istohi) return u;
	if (u.istohi) return v;
	for (pii x : v.vec[0])
		w.vec[0].push_back(x);
	for (pii x : u.vec[0]){
		pii y = w.vec[0].back(), z = x; z.A |= y.A;
		if (z.A > y.A) w.vec[0].push_back(z);
		else w.vec[0].back().B += x.B;
	}
	for (pii x : u.vec[1])
		w.vec[1].push_back(x);
	for (pii x : v.vec[1]){
		pii y = w.vec[1].back(), z = x; z.A |= y.A;
		if (z.A > y.A) w.vec[1].push_back(z);
		else w.vec[1].back().B += x.B;
	}
	w.ans = v.ans + u.ans;
	ptr = SZ(u.vec[0]) - 1, sum = 0;
	for (int i = 0; i < SZ(v.vec[1]); ++ i){
		while (ptr >= 0 && (v.vec[1][i].A | u.vec[0][ptr].A) >= val)
			sum += u.vec[0][ptr].B, -- ptr;
		w.ans += v.vec[1][i].B * sum;
	}
	return w;
}
void build(int id, int l, int r){
	seg[id].istohi = false;
	if (r - l == 1){
		seg[id].vec[0].push_back({a[l], 1});
		seg[id].vec[1].push_back({a[l], 1});
		if (a[l] >= val)
			seg[id].ans = 1;
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
	seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
}
void modify(int id, int l, int r, int pos, int x){
	if (r - l == 1){
		a[pos] = x;
		seg[id].vec[0].back().A = x;
		seg[id].vec[1].back().A = x;
		if (a[l] >= val)
			seg[id].ans = 1;
		else
			seg[id].ans = 0;
		return;
	}
	int mid = l + r >> 1;
	if (pos < mid)
		modify(id << 1, l, mid, pos, x);
	else
		modify(id << 1 | 1, mid, r, pos, x);
	seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
}
node get(int id, int l, int r, int ql, int qr){
	if (qr <= l || r <= ql)
		return tohi;
	if (ql <= l && r <= qr)
		return seg[id];
	int mid = l + r >> 1;
	return merge(get(id << 1, l, mid, ql, qr), get(id << 1 | 1, mid, r, ql, qr));
}
 
int main(){
	InTheNameOfGod;
	
	cin >> n >> m >> val;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	tohi.istohi = true;
	build(1, 1, n + 1);
	while (m --){
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1)
			modify(1, 1, n + 1, x, y);
		else
			cout << get(1, 1, n + 1, x, y + 1).ans << endl;
	}
	
	return 0;
}