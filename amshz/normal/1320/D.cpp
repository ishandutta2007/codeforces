//khodaya khodet komak kon
# include <bits/stdc++.h>
 
/*
// ordered_set 
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/
 
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
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ll mod[2] = {1000000009, 1000000007};
const ll base = 1e6 + 7;

struct node{
	bool istohi;
	ll f[2], sz, ted, l, r, t;
	pll ans;
};

ll n, q, pw[2][xn], part[xn], Inv[2];
ll ps[2][xn];
string s;
node seg[xn << 2], tohi;

node merge(node v, node u){
	if (v.istohi)
		return u;
	if (u.istohi)
		return v;
	node w;
	w.ans.A = (v.ans.A + u.ans.A * pw[0][v.ted] % mod[0]) % mod[0];
	w.ans.B = (v.ans.B + u.ans.B * pw[1][v.ted] % mod[1]) % mod[1];
	w.istohi = false;
	w.sz = v.sz + u.sz;
	w.t = v.t + u.t;
	w.l = v.l;
	w.r = u.r;
	w.ted = v.ted + u.ted;
	w.f[0] = v.f[0];
	if (v.f[0] == v.sz)
		w.f[0] += u.f[0];
	w.f[1] = u.f[1];
	if (u.f[1] == u.sz)
		w.f[1] += v.f[1];
	if (v.f[1] % 2 && u.f[0] % 2){
		w.ted -= 2;
		-- v.ted;
		v.ans.A = (v.ans.A - part[v.r] * pw[0][v.ted] % mod[0] + mod[0]) % mod[0];
		v.ans.B = (v.ans.B - part[v.r] * pw[1][v.ted] % mod[1] + mod[1]) % mod[1];
		u.ans.A = (u.ans.A - part[v.r] + mod[0]) % mod[0];
		u.ans.A = u.ans.A * Inv[0] % mod[0];
		u.ans.B = (u.ans.B - part[v.r] + mod[1]) % mod[1];
		u.ans.B = u.ans.B * Inv[1] % mod[1];
		w.ans.A = (v.ans.A + u.ans.A * pw[0][v.ted] % mod[0]) % mod[0];
		w.ans.B = (v.ans.B + u.ans.B * pw[1][v.ted] % mod[1]) % mod[1];
	}
	return w;
}
void build(int id, int l, int r){
	if (r - l == 1){
		seg[id].istohi = false;
		seg[id].sz = 1;
		seg[id].f[0] = seg[id].f[1] = seg[id].ted = s[l - 1] - '0';
		seg[id].t = 1 - s[l - 1] + '0';
		seg[id].l = l, seg[id].r = r;
		if (s[l - 1] == '1'){
			seg[id].ans.A = part[l];
			seg[id].ans.B = part[l];
		}
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
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
	InTheNameOfGod;
	
	pw[0][0] = pw[1][0] = 1;
	ps[0][0] = ps[1][0] = 1;
	for (ll i = 1; i < xn; ++ i){
		pw[0][i] = pw[0][i - 1] * base % mod[0];
		pw[1][i] = pw[1][i - 1] * base % mod[1];
		ps[0][i] = (ps[0][i - 1] + pw[0][i]) % mod[0];
		ps[1][i] = (ps[1][i - 1] + pw[1][i]) % mod[1];
	}
	Inv[0] = power(base, mod[0] - 2, mod[0]);
	Inv[1] = power(base, mod[1] - 2, mod[1]);
	cin >> n >> s;
	for (int i = 1; i <= n; ++ i)
		part[i] = part[i - 1] + 1 - s[i - 1] + '0';
	build(1, 1, n + 1);
	tohi.istohi = true;
	cin >> q;
	while (q --){
		int l1, l2, arz;
		cin >> l1 >> l2 >> arz;
		if (l1 > l2)
			swap(l1, l2);
		node x = get(1, 1, n + 1, l1, l1 + arz);
		node y = get(1, 1, n + 1, l2, l2 + arz);
		if (x.ted){
			x.ans.A = (x.ans.A + (part[l2 - 1] - part[l1 - 1]) * ps[0][x.ted - 1]) % mod[0];
			x.ans.B = (x.ans.B + (part[l2 - 1] - part[l1 - 1]) * ps[1][x.ted - 1]) % mod[1];
		}
		if (x.ans == y.ans && x.t == y.t)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
			
	return 0;
}