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
 
const int xn = 4e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;
 
int n, dp[xn], ans, fen[xn], q, seg[xn << 2], pd[xn], b[xn];
pii a[xn];
vector <pii> Q[xn];
bool flag[xn];
 
void mofen(int pos, int val = 1){
	for (pos += 5; pos < xn; pos += pos & - pos)
		fen[pos] = (fen[pos] + val) % mod;
}
int gefen(int pos){
	int res = 0;
	for (pos += 5; pos > 0; pos -= pos & - pos)
		res = (res + fen[pos]) % mod;
	return res;
}
void modify(int id, int l, int r, int pos, int val){
	seg[id] = max(seg[id], val);
	if (r - l == 1)
		return;
	int mid = l + r >> 1;
	if (pos < mid)
		modify(lc, l, mid, pos, val);
	else
		modify(rc, mid, r, pos, val);
}
int get(int id, int l, int r, int ql, int qr){
	if (qr <= l || r <= ql || qr <= ql)
		return 0;
	if (ql <= l && r <= qr)
		return seg[id];
	int mid = l + r >> 1;
	return max(get(lc, l, mid, ql, qr), get(rc, mid, r, ql, qr));
}
 
int main(){
	fast_io;
 
	cin >> n;
	for (int i = 1; i <= n; ++ i){
		int l, r;
		cin >> l >> r;
		a[r] = {l, i};
	}
	cin >> q;
	while (q --){
		int x;
		cin >> x;
		flag[x] = true;
	}
	for (int i = 1; i <= n + n; ++ i){
		if (!a[i].A)
			continue;
		dp[i] = (gefen(i) - gefen(a[i].A) + mod + 1) % mod;
		mofen(a[i].A, dp[i]);
		if (!flag[a[i].B])
			continue;
		int mx = get(1, 0, xn, a[i].A, i);
		b[i] = mx;
		Q[mx].push_back({a[i].A, i});
		modify(1, 0, xn, a[i].A, i);
	}
	int mx = get(1, 0, xn, 0, xn);
	Q[mx].push_back({0, n + n + 1});
	fill(fen, fen + xn, 0);
	for (int i = 1; i <= n + n; ++ i){
		for (pii x : Q[i])
			pd[x.B] = (gefen(i) - gefen(x.A) + mod) % mod;
		if (a[i].A)
			mofen(a[i].A, dp[i]);
	}
	for (int i = 1; i <= n + n; ++ i)
		if (flag[a[i].B])
			pd[i] = (pd[i] + pd[b[i]] + 1) % mod;
	cout << (pd[n + n + 1] + pd[mx]) % mod << endl;
 
	return 0;
}