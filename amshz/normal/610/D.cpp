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
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e5 + 10;
const int xm = - 20;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, tab[2][xn], ptr[2];
ll ans;
ppp a[xn];
pii b[xn];
stack <pii> st[2][xn];
vector <int> compress[2], seg[2][xn << 2];
unordered_map <int, int> mp[2];
vector <pii> vec[2][xn];

bool cmp(pii i, pii j){
	return i.B < j.B;
}
void modify(int id, int l, int r, int pos, pii x){
	seg[1][id].push_back(x.A);
	seg[0][id].push_back(x.B);
	if (r - l == 1)
		return;
	int mid = l + r >> 1;
	if (pos < mid)
		modify(lc, l, mid, pos, x);
	else
		modify(rc, mid, r, pos, x);
}
void build(int id, int l, int r){
	if (SZ(seg[0][id]))
		sort(all(seg[0][id]));
	if (SZ(seg[1][id])){
		sort(all(seg[1][id]));
		reverse(all(seg[1][id]));
	}
	if (r - l == 1)
		return;
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
}
int get(int id, int l, int r, int ql, int qr, int x){
	if (qr <= l || r <= ql || qr <= ql)
		return 0;
	if (ql <= l && r <= qr){
		int res = SZ(seg[0][id]);
		int lb = - 1, rb = SZ(seg[0][id]), md;
		while (rb - lb > 1){
			md = lb + rb >> 1;
			if (seg[0][id][md] < x) lb = md;
			else rb = md;
		}
		res -= rb;
		lb = - 1, rb = SZ(seg[1][id]);
		while (rb - lb > 1){
			md = lb + rb >> 1;
			if (seg[1][id][md] > x) lb = md;
			else rb = md;
		}
		res -= rb;
		return res;
	}
	int mid = l + r >> 1;
	return get(lc, l, mid, ql, qr, x) + get(rc, mid, r, ql, qr, x);
}
 
int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 1; i <= n; ++ i){
		cin >> a[i].A.A >> a[i].A.B >> a[i].B.A >> a[i].B.B;
		compress[0].push_back(a[i].A.A);
		compress[0].push_back(a[i].B.A);
		compress[1].push_back(a[i].A.B);
		compress[1].push_back(a[i].B.B);
	}
	sort(all(compress[0])), sort(all(compress[1]));
	for (int i = 0; i < SZ(compress[0]); ++ i){
		if (i && compress[0][i] == compress[0][i - 1])
			continue;
		tab[0][ptr[0]] = compress[0][i];
		mp[0][compress[0][i]] = ptr[0] ++;
	}
	for (int i = 0; i < SZ(compress[1]); ++ i){
		if (i && compress[1][i] == compress[1][i - 1])
			continue;
		tab[1][ptr[1]] = compress[1][i];
		mp[1][compress[1][i]] = ptr[1] ++;
	}
	for (int i = 1; i <= n; ++ i){
		a[i].A.A = mp[0][a[i].A.A], a[i].B.A = mp[0][a[i].B.A];
		a[i].A.B = mp[1][a[i].A.B], a[i].B.B = mp[1][a[i].B.B];
		if (a[i].A.B == a[i].B.B){
			if (a[i].B.A < a[i].A.A)
				swap(a[i].A, a[i].B);
			vec[0][a[i].A.B].push_back({a[i].A.A, a[i].B.A});
		}
		else{
			if (a[i].B.B < a[i].A.B)
				swap(a[i].A, a[i].B);
			vec[1][a[i].A.A].push_back({a[i].A.B, a[i].B.B});
		}
	}
	for (int i = 0; i < ptr[1]; ++ i){
		if (SZ(vec[0][i]))
			sort(all(vec[0][i]), cmp);
		for (int j = 0; j < SZ(vec[0][i]); ++ j){
			pii res = vec[0][i][j];
			while (SZ(st[0][i]) && st[0][i].top().B >= res.A){
				res.A = min(res.A, st[0][i].top().A);
				st[0][i].pop();
			}
			st[0][i].push(res);
		}
	}
	for (int i = 0; i < ptr[0]; ++ i){
		if (SZ(vec[1][i]))
			sort(all(vec[1][i]), cmp);
		for (int j = 0; j < SZ(vec[1][i]); ++ j){
			pii res = vec[1][i][j];
			while (SZ(st[1][i]) && st[1][i].top().B >= res.A){
				res.A = min(res.A, st[1][i].top().A);
				st[1][i].pop();
			}
			st[1][i].push(res);
		}
		while (SZ(st[1][i])){
			pii x = st[1][i].top();
			st[1][i].pop();
			modify(1, 0, ptr[0], i, x);
			ans += tab[1][x.B] - tab[1][x.A] + 1;
		}
	}
	build(1, 0, ptr[0]);
	for (int i = 0; i < ptr[1]; ++ i){
		while (SZ(st[0][i])){
			pii x = st[0][i].top();
			st[0][i].pop();
			ans -= get(1, 0, ptr[0], x.A, x.B + 1, i);
			ans += tab[0][x.B] - tab[0][x.A] + 1;
		}
	}
	cout << ans << endl;
	
	return 0;
}