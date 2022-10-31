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
 
const int xn = 5e5 + 10;
const int xm = - 20;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, k, a[xn], ptr, lst;
pii seg[xn << 2];
bitset <xn> flag;
vector <pii> compress;

void modify(int pos, pii val){
	pos += ptr;
	while (pos){
		seg[pos] = max(seg[pos], val);
		pos >>= 1;
	}
}
pii get(int l, int r){
	pii x = {0, 0};
	l += ptr, r += ptr;
	while (l < r){
		if ((l & 1))
			x = max(x, seg[l ++]);
		if ((r & 1))
			x = max(x, seg[-- r]);
		l >>= 1;
		r >>= 1;
	}
	return x;
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i){
		cin >> a[i];
		a[i] -= i;
		compress.push_back({a[i], i});
	}
	for (int i = 0; i < k; ++ i){
		int x;
		cin >> x;
		flag[x] = 1;
	}
	sort(all(compress));
	for (int i = 0; i < SZ(compress); ++ i){
		ptr += (i && compress[i].A != compress[i - 1].A);
		a[compress[i].B] = ptr;
	}
	++ ptr;
	for (int i = 1; i <= n; ++ i){
		pii x = get(0, a[i] + 1);
		if (x.A != lst)
			continue;
		++ x.B;
		lst += flag[i], x.A += flag[i];
		modify(a[i], x);
	}
	if (seg[1].A < k)
		kill(- 1);
	cout << n - seg[1].B << endl;
	
	return 0;
}