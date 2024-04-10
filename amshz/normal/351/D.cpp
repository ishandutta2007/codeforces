# include <bits/stdc++.h>
 
using namespace std;
 
/*
// ordered_set 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/
 
typedef long long                         ll;
typedef long double                       ld;
typedef pair <int, int>                   pii;
typedef pair <pii, int>                   ppi;
typedef pair <pii, pii>                   pip;
 
# define A                                first
# define B                                second
# define endl                             '\n'
# define sep                              ' '
# define all(x)                           x.begin(), x.end()
# define Kill(x)                          return cout << x << endl, 0
# define SZ(x)                            int(x.size())
# define InTheNameOfGod                   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 998244353;
const int xn = 1e5 + 10;
const int xm = 4e5 + 10;
const int SQ = 320;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";

int n, q, num[xn], order[xn], ptr = 1, last[xn], T[xn], ans[xn], cnt[xn], mn[xn], mx[xn], oke[xn], lst[xn];
vector <int> adj[xn];
bool flag[xn];
pii Q[xn];

bool cmp(int i, int j){
	if (Q[i].A / SQ != Q[j].A / SQ) return Q[i].A / SQ < Q[j].A / SQ;
	return Q[i].B < Q[j].B;
}

void Solve(int ind){
	ind = max(ind, 1);
	memset(cnt, 0, sizeof cnt);
	memset(flag, true, sizeof flag);
	memset(oke, 0, sizeof oke);
	for (int i = 0; i <= 1e5; ++ i) mn[i] = inf, mx[i] = 0; 
	int ted = 0, t = 0;
	for (int i = ind; i <= n; ++ i){
		if (cnt[num[i]] == 0) ++ ted, ++ t;
		++ cnt[num[i]];
		mn[num[i]] = min(mn[num[i]], i);
		mx[num[i]] = i;
		t -= flag[num[i]];
		flag[num[i]] &= (last[i] <= mn[num[i]]);
		t += flag[num[i]];
		while (ptr <= q && Q[order[ptr]].B == i && Q[order[ptr]].A / SQ == ind / SQ){
			int j = order[ptr];
			ans[j] = ted;
			oke[j] = t;
			for (int k = ind; k < Q[j].A; ++ k){
				if (cnt[num[k]] == 1) -- ans[j];
				-- cnt[num[k]];
				if (k == mn[num[k]]){
					if (flag[num[k]] && mx[num[k]] < Q[j].A) -- oke[j];
					if (!flag[num[k]] && lst[last[mx[num[k]]]] < Q[j].A && mx[num[k]] >= Q[j].A) ++ oke[j];
				}
			}
			for (int k = ind; k < Q[j].A; ++ k) ++ cnt[num[k]];
			if (!oke[j]) ++ ans[j];
			++ ptr;
		}
	}
}

 
int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> num[i], adj[num[i]].push_back(i);
	cin >> q;
	for (int i = 1; i <= q; ++ i){
		int l, r;
		cin >> l >> r;
		Q[i] = {l, r};
		order[i] = i;
	}
	sort(order + 1, order + q + 1, cmp);
	for (int i = 1; i <= 1e5; ++ i){
		if (!SZ(adj[i])) continue;
		last[adj[i][0]] = 1;
		if (SZ(adj[i]) == 1) continue;
		last[adj[i][1]] = adj[i][0], T[adj[i][1]] = adj[i][1] - adj[i][0];
		lst[adj[i][1]] = adj[i][0];
		for (int j = 2; j < SZ(adj[i]); ++ j){
			T[adj[i][j]] = adj[i][j] - adj[i][j - 1];
			if (T[adj[i][j]] == T[adj[i][j - 1]]) last[adj[i][j]] = last[adj[i][j - 1]];
			else last[adj[i][j]] = adj[i][j - 1];
			lst[adj[i][j]] = adj[i][j - 1];
		}
	}
	for (int i = 0; i <= n; i += SQ) Solve(i);
	for (int i = 1; i <= q; ++ i) cout << ans[i] << endl;
	cout << endl;
	
	return 0;
}