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
 
const int xn = 1.5e6 + 10;
const int xm = - 20;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, ptr, seg[xn << 2], ord[xn], a[3][xn], ans;
vector <pip> compress;
vector <int> query[xn];

void modify(int id, int l, int r, int pos, int val){
	seg[id] = max(seg[id], val);
	if (r - l == 1)
		return;
	int mid = l + r >> 1;
	if (pos < mid) modify(id << 1, l, mid, pos, val);
	else modify(id << 1 | 1, mid, r, pos, val);
}
int get (int id, int l, int r, int ql, int qr){
	if (qr <= l || r <= ql)
		return 0;
	if (ql <= l && r <= qr)
		return seg[id];
	int mid = l + r >> 1;
	return max(get(id << 1, l, mid, ql, qr), get(id << 1 | 1, mid, r, ql, qr));
}

int main(){
	InTheNameOfGod;
    
    cin >> n;
    for (int i = 1; i <= n; ++ i)
    	cin >> a[0][i];
    for (int i = 1; i <= n; ++ i)
    	cin >> a[1][i];
    for (int i = 1; i <= n; ++ i)
    	cin >> a[2][i];
    for (int i = 1; i <= n; ++ i){
    	compress.push_back({a[0][i], {0, i}});
    	compress.push_back({a[1][i], {1, i}});
    	compress.push_back({a[2][i], {2, i}});
    	ord[i] = i;
	}
	sort(all(compress));
	for (int i = 0; i < SZ(compress); ++ i){
		if (!i || compress[i].A != compress[i - 1].A) ++ ptr;
		a[compress[i].B.A][compress[i].B.B] = ptr;
	}
	for (int i = 1; i <= n; ++ i)
		query[a[0][i]].push_back(i);
	for (int i = ptr; i >= 1; -- i){
		for (int x : query[i])
			ans += get(1, 1, ptr + 1, a[1][x] + 1, ptr + 1) > a[2][x];
		for (int x : query[i])
			modify(1, 1, ptr + 1, a[1][x], a[2][x]);
	}
	cout << ans << endl;
	
    return 0;
}