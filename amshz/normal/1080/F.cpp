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
//# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, m, k;
vector <pii> seg[xn << 2];

void modify(int id, int l, int r, int pos, pii val){
	if (r - l == 1){
		seg[id].push_back(val);
		return;
	}
	int mid = l + r >> 1;
	if (pos < mid)
		modify(lc, l, mid, pos, val);
	else
		modify(rc, mid, r, pos, val);
}
void build(int id, int l, int r){
	if (r - l == 1){
		sort(all(seg[id]));
		int mn = inf;
		for (int i = SZ(seg[id]) - 1; i >= 0; -- i)
			mn = min(mn, seg[id][i].B), seg[id][i].B = mn;
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
	for (pii x : seg[lc])
		seg[id].push_back(x);
	for (pii x : seg[rc])
		seg[id].push_back({x.A, - x.B});
	sort(all(seg[id]));
	int mn1 = inf, mn2 = inf;
	for (int i = SZ(seg[id]) - 1; i >= 0; -- i){
		if (0 < seg[id][i].B)
			mn1 = min(mn1, seg[id][i].B);
		else
			mn2 = min(mn2, - seg[id][i].B);
		seg[id][i].B = max(mn1, mn2);
	}
}
int get(int id, int l, int r, int ql, int qr, int val){
	if (qr <= l || r <= ql || qr <= ql)
		return - inf;
	if (ql <= l && r <= qr){
		int lb = - 1, rb = SZ(seg[id]);
		while (1 < rb - lb){
			int md = lb + rb >> 1;
			if (seg[id][md].A < val)
				lb = md;
			else
				rb = md;
		}
		if (rb < SZ(seg[id]))
			return seg[id][rb].B;
		return inf;
	}
	int mid = l + r >> 1;
	return max(get(lc, l, mid, ql, qr, val), get(rc, mid, r, ql, qr, val));
}

int main(){
	InTheNameOfGod;

	cin >> n >> m >> k;
	while (k --){
		int l, r, p;
		cin >> l >> r >> p;
		modify(1, 1, n + 1, p, {l, r});
	}
	build(1, 1, n + 1);
	while (m --){
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		if (get(1, 1, n + 1, a, b + 1, x) <= y)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}

	return 0;
}
/*
5 1 9
3 6 3
1 3 1
2 4 2
1 2 3
4 6 5
2 5 3
7 9 4
2 3 1
4 10 4
2 3 3 6
*/