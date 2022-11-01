# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <ll, ll>                                  pii;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

struct node{
	ll seg[4], del[2], sz;
	pii val, big[2];
};

ll n, q, a[xn], lazy[xn << 2], ans;
node s[xn << 2], tohi;

node merge(node v, node u, int mid){
	if (u.big[0].A == 2)
		return v;
	if (v.big[0].A == 2)
		return u;
	node w;
	w.val.A = v.val.A;
	w.val.B = u.val.B;
	w.big[0] = v.big[0];
	w.del[0] = v.del[0];
	w.sz = v.sz + u.sz;
	if (v.sz == 1){
		w.big[0].A = bool(u.val.A <= v.val.A);
		w.big[0].B = bool(u.val.A >= v.val.A);
		w.del[0] = u.val.A - v.val.A;
		
	}
	w.big[1] = u.big[1];
	w.del[1] = u.del[1];
	if (u.sz == 1){
		w.big[1].A = bool(u.val.B >= v.val.B);
		w.big[1].B = bool(u.val.B <= v.val.B);
		w.del[1] = v.val.B - u.val.B;
	}
	w.seg[0] = v.seg[0] + u.seg[0];
	w.seg[0] += abs(v.val.B - u.val.A);
	ll t = 0;
	if (v.val.B == u.val.A)
		t = 0;
	else if (v.val.B > u.val.A)
		t = 1;
	else
		t = 2;
	w.seg[1] = max(v.seg[1], u.seg[1]);
	w.seg[2] = max(v.seg[2], u.seg[2]);
	w.seg[3] = min(v.seg[3], u.seg[3]);
	if (t % 2 == 0 && u.big[0].A)
		w.seg[1] = mid;
	if (t < 2 && v.big[1].A)
		w.seg[1] = mid - 1;
	if (t < 2 && u.big[0].B)
		w.seg[2] = mid;
	if (t % 2 == 0 && v.big[1].B)
		w.seg[2] = mid - 1;
	if (t % 2 == 0 && u.big[0].B)
		w.seg[3] = min(w.seg[3], u.del[0]);
	if (t < 2 && u.big[0].A)
		w.seg[3] = min(w.seg[3], v.val.B - u.val.A);
	if (t < 2 && v.big[1].B)
		w.seg[3] = min(w.seg[3], v.del[1]);
	if (t % 2 == 0 && v.big[1].A)
		w.seg[3] = min(w.seg[3], u.val.A - v.val.B);
	return w;
}
void build(int id, int l, int r){
	if (r - l == 1){
		s[id].sz = 1;
		s[id].val = {a[l], a[l]};
		s[id].seg[1] = s[id].seg[2] = - 1;
		s[id].seg[3] = INF;
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
	s[id] = merge(s[id << 1], s[id << 1 | 1], mid);
}
void shift(int id, int l, int r){
	if (!lazy[id])
		return;
	s[id].val.A += lazy[id];
	s[id].val.B += lazy[id];
	if (r - l > 1){
		lazy[id << 1] += lazy[id];
		lazy[id << 1 | 1] += lazy[id];
	}
	lazy[id] = 0;
}
void update(int id, int l, int r, int ql, int qr, ll x){
	shift(id, l, r);
	if (qr <= l || r <= ql)
		return;
	if (ql <= l && r <= qr){
		lazy[id] += x;
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(id << 1, l, mid, ql, qr, x);
	update(id << 1 | 1, mid, r, ql, qr, x);
	s[id] = merge(s[id << 1], s[id << 1 | 1], mid);
}
node get(int id, int l, int r, int ql, int qr){
	shift(id, l, r);
	if (qr <= l || r <= ql)
		return tohi;
	if (ql <= l && r <= qr)
		return s[id];
	int mid = l + r >> 1;
	return merge(get(id << 1, l, mid, ql, qr), get(id << 1 | 1, mid, r, ql, qr), mid);
}
void check(int ind, ll x){
	if (ind == - 1)
		return;
	update(1, 1, n + 1, ind, ind + 1, x);
	ans = max(ans, s[1].seg[0]);
	update(1, 1, n + 1, ind, ind + 1, - x);
}

int main(){
	InTheNameOfGod;
	
	tohi.big[0].A = 2;
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	build(1, 1, n + 1);
	cin >> q;
	while (q --){
		ll t, l, r, x;
		cin >> t >> l >> r >> x;
		if (t == 2)
			update(1, 1, n + 1, l, r + 1, x);
		else{
			node y = get(1, 1, n + 1, l, r + 1);
			ll last = s[1].seg[0];
			ans = 0;
			check(l, x);
			check(r, x);
			check(y.seg[1], x);
			check(y.seg[2], x);
			if (x > y.seg[3])
				ans = max(ans, last + 2LL * (x - y.seg[3]));
			cout << ans << endl;
		}
	}
	
	return 0;
}