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
 
const int xn = 1e6 + 10;
const int xm = - 20 + 10;
const int SQ = 320;
const int sq = 500 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int MOD = 1e9 + 7;
const int TM = 1e5;
const int BASE = 257;

int n, a[xn], ptr;
pll b[xn];
ll ans, seg[xn << 2];
unordered_map <int, int> mp;
vector <int> compress;

void modify(int id, int l, int r, int pos){
	if (r - l == 1){
		++ seg[id];
		return;
	}
	int mid = l + r >> 1;
	if (pos < mid) modify(id << 1, l, mid, pos);
	else modify(id << 1 | 1, mid, r, pos);
	seg[id] = seg[id << 1] + seg[id << 1 | 1];
}
ll get(int id, int l, int r, int ql, int qr){
	if (qr <= l || r <= ql) return 0;
	if (ql <= l && r <= qr) return seg[id];
	int mid = l + r >> 1;
	return get(id << 1, l, mid, ql, qr) + get(id << 1 | 1, mid, r, ql, qr);
}

int main(){
    InTheNameOfGod;
    
    cin >> n;
    for (int i = 1; i <= n; ++ i){
    	cin >> a[i];
    	compress.push_back(a[i]);
	}
	Sort(compress);
	for (int i = 0; i < n; ++ i){
		if (i && compress[i] == compress[i - 1]) continue;
		mp[compress[i]] = ptr ++;
	}
	for (int i = 1; i <= n; ++ i) a[i] = mp[a[i]];
	for (int i = 1; i <= n; ++ i){
		b[i].A = get(1, 0, ptr, a[i] + 1, ptr);
		modify(1, 0, ptr, a[i]);
	}
	memset(seg, 0, sizeof seg);
	for (int i = n; i >= 1; -- i){
		b[i].B = get(1, 0, ptr, 0, a[i]);
		modify(1, 0, ptr, a[i]);
	}
	for (int i = 1; i <= n; ++ i) ans += b[i].A * b[i].B;
	cout << ans << endl;
    
    return 0;
}