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
const int xm = 12;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;
 
struct node{
	int l, r, ans;
	bool istohi = false;
};
 
int n, m, q, a[xn][xm], last;
pii dp[xn][xm][xm];
vector <pii> vec;
node seg[xn << 2], tohi;
 
node merge(node v, node u){
	if (v.istohi) return u;
	if (u.istohi) return v;
	node w;
	w.l = v.l, w.r = u.r;
	w.ans = v.ans + u.ans;
	for (int j = 1; j <= n; ++ j){
		if (a[u.l - 1][j] != a[u.l][j]) continue;
		bool f = true;
		for (int k = 1; k < j; ++ k){
			if (a[u.l - 1][k] != a[u.l][k]) continue;
			if (a[u.l][k] != a[u.l][j]) continue;
			if (dp[u.l - 1][k][j].A < v.l) continue;
			if (dp[u.l][k][j].B >= u.r) continue;
			f = false;
		}
		w.ans -= f;
	}
	return w;
}
void build(int id, int l, int r){
	seg[id].l = l, seg[id].r = r;
	if (r - l == 1){
		seg[id].ans = 0;
		for (int j = 1; j <= n; ++ j)
			seg[id].ans += (a[l][j] != a[l][j - 1]);
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
	seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
}
node get(int id, int l, int r, int ql, int qr){
	if (qr <= l || r <= ql)
		return tohi;
	if (ql <= l && r <= qr)
		return seg[id];
	int mid = l + r >> 1;
	return merge(get(id << 1, l, mid, ql, qr), get(id << 1 | 1, mid, r, ql, qr));
}
 
int main(){
	InTheNameOfGod;
	
	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j)
			cin >> a[j][i];
	for (int i = 1; i <= m; ++ i){
		vec.clear(), last = 1;
		for (int j = 1; j <= n; ++ j){
			if (j - 1 && a[i][j] != a[i][j - 1]){
				vec.push_back({last, j});
				last = j;
			}
		}
		vec.push_back({last, n + 1});
		for (int p1 = 0; p1 < SZ(vec); ++ p1){
			for (int p2 = p1 + 1; p2 < SZ(vec); ++ p2){
				if (a[i][vec[p1].A] != a[i][vec[p2].A])
					continue;
				int mx = 0;
				for (int j = vec[p1].A; j < vec[p1].B; ++ j){
					if (a[i][j] != a[i - 1][j]) continue;
					for (int k = vec[p2].A; k < vec[p2].B; ++ k){
						if (a[i][k] != a[i - 1][k]) continue;
						mx = max(mx, dp[i - 1][j][k].A);
					}
				}
				for (int j = vec[p1].A; j < vec[p1].B; ++ j)
					for (int k = vec[p2].A; k < vec[p2].B; ++ k)
						dp[i][j][k].A = mx;
			}
			for (int j = vec[p1].A; j < vec[p1].B; ++ j)
				for (int k = j + 1; k < vec[p1].B; ++ k)
					dp[i][j][k].A = i;
		}
	}
	for (int i = m; i >= 1; -- i){
		vec.clear(), last = 1;
		for (int j = 1; j <= n; ++ j){
			if (j - 1 && a[i][j] != a[i][j - 1]){
				vec.push_back({last, j});
				last = j;
			}
		}
		vec.push_back({last, n + 1});
		for (int p1 = 0; p1 < SZ(vec); ++ p1){
			for (int p2 = p1 + 1; p2 < SZ(vec); ++ p2){
				if (a[i][vec[p1].A] != a[i][vec[p2].A]) continue;
				int mn = inf;
				for (int j = vec[p1].A; j < vec[p1].B; ++ j){
					if (a[i][j] != a[i + 1][j]) continue;
					for (int k = vec[p2].A; k < vec[p2].B; ++ k){
						if (a[i][k] != a[i + 1][k]) continue;
						mn = min(mn, dp[i + 1][j][k].B);
					}
				}
				for (int j = vec[p1].A; j < vec[p1].B; ++ j)
					for (int k = vec[p2].A; k < vec[p2].B; ++ k)
						dp[i][j][k].B = mn;
			}
			for (int j = vec[p1].A; j < vec[p1].B; ++ j)
				for (int k = j + 1; k < vec[p1].B; ++ k)
					dp[i][j][k].B = i;
		}
	}
	tohi.istohi = true;
	build(1, 1, m + 1);
	while (q --){
		int l, r;
		cin >> l >> r;
		cout << get(1, 1, m + 1, l, r + 1).ans << endl;
	}
	
	return 0;
}