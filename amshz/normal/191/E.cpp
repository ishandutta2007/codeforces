# include <bits/stdc++.h>
 
///*
// ordered_set 
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
//*/
 
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
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int SQ = 320;
const int sq = 500 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e14 + 10;
const int MOD = 1e9 + 7;
const int TM = 1e7;
const int BASE = 257;

ll n, k, num[xn], ted, seg[xn << 2], p[xn];
pll part[xn];

void modify(int id, int l, int r, int pos){
	if (r - l == 1){
		seg[id] = 1;
		return;
	}
	int mid = l + r >> 1;
	if (pos < mid) modify(id << 1, l, mid, pos);
	else modify(id << 1 | 1, mid, r, pos);
	seg[id] = seg[id << 1] + seg[id << 1 | 1];
}
int get(int id, int l, int r, int ql, int qr){
	if (qr <= l || r <= ql || ql == qr) return 0;
	if (ql <= l && r <= qr) return seg[id];
	int mid = l + r >> 1;
	return get(id << 1, l, mid, ql, qr) + get(id << 1 | 1, mid, r, ql, qr);
}
bool check(ll x){
	memset(seg, 0, sizeof seg);
	ted = 0;
	for (int i = 0; i <= n; ++ i){
		int l = - 1, r = n + 1;
		while (r - l > 1){
			int mid = l + r >> 1;
			if (part[mid].A <= part[p[i]].A - x) l = mid;
			else r = mid;
		}
		ted += get(1, 0, n + 1, 0, r);
		modify(1, 0, n + 1, p[i]);
	}
	return ted >= k;
}

int main(){
    InTheNameOfGod;
    
    cin >> n >> k;
    for (int i = 1; i <= n; ++ i) cin >> num[i];
    for (int i = 1; i <= n; ++ i) part[i] = {part[i - 1].A + num[i], i};
	sort(part, part + n + 1);
	for (int i = 0; i <= n; ++ i) p[part[i].B] = i;
    ll l = - INF, r = INF;
    while (r - l > 1){
    	ll mid = l + r >> 1;
    	if (check(mid)) l = mid;
    	else r = mid;
	}
	cout << l << endl;
    
    return 0;
}