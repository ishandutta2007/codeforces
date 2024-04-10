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
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

struct node{
	bool istohi;
	int sz, ans, ted;
	vector <int> pre, suff, b;
};

int n, q, a[xn], pt1, pt2, ptr, mxp1, mxp2, mxs1, mxs2;
string s[xn];
node seg[xn << 2], tohi;

node merge(node v, node u){
	if (v.istohi)
		return u;
	if (u.istohi)
		return v;
	node w;
	w.b.clear();
	w.pre.clear();
	w.suff.clear();
	w.b.push_back(0);
	w.pre.push_back(0);
	w.suff.push_back(0);
	w.istohi = false;
	w.sz = v.sz + u.sz;
	w.ans = max(v.ans, u.ans);
	pt1 = pt2 = ptr = 0;
	while (pt1 < v.ted || pt2 < u.ted){
		w.b.push_back(0);
		w.pre.push_back(0);
		w.suff.push_back(0);
		int f = 0, val = v.b[pt1];
		if (pt1 == v.ted || (pt2 < u.ted && v.b[pt1] > u.b[pt2])) f = 1;
		else if (pt2 == u.ted || (pt1 < v.ted && v.b[pt1] < u.b[pt2])) f = 2;
		if (f == 1) val = u.b[pt2];
		w.pre[ptr] = v.pre[pt1];
		if (v.suff[pt1] == v.sz)
			w.pre[ptr] += u.pre[pt2] + 1;
		w.suff[ptr] = u.suff[pt2];
		if (u.suff[pt2] == u.sz)
			w.suff[ptr] += v.suff[pt1];
		w.ans = max(w.ans, val * (v.suff[pt1] + u.pre[pt2] + 1));
		w.b[ptr] = val;
		if (f == 1)
			++ pt2;
		else if (f == 2)
			++ pt1;
		else
			++ pt1, ++ pt2;
		++ ptr;
	}
	w.ted = ptr;
	return w;
}
void build(int id, int l, int r){
	if (r - l == 1){
		seg[id].b.push_back(0);
		seg[id].b.push_back(0);
		seg[id].pre.push_back(0);
		seg[id].pre.push_back(0);
		seg[id].suff.push_back(0);
		seg[id].suff.push_back(0);
		seg[id].sz = 1;
		seg[id].ans = SZ(s[l]);
		seg[id].ted = seg[id].suff[0] = 1;
		seg[id].pre[0] = 0;
		seg[id].b[0] = a[l];
		seg[id].istohi = false;
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
	seg[id] = merge(seg[lc], seg[rc]);
}
void modify(int id, int l, int r, int pos){
	if (!pos)
		return;
	if (r - l == 1){
		seg[id].b.push_back(0);
		seg[id].b.push_back(0);
		seg[id].pre.push_back(0);
		seg[id].pre.push_back(0);
		seg[id].suff.push_back(0);
		seg[id].suff.push_back(0);
		seg[id].sz = 1;
		seg[id].ans = SZ(s[l]);
		seg[id].ted = seg[id].suff[0] = 1;
		seg[id].pre[0] = 0;
		seg[id].b[0] = a[l];
		seg[id].istohi = false;
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
	InTheNameOfGod;
	
	cin >> n >> q;
	for (int i = 1; i <= n; ++ i)
		cin >> s[i];
	for (int i = 1; i < n; ++ i){
		for (int j = 0; j < min(SZ(s[i]), SZ(s[i + 1])); ++ j){
			if (s[i][j] != s[i + 1][j])
				break;
			++ a[i];
		}
	}
	build(1, 1, n + 1);
	tohi.istohi = true;
	while (q --){
		int t, l, r, ind;
		string S;
		cin >> t;
		if (t == 2){
			cin >> ind >> S;
			s[ind] = S;
			a[ind] = 0;
			for (int j = 0; j < min(SZ(s[ind]), SZ(s[ind + 1])); ++ j){
				if (s[ind][j] != s[ind + 1][j])
					break;
				++ a[ind];
			}
			a[ind - 1] = 0;
			for (int j = 0; j < min(SZ(s[ind - 1]), SZ(s[ind])); ++ j){
				if (s[ind - 1][j] != s[ind][j])
					break;
				++ a[ind - 1];
			}
			modify(1, 1, n + 1, ind - 1);
			modify(1, 1, n + 1, ind);
		}
		else{
			cin >> l >> r;
			cout << get(1, 1, n + 1, l, r + 1).ans << endl;
		}
	}
	
	return 0;
}