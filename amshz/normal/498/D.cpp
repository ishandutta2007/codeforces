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

struct node{
	int f[60];
	bool istohi = false;
}; 

const int xn = 1e5 + 10;
const int xm = - 20;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, a[xn], q;
node seg[xn << 2], tohi;

node merge(node v, node u){
	if (v.istohi)
		return u;
	if (u.istohi)
		return v;
	node w;
	for (int i = 0; i < 60; ++ i)
		w.f[i] = v.f[i] + u.f[(i + v.f[i]) % 60];
	return w;
}
void build(int id, int l, int r){
	if (r - l == 1){
		for (int i = 0; i < 60; ++ i)
			seg[id].f[i] = 1 + (i % a[l] == 0);
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
	seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
}
void modify(int id, int l, int r, int pos, int val){
	if (r - l == 1){
		a[l] = val;
		for (int i = 0; i < 60; ++ i)
			seg[id].f[i] = 1 + (i % a[l] == 0);
		return;
	}
	int mid = l + r >> 1;
	if (pos < mid)
		modify(id << 1, l, mid, pos, val);
	else
		modify(id << 1 | 1, mid, r, pos, val);
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
	
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	tohi.istohi = true;
	build(1, 1, n + 1);	
	cin >> q;
	while (q --){
		char c;
		int x, y;
		cin >> c >> x >> y;
		if (c == 'A')
			cout << get(1, 1, n + 1, x, y).f[0] << endl;
		else
			modify(1, 1, n + 1, x, y);
	}
	
	return 0;
}