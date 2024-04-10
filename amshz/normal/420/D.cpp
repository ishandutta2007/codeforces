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
 
const int xn = 2e6 + 10;
const int xm = - 20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int TM = 3;
const int base = 257;

int n, m, a[xn], ans[xn], seg[xn << 2], lazy[xn << 2], num[xn], p[xn];
deque <int> dq;

void shift(int id, int l, int r){
	if (!lazy[id]) return;
	seg[id] += lazy[id];
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
int get(int id, int l, int r, int pos){
	//shift(id, l, r);
	if (r - l == 1) return l;
	int mid = l + r >> 1;
	shift(id << 1, l, mid);
	shift(id << 1 | 1, mid, r);
	if (pos <= seg[id << 1]) return get(id << 1, l, mid, pos);
	return get(id << 1 | 1, mid, r, pos);
}

int main(){
    InTheNameOfGod;
    
    cin >> n >> m;
    for (int i = m + 1; i <= n + m; ++ i){
    	a[i] = 1;
    	update(1, 1, n + m + 1, i, n + m + 1, 1);
	}
    for (int i = 1; i <= m; ++ i){
    	int x, y;
    	cin >> x >> y;
    	int ind = get(1, 1, n + m + 1, y);
		if (!p[x]) ans[ind - m] = x;
    	if (p[x] && p[x] != ind) kill(- 1);
    	if (num[ind] && num[ind] != x) kill(- 1);
		update(1, 1, n + m + 1, ind, n + m + 1, - 1);
		update(1, 1, n + m + 1, m - i + 1, n + m + 1, 1);
		a[ind] = num[ind] = 0;
		a[m - i + 1] = 1;
		num[m - i + 1] = x;
		p[x] = m - i + 1;
	}
	for (int i = 1; i <= n; ++ i) if (!p[i]) dq.push_back(i);
	for (int i = 1; i <= n; ++ i){
		if (ans[i]) continue;
		ans[i] = dq.front();
		dq.pop_front();
	}
	for (int i = 1; i <= n; ++ i) cout << ans[i] << sep;
	cout << endl;

    return 0;
}