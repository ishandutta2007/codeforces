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
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, a[xn], qq;
pii mn[xn << 2], mx[xn << 2];

void build(int id, int l, int r){
	if (r - l == 1){
		mn[id] = mx[id] = {a[l], l};
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid);
	build(rc, mid, r);
	mn[id] = min(mn[lc], mn[rc]);
	mx[id] = max(mx[lc], mx[rc]);
}
pii getmn(int id, int l, int r, int ql, int qr){
	if (qr <= l || r <= ql || qr <= ql)
		return {n + 1, 0};
	if (ql <= l && r <= qr)
		return mn[id];
	int mid = l + r >> 1;
	return min(getmn(lc, l, mid, ql, qr), getmn(rc, mid, r, ql, qr));
}
pii getmx(int id, int l, int r, int ql, int qr){
	if (qr <= l || r <= ql || qr <= ql)
		return {0, 0};
	if (ql <= l && r <= qr)
		return mx[id];
	int mid = l + r >> 1;
	return max(getmx(lc, l, mid, ql, qr), getmx(rc, mid, r, ql, qr));
}
int solve(int l, int r){
	if (l == r)
		return 0;
	int x = getmn(1, 1, n + 1, l, r + 1).B;
	int y = getmx(1, 1, n + 1, l, r + 1).B;
	if (l < x && x < r){
		return solve(l, x) + solve(x, r);
	}
	if (l < y && y < r){
		return solve(l, y) + solve(y, r);
	}
	return 1;
}

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n;
		for (int i = 1; i <= n; ++ i)
			cin >> a[i];
		build(1, 1, n + 1);
		cout << solve(1, n) << endl;
	}

	return 0;
}