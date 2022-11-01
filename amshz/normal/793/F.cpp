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
const int xm = 320 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;
 
int n, L[xn], a[xn], m, q, P[xn], ans[xn], ptr[xm];
vector <pii> query[xn];
pii sk[xm][xm];
 
bool cmp(int i, int j){
	return a[i] < a[j];
}
void build(int id){
	int l = id * sq, r = min(n, (id + 1) * sq - 1);
	sort(P + l, P + r + 1, cmp);
	for (int i = l; i <= r; ++ i)
		sk[id][ptr[id] ++] = {a[P[i]], 1};
}
void get_all(int id){
	int l = id * sq, r = min(n, (id + 1) * sq - 1);
	int pt = r;
	while (ptr[id]){
		pii x = sk[id][-- ptr[id]];
		while (x.B){
			a[P[pt --]] = x.A;
			-- x.B;
		}
	}
}
void update(int l, int r){
	int last = 0;
	for (int id = 0; (id + 1) * sq - 1 <= l; ++ id){
		pii x = {r, 0};
		while (ptr[id] && sk[id][ptr[id] - 1].A >= l)
			x.B += sk[id][-- ptr[id]].B;
		if (x.B)
			sk[id][ptr[id] ++] = x;
		last = (id + 1) * sq;
	}
	get_all(l / sq);
	for (int i = last; i <= l; ++ i)
		if (a[i] >= l)
			a[i] = r;
	build(l / sq);
}
 
int main(){
	InTheNameOfGod;
	
	cin >> n >> m;
	while (m --){
		int l, r;
		cin >> l >> r;
		L[r] = l;
	}
	cin >> q;
	for (int i = 0; i < q; ++ i){
		int x, y;
		cin >> x >> y;
		query[y].push_back({x, i});
	}
	for (int i = 1; i <= n; ++ i)
		a[i] = P[i] = i;
	for (int i = 0; i <= n; i += sq)
		build(i / sq);
	for (int i = 1; i <= n; ++ i){
		if (L[i])
			update(L[i], i);
		for (pii x : query[i]){
			get_all(x.A / sq);
			build(x.A / sq);
			ans[x.B] = a[x.A];
		}
	}
	for (int i = 0; i < q; ++ i)
		cout << ans[i] << endl;
	
	return 0;
}