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
const int xm = - 20;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, k, a[xn], last[xn], q, ans;
vector <int> adj[xn], vec[xn << 2];

void build(int id, int l, int r){
	if (r - l == 1){
		vec[id].push_back(last[l]);
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
	for (int x : vec[id << 1])
		vec[id].push_back(x);
	for (int x : vec[id << 1 | 1])
		vec[id].push_back(x);
	sort(all(vec[id]));
}
int get(int id, int l, int r, int ql, int qr){
	if (qr <= l || r <= ql)
		return 0;
	if (ql <= l && r <= qr){
		int L = - 1, R = r - l, Mid;
		while (R - L > 1){
			Mid = L + R >> 1;
			if (vec[id][Mid] < ql) L = Mid;
			else R = Mid;
		}
		return R;
	}
	int mid = l + r >> 1;
	return get(id << 1, l, mid, ql, qr) + get(id << 1 | 1, mid, r, ql, qr);
}

int main(){
	InTheNameOfGod;
    
    cin >> n >> k;
    for (int i = 1; i <= n; ++ i){
    	cin >> a[i];
    	adj[a[i]].push_back(i);
	}
	for (int i = 1; i < xn; ++ i)
		for (int j = k; j < SZ(adj[i]); ++ j)
			last[adj[i][j]] = adj[i][j - k];
	build(1, 1, n + 1);
	cin >> q;
	while (q --){
		int l, r;
		cin >> l >> r;
		l = (l + ans) % n + 1;
		r = (r + ans) % n + 1;
		if (r < l) swap(l, r);
		ans = get(1, 1, n + 1, l, r + 1);
		cout << ans << endl;
	}
	
    return 0;
}