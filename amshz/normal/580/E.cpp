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
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e5 + 10;
const int xm = 26 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod[3] = {1000000007, 1000000009, 998244353};
const ll MOD = 1111118111111;
const int base = 10;

struct node{
	int hash[3], sz;
	bool istohi = false;
};

int n, m, k, pw[3][xn];
node seg[xn << 2], tohi;
int lazy[xn << 2], a[3][xn];
string s;

bool check(node v, node u){
	bool flag = true;
	for (int i = 0; i < 3; ++ i)
		flag &= v.hash[i] == u.hash[i];
	return flag;
}
node merge(node v, node u){
	if (v.istohi) return u;
	if (u.istohi) return v;
	node w;
	w.sz = v.sz + u.sz;
	for (int i = 0; i < 3; ++ i)
		w.hash[i] = (v.hash[i] + ll(u.hash[i]) * ll(pw[i][v.sz])) % mod[i];
	return w;
}
void build(int id, int l, int r){
	lazy[id] = - 1;
	if (r - l == 1){
		seg[id].sz = 1;
		for (int i = 0; i < 3; ++ i)
			seg[id].hash[i] = s[l] - '0';
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
	seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
}
void shift(int id, int l, int r){
	if (lazy[id] == - 1)
		return;
	for (int i = 0; i < 3; ++ i)
		seg[id].hash[i] = ll(a[i][r - l]) * ll(lazy[id]) % mod[i];
	if (r - l > 1){
		lazy[id << 1] = lazy[id];
		lazy[id << 1 | 1] = lazy[id];
	}
	lazy[id] = - 1;
}
void update(int id, int l, int r, int ql, int qr, int val){
	shift(id, l, r);
	if (qr <= l || r <= ql)
		return;
	if (ql <= l && r <= qr){
		lazy[id] = val;
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(id << 1, l, mid, ql, qr, val);
	update(id << 1 | 1, mid, r, ql, qr, val);
	seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
}
node get(int id, int l, int r, int ql, int qr){
	shift(id, l, r);
	if (qr <= l || r <= ql)
		return tohi;
	if (ql <= l && r <= qr)
		return seg[id];
	int mid = l + r >> 1;
	return merge(get(id << 1, l, mid, ql, qr), get(id << 1 | 1, mid, r, ql, qr));
}

int main(){
	InTheNameOfGod;
	
	for (int i = 0; i < 3; ++ i)
		pw[i][0] = 1;
	for (int i = 0; i < 3; ++ i)
		for (int j = 1; j < xn; ++ j)
			pw[i][j] = ll(pw[i][j - 1]) * ll(base) % mod[i];
	cin >> n >> m >> k >> s;
	s = '.' + s, m += k;
	build(1, 1, n + 1);
	tohi.istohi = true;
	for (int i = 1; i < xn; ++ i)
		for (int j = 0; j < 3; ++ j)
			a[j][i] = (a[j][i - 1] + pw[j][i - 1]) % mod[j];
	while (m --){
		int t, l, r, x;
		cin >> t >> l >> r >> x;
		if (t == 1)
			update(1, 1, n + 1, l, r + 1, x);
		else{
			node v = get(1, 1, n + 1, l, r - x + 1);
			node u = get(1, 1, n + 1, l + x, r + 1);
			if (check(v, u))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	
	return 0;
}