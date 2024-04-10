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
const int mod = 998244353;
const int base = 257;

struct node{
	int sz, pref, suff, mx;
	bool istohi = false;
};

int n, q, a[xn], tb[xn], ptr;
pii b[xn];
ppi c[xn];
unordered_map <int, int> mp;
vector <int> cprs, vec[xn], Q[xn];
node seg[xn << 2], tohi;

node merge(node v, node u){
	if (v.istohi)
		return u;
	if (u.istohi)
		return v;
	node w;
	w.sz = v.sz + u.sz;
	w.pref = v.pref;
	if (v.pref == v.sz)
		w.pref += u.pref;
	w.suff = u.suff;
	if (u.suff == u.sz)
		w.suff += v.suff;
	w.mx = max({v.mx, u.mx, v.suff + u.pref});
	return w;
}
void build(int id, int l, int r){
	if (r - l == 1){
		seg[id].pref = seg[id].suff = seg[id].mx = 0;
		seg[id].sz = 1;
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
	seg[id] = merge(seg[lc], seg[rc]);
}
void modify(int id, int l, int r, int pos){
	if (r - l == 1){
		seg[id].pref = seg[id].suff = seg[id].mx = 1;
		return;
	}
	int mid = l + r >> 1;
	if (pos < mid)
		modify(lc, l, mid, pos);
	else
		modify(rc, mid, r, pos);
	seg[id] = merge(seg[lc], seg[rc]);
}
node get(int id, int l, int r, int ql, int qr){
	if (qr <= l || r <= ql || qr <= ql)
		return tohi;
	if (ql <= l && r <= qr)
		return seg[id];
	int mid = l + r >> 1;
	return merge(get(lc, l, mid, ql, qr), get(rc, mid, r, ql, qr));
}

int main(){
	fast_io;

	tohi.istohi = true;
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i], cprs.push_back(a[i]);
	sort(all(cprs));
	for (int i = 0; i < SZ(cprs); ++ i){
		if (i && cprs[i] == cprs[i - 1])
			continue;
		mp[cprs[i]] = ++ ptr;
		tb[ptr] = cprs[i];
	}
	for (int i = 1; i <= n; ++ i)
		vec[mp[a[i]]].push_back(i);
	cin >> q;
	for (int i = 1; i <= q; ++ i){
		int l, r, w;
		cin >> l >> r >> w;
		c[i] = {{l, r}, w};
		b[i] = {1, ptr + 1};
	}
	for (int _ = 0; _ < 18; ++ _){
		for (int i = 1; i <= ptr; ++ i)
			Q[i].clear();
		for (int i = 1; i <= q; ++ i)
			Q[b[i].A + b[i].B >> 1].push_back(i);
		build(1, 1, n + 1);
		for (int i = ptr; 1 <= i; -- i){
			for (int x : vec[i])
				modify(1, 1, n + 1, x);
			for (int x : Q[i]){
				if (get(1, 1, n + 1, c[x].A.A, c[x].A.B + 1).mx < c[x].B)
					b[x].B = b[x].A + b[x].B >> 1;
				else
					b[x].A = b[x].A + b[x].B >> 1;
			}
		}
	}
	for (int i = 1; i <= q; ++ i)
		cout << tb[b[i].A] << endl;

	return 0;
}