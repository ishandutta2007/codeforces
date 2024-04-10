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

const int xn = 1e6 + 10;
const int xm = 2e6 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int qq, n, m, a[xn], b[xn], seg[xn << 2], ptr, cnt[xm];
int lazy[xn << 2], fen[xm];
vector <int> vec[xm];
vector <pii> cprs;
ll ans, ted;

void build(int id, int l, int r){
	lazy[id] = 0;
	if (r - l == 1){
		seg[id] = 0;
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid);
	build(rc, mid, r);
	seg[id] = min(seg[lc], seg[rc]);
}
void shift(int id, int l, int r){
	if (!lazy[id])
		return;
	seg[id] += lazy[id];
	if (1 < r - l)
		lazy[lc] += lazy[id], lazy[rc] += lazy[id];
	lazy[id] = 0;
}
void update(int id, int l, int r, int ql, int qr, int val){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql)
		return;
	if (ql <= l && r <= qr){
		lazy[id] += val;
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(lc, l, mid, ql, qr, val);
	update(rc, mid, r, ql, qr, val);
	seg[id] = min(seg[lc], seg[rc]);
}
void mofen(int pos, int val){
	for (pos += 5; pos < xm; pos += pos & - pos)
		fen[pos] += val;
}
int gefen(int pos){
	int res = 0;
	for (pos += 5; 0 < pos; pos -= pos & - pos)
		res += fen[pos];
	return res;
}

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n >> m;
		cprs.clear();
		for (int i = 1; i <= n; ++ i)
			cin >> a[i], cprs.push_back({a[i], i});
		for (int i = 1; i <= m; ++ i)
			cin >> b[i], cprs.push_back({b[i], - i});
		sort(all(cprs));
		ptr = 0;
		for (int i = 0; i < SZ(cprs); ++ i){
			if (!i || cprs[i].A != cprs[i - 1].A)
				++ ptr;
			if (0 < cprs[i].B)
				a[cprs[i].B] = ptr;
			else
				b[- cprs[i].B] = ptr;
		}
		for (int i = 0; i <= ptr; ++ i)
			cnt[i] = 0, vec[i].clear();
		ans = 0;
		build(1, 0, n + 1);
		for (int i = 1; i <= n; ++ i){
			update(1, 0, n + 1, i, n + 1, 1);
			vec[a[i]].push_back(i);
			ans += i - 1 - gefen(a[i]);
			mofen(a[i], 1);
		}
		for (int i = 1; i <= n; ++ i)
			mofen(a[i], - 1);
		for (int i = 1; i <= m; ++ i)
			++ cnt[b[i]];
		ted = 0;
		for (int i = 1; i <= ptr; ++ i){
			for (int x : vec[i])
				update(1, 0, n + 1, x, n + 1, - 1);
			ans += 1ll * cnt[i] * ll(ted + seg[1]);
			for (int x : vec[i])
				update(1, 0, n + 1, x, n + 1, - 1), ++ ted;
		}
		cout << ans << endl;
	}

	return 0;
}