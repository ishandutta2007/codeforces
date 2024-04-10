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

const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, a[xn], last[xn], b[xn], seg[xn << 2], ans;

void build(int id, int l, int r){
	if (r - l == 1){
		seg[id] = b[l];
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
	seg[id] = min(seg[lc], seg[rc]);
}
int get(int id, int l, int r, int ql, int qr){
	if (qr <= l || r <= ql || qr <= ql)
		return inf;
	if (ql <= l && r <= qr)
		return seg[id];
	int mid = l + r >> 1;
	return min(get(lc, l, mid, ql, qr), get(rc, mid, r, ql, qr));
}

int main(){
	fast_io;

	cin >> n;
	for (int i = 1; i <= n; ++ i){
		cin >> a[i];
		b[i] = last[a[i]];
		if (!b[i])
			b[i] = inf;
		if (!last[a[i]])
			last[a[i]] = i;
	}
	build(1, 1, n + 1);
	int ptr = n;
	while (ptr){
		int x = get(1, 1, n + 1, ptr, n + 1);
		if (ptr <= x)
			-- ptr;
		else
			ans += ptr - x - 1, ptr = x;
	}
	cout << ans << endl;

	return 0;
}