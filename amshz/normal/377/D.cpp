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
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 3e5 + 10;
const int xm = - 20 + 10;
const int SQ = 320;
const int sq = 500 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int MOD = 1e9 + 7;
const int TM = 1e5;
const int BASE = 257;

int n, ans, lazy[xn << 2];
pii segment, seg[xn << 2];
pip a[xn];
vector <int> Q[2][xn];

void build(int id, int l, int r){
	if (r - l == 1){
		seg[id].B = l;
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
	seg[id] = seg[id << 1];
}
void shift(int id, int l, int r){
	if (!lazy[id]) return;
	seg[id].A += lazy[id];
	if (r - l > 1){
		lazy[id << 1] += lazy[id];
		lazy[id << 1 | 1] += lazy[id];
	}
	lazy[id] = 0;
}
void update(int id, int l, int r, int ql, int qr, int val){
	shift(id, l, r);
	if (qr <= l || r <= ql) return;
	if (ql <= l && r <= qr){
		lazy[id] += val;
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(id << 1, l, mid, ql, qr, val);
	update(id << 1 | 1, mid, r, ql, qr, val);
	seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
}

int main(){
    InTheNameOfGod;
    
    cin >> n;
    for (int i = 0; i < n; ++ i){
    	cin >> a[i].A >> a[i].B.A >> a[i].B.B;
    	Q[0][a[i].B.B].push_back(i);
    	Q[1][a[i].B.A].push_back(i);
	}
	build(1, 0, xn);
	for (int i = 1; i <= 3e5; ++ i){
		for (int x : Q[1][i]) update(1, 0, xn, a[x].A, i + 1, 1);
		if (seg[1].A > ans) ans = seg[1].A, segment = {seg[1].B, i};
		for (int x : Q[0][i]) update(1, 0, xn, a[x].A, a[x].B.A + 1, - 1);
	}
	cout << ans << endl;
	for (int i = 0; i < n; ++ i){
		if (a[i].A > segment.A) continue;
		if (a[i].B.B < segment.B) continue;
		if (segment.A > a[i].B.A) continue;
		if (segment.B < a[i].B.A) continue;
		cout << i + 1 << sep;
	}
	cout << endl;
    
    return 0;
}