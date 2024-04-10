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
 
const int xn = 2e5 + 10;
const int xm = 10 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, a[xn << 2], b[xn << 2], c[xn], seg[xn << 2], lazy[xn << 2];

void modify(int id, int l, int r, int pos){
	if (r - l == 1){
		++ seg[id];
		return;
	}
	int mid = l + r >> 1;
	if (pos < mid)
		modify(id << 1, l, mid, pos);
	else
		modify(id << 1 | 1, mid, r, pos);
	seg[id] = seg[id << 1] + seg[id << 1 | 1];
}
int get(int id, int l, int r, int ql, int qr){
	if (qr <= l || r <= ql)
		return 0;
	if (ql <= l && r <= qr)
		return seg[id];
	int mid = l + r >> 1;
	return get(id << 1, l, mid, ql, qr) + get(id << 1 | 1, mid, r, ql, qr);
}
void build(int id, int l, int r){
	if (r - l == 1){
		a[id] = b[id] = l;
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
	a[id] = a[id << 1];
	b[id] = b[id << 1 | 1];
}
void shift(int id, int l, int r){
	if (!lazy[id])
		return;
	a[id] += lazy[id];
	b[id] += lazy[id];
	if (r - l > 1){
		lazy[id << 1] += lazy[id];
		lazy[id << 1 | 1] += lazy[id];
	}
	lazy[id] = 0;
}
void update(int id, int l, int r, int ql, int qr){
	shift(id, l, r);
	if (qr <= l || r <= ql)
		return;
	if (ql <= l && r <= qr){
		-- lazy[id];
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(id << 1, l, mid, ql, qr);
	update(id << 1 | 1, mid, r, ql, qr);
	a[id] = a[id << 1];
	b[id] = b[id << 1 | 1];
}
int find(int id, int l, int r, int val){
	if (r - l == 1)
		return l;
	int mid = l + r >> 1;
	shift(id << 1, l, mid);
	shift(id << 1 | 1, mid, r);
	if (b[id << 1] >= val)
		return find(id << 1, l, mid, val);
	return find(id << 1 | 1, mid, r, val);
}

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 0; i < n; ++ i)
		cin >> a[i];
	for (int i = 0; i < n; ++ i)
		cin >> b[i];
	for (int i = n - 1; i >= 0; -- i){
		c[i] += get(1, 0, n, 0, a[i]);
		modify(1, 0, n, a[i]);
	}
	memset(seg, 0, sizeof seg);
	for (int i = n - 1; i >= 0; -- i){
		c[i] += get(1, 0, n, 0, b[i]);
		modify(1, 0, n, b[i]);
	}
	for (int i = n - 1; i >= 0; -- i){
		if (i)
			c[i - 1] += c[i] / (n - i);
		c[i] %= (n - i);
	}
	build(1, 0, n);
	for (int i = 0; i < n; ++ i){
		int x = find(1, 0, n, c[i]);
		update(1, 0, n, x, n);
		cout << x << sep;
	}
	cout << endl;
	
	return 0;
}