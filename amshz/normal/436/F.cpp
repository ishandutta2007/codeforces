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
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, ptr, lazy[xn], last;
ll b[xn], part[xn], w, mx;
pll a[xn], seg[xn], ans[xn];
vector <pii> vec, query[xn];

ll f(ll x, ll y){ return b[x] + x * y;}

void add(int ind){
	int res = 1;
	for (int i = 0; i < SZ(vec); ++ i){
		if (vec[i].A < a[ind].B)
			++ vec[i].B;
		else
			++ res;
	}
	vec.push_back({a[ind].B, res});
	for (pii x : vec)
		query[x.A].push_back({x.B, ind});
	query[xn - 1].push_back({0, ind});
}
void shift(int id, int l, int r){
	if (!lazy[id])
		return;
	seg[id].A = lazy[id];
	seg[id].B = lazy[id];
	if (r - l > 1){
		lazy[id << 1] = lazy[id];
		lazy[id << 1 | 1] = lazy[id];
	}
	lazy[id] = 0;
}
void update(int id, int l, int r, int ind){
	shift(id, l, r);
	if (f(seg[id].B, r - 1) >= f(ind, r - 1))
		return;
	if (f(seg[id].A, l) < f(ind, l)){
		lazy[id] = ind;
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(id << 1, l, mid, ind);
	update(id << 1 | 1, mid, r, ind);
	seg[id].A = seg[id << 1].A;
	seg[id].B = seg[id << 1 | 1].B;
}
int get(int id, int l, int r, int pos){
	shift(id, l, r);
	if (r - l == 1)
		return seg[id].A;
	int mid = l + r >> 1;
	if (pos < mid) return get(id << 1, l, mid, pos);
	return get(id << 1 | 1, mid, r, pos);
}
void build(){
	for (int i = 0; i < xn; ++ i)
		seg[i].A = seg[i].B = lazy[i] = 0;
	for (int i = 1; i < xn; ++ i){
		update(1, 0, sq + 1, i);
		for (pii x : query[i]){
			int y = get(1, 0, sq + 1, x.A);
			if (f(y, x.A) > ans[x.B].A)
				ans[x.B] = {f(y, x.A), y};
		}
		query[i].clear();
		part[i] = 0;
	}
	for (pii x : vec)
		++ part[x.A];
	for (int i = xn - 2; i >= 1; -- i){
		part[i] += part[i + 1];
		b[i] += part[i] * ll(i);
	}
	vec.clear();
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> w;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i].B >> a[i].A;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++ i){
		add(i);
		if (i % sq == 0 || i == n)
			build();
		mx = max(mx, a[i].A + 2);
	}
	for (int i = 0; i < mx; ++ i){
		while (ptr < n && a[ptr + 1].A < i)
			++ ptr;
		cout << ll(n - ptr) * w * ll(i)  + ans[ptr].A << sep << ans[ptr].B << endl;
	}
	
	return 0;
}