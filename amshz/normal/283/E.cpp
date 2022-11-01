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

int m, a[xn], seg[xn << 2];
vector <int> vec[2][xn];
bool lazy[xn << 2];
ll ans, res, n;

void shift(int id, int l, int r){
	if (!lazy[id])
		return;
	seg[id] = r - l - seg[id];
	if (r - l > 1){
		lazy[id << 1] ^= 1;
		lazy[id << 1 | 1] ^= 1;
	}
	lazy[id] = false;
}
void update(int id, int l, int r, int ql, int qr){
	shift(id, l, r);
	if (qr <= l || r <= ql)
		return;
	if (ql <= l && r <= qr){
		lazy[id] ^= 1;
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(id << 1, l, mid, ql, qr);
	update(id << 1 | 1, mid, r, ql, qr);
	seg[id] = seg[id << 1] + seg[id << 1 | 1];	
}
int get(int id, int l, int r, int ql, int qr){
	shift(id, l, r);
	if (qr <= l || r <= ql)
		return 0;
	if (ql <= l && r <= qr)
		return seg[id];
	int mid = l + r >> 1;
	return get(id << 1, l, mid, ql, qr) + get(id << 1 | 1, mid, r, ql, qr);
}

int main(){
    InTheNameOfGod;
    
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i)
    	cin >> a[i];
    sort(a + 1, a + n + 1);
    while (m --){
    	int x, y, L, R;
    	cin >> x >> y;
    	int l = 0, r = n + 1;
    	while (r - l > 1){
    		int mid = l + r >> 1;
    		if (a[mid] < x) l = mid;
    		else r = mid;
		}
		if (r > n) continue;
		L = r;
		l = 0, r = n + 1;
		while (r - l > 1){
			int mid = l + r >> 1;
			if (a[mid] <= y) l = mid;
			else r = mid;
		}
		if (!l) continue;
		R = l;
		vec[0][L].push_back(R);
		vec[1][R].push_back(L);
	}
	ans = n * (n - 1) * (n - 2) / 6;
	for (int i = 1; i <= n; ++ i){
		for (int x : vec[0][i])
			update(1, 1, n + 1, i, x + 1);
		if (i - 1) update(1, 1, n + 1, i - 1, i);
		res = seg[1] - get(1, 1, n + 1, i, i + 1);
		res = res * (res - 1) / 2;
		ans -= res;
		for (int x : vec[1][i])
			update(1, 1, n + 1, x, i + 1);
	}
	cout << ans << endl;

    return 0;
}