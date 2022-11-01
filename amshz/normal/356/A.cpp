# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 3e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, m, ptr, ans[xn];
pii seg[xn << 2];

void update(int id, int l, int r, int ql, int qr, int x){
	if (qr <= l || r <= ql || qr <= ql)
		return;
	if (ql <= l && r <= qr){
		seg[id] = min(seg[id], {ptr, x});
		return;
	}
	int mid = l + r >> 1;
	update(id << 1, l, mid, ql, qr, x);
	update(id << 1 | 1, mid, r, ql, qr, x);
}
void build(int id, int l, int r){
	if (r - l == 1){
		ans[l] = seg[id].B;
		return;
	}
	int mid = l + r >> 1;
	seg[id << 1] = min(seg[id << 1], seg[id]);
	seg[id << 1 | 1] = min(seg[id << 1 | 1], seg[id]);
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
}
 
int main(){
	InTheNameOfGod;
	
	cin >> n >> m;
	for (int i = 0; i < xn << 2; ++ i)
		seg[i].A = inf;
	for (int i = 1; i <= m; ++ i){
		int l, r, x;
		cin >> l >> r >> x;
		++ ptr;
		update(1, 1, n + 1, l, x, x);
		update(1, 1, n + 1, x + 1, r + 1, x);
	}
	build(1, 1, n + 1);
	for (int i = 1; i <= n; ++ i)
		cout << ans[i] << sep;
	cout << endl;
	
	return 0;
}