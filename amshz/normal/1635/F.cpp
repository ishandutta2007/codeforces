//khodaya khodet komak kon
# include <bits/stdc++.h>

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
# define fast_io                                         ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 3e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 4e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, q;
ll ans[xn], seg[xn << 2];
pii a[xn], b[xn];
vector <int> sk, Q[2][xn];

void build(int id, int l, int r){
	seg[id] = INF;
	if (r - l == 1)
		return;
	int mid = l + r >> 1;
	build(lc, l, mid);
	build(rc, mid, r);
}
void modify(int id, int l, int r, int pos, ll val){
	seg[id] = min(seg[id], val);
	if (r - l == 1)
		return;
	int mid = l + r >> 1;
	if (pos < mid)
		modify(lc, l, mid, pos, val);
	else
		modify(rc, mid, r, pos, val);
}
ll get(int id, int l, int r, int ql, int qr){
	if (qr <= l || r <= ql || qr <= ql)
		return INF;
	if (ql <= l && r <= qr)
		return seg[id];
	int mid = l + r >> 1;
	return min(get(lc, l, mid, ql, qr), get(rc, mid, r, ql, qr));
}

int main(){
	fast_io;

	cin >> n >> q;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i].A >> a[i].B;
	for (int i = 1; i <= n; ++ i){
		while (SZ(sk) && a[i].B < a[sk.back()].B)
			sk.pop_back();
		if (SZ(sk))
			Q[0][i].push_back(sk.back());
		sk.push_back(i);
	}
	sk.clear();
	for (int i = n; 1 <= i; -- i){
		while (SZ(sk) && a[i].B < a[sk.back()].B)
			sk.pop_back();
		if (SZ(sk))
			Q[0][sk.back()].push_back(i);
		sk.push_back(i);
	}
	for (int i = 1; i <= q; ++ i){
		int l, r;
		cin >> l >> r;
		b[i] = {l, r};
		Q[1][r].push_back(i);
		ans[i] = INF;
	}
	build(1, 1, n + 1);
	for (int i = 1; i <= n; ++ i){
		for (int x : Q[0][i])
			modify(1, 1, n + 1, x, 1ll * (a[i].A - a[x].A) * (a[i].B + a[x].B));
		for (int x : Q[1][i])
			ans[x] = min(ans[x], get(1, 1, n + 1, b[x].A, i + 1));
	}
	for (int i = 1; i <= q; ++ i)
		cout << ans[i] << endl;

	return 0;
}