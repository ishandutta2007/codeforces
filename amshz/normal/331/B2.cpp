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


const int xn = 3e5 + 10;
const int xm = - 20;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, a[xn], seg[xn << 2], b[xn], p[xn], m;

void modify(int id, int l, int r, int pos, int val){
	if (r - l == 1){
		seg[id] += val;
		return;
	}
	int mid = l + r >> 1;
	if (pos < mid)
		modify(id << 1, l, mid, pos, val);
	else
		modify(id << 1 | 1, mid, r, pos, val);
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

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i], p[a[i]] = i;
	for (int i = 1; i < n; ++ i){
		b[i] = (p[i] > p[i + 1]);
		modify(1, 1, n, i, b[i]);
	}
	cin >> m;
	while (m --){
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1)
			cout << get(1, 1, n, x, y) + 1 << endl;
		else{
			int X = a[x], Y = a[y];
			if (X > Y)
				swap(X, Y);
			if (X > 1) modify(1, 1, n, X - 1, - b[X - 1]);
			if (X < n) modify(1, 1, n, X, - b[X]);
			if (Y > 1 && Y > X + 1) modify(1, 1, n, Y - 1, - b[Y - 1]);
			if (Y < n) modify(1, 1, n, Y, - b[Y]);
			swap(p[X], p[Y]);
			if (X > 1) b[X - 1] = bool(p[X - 1] > p[X]);
			if (X < n) b[X] = bool(p[X] > p[X + 1]);
			if (Y > 1) b[Y - 1] = bool(p[Y - 1] > p[Y]);
			if (Y < n) b[Y] = bool(p[Y] > p[Y + 1]);
			swap(a[x], a[y]);
			if (X > 1) modify(1, 1, n, X - 1, b[X - 1]);
			if (X < n) modify(1, 1, n, X, b[X]);
			if (Y > 1 && Y > X + 1) modify(1, 1, n, Y - 1, b[Y - 1]);
			if (Y < n) modify(1, 1, n, Y, b[Y]);
		}
	}
	
	return 0;
}