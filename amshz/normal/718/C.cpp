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

const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

struct matrix{
    int n, m, a[2][2];
    matrix(int n1, int m1, int x = 0){
        n = n1; m = m1;
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                a[i][j] = x;
    }
    matrix operator * (const matrix &t){
        matrix r = matrix(n, t.m);
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < t.m; j ++)
                for (int k = 0; k < m; k ++)
                    r.a[i][j] = (r.a[i][j] + 1ll * a[i][k] * t.a[k][j] % mod) % mod;
        return r;
    }
};

matrix Pow(matrix a, ll b){
    matrix res = matrix(a.n, a.m);
    for (int i = 0; i < a.n; i ++)
    	res.a[i][i] = 1;
    for (; b; b = b >> 1){
        if (b & 1)
            res = res * a;
        a = a * a;
    }
    return res;
}
pii merge(pii x, pii y){
	pii z = {0, 0};
	z.A = (1ll * x.A * (y.B - y.A + mod) % mod + 1ll * x.B * y.A) % mod;
	z.B = (1ll * x.A * y.A % mod + 1ll * x.B * y.B % mod) % mod;
	return z;
}

int n, m, a[xn];
pii seg[xn << 2], lazy[xn << 2];

pii F(int x, int y, ll k){
	matrix M(1, 2), c(2, 2);
	M.a[0][0] = x, M.a[0][1] = y;
	c.a[0][1] = c.a[1][0] = c.a[1][1] = 1;
	M = M * Pow(c, k);
	return {M.a[0][0], M.a[0][1]};
}
void build(int id, int l, int r){
	lazy[id] = {0, 1};
	if (r - l == 1){
		seg[id] = F(0, 1, a[l]);
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
	seg[id].A = (seg[lc].A + seg[rc].A) % mod;
	seg[id].B = (seg[lc].B + seg[rc].B) % mod;
}
void shift(int id, int l, int r){
	if (lazy[id].A == 0 && lazy[id].B == 1)
		return;
	seg[id] = merge(seg[id], lazy[id]);
	if (1 < r - l){
		lazy[lc] = merge(lazy[lc], lazy[id]);
		lazy[rc] = merge(lazy[rc], lazy[id]);
	}
	lazy[id] = {0, 1};
}
void update(int id, int l, int r, int ql, int qr, pii val){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql)
		return;
	if (ql <= l && r <= qr){
		lazy[id] = merge(lazy[id], val);
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(lc, l, mid, ql, qr, val);
	update(rc, mid, r, ql, qr, val);
	seg[id].A = (seg[lc].A + seg[rc].A) % mod;
	seg[id].B = (seg[lc].B + seg[rc].B) % mod;
}
int get(int id, int l, int r, int ql, int qr){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql)
		return 0;
	if (ql <= l && r <= qr)
		return seg[id].A;
	int mid = l + r >> 1;
	return (get(lc, l, mid, ql, qr) + get(rc, mid, r, ql, qr)) % mod;
}

int main(){
	fast_io;

	cin >> n >> m;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	build(1, 1, n + 1);
	while (m --){
		int t, l, r, x;
		cin >> t >> l >> r;
		if (t == 1){
			cin >> x;
			update(1, 1, n + 1, l, r + 1, F(0, 1, x));
		}
		else
			cout << get(1, 1, n + 1, l, r + 1) << endl;
	}

	return 0;
}