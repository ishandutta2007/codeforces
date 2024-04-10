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
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int SQ = 1200;
const int sq = 500 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int MOD = 1e9 + 7;
const int TM = 1e5;
const int BASE = 257;
 
int n, q, mx[sq], flag, a[xn], c[xn];
deque <int> dq[sq];
set <int> st[sq];
 
void update(int l, int r){
	flag = 0;
	if (l / SQ != r / SQ){
		flag = 1;
		for (int i = l - l % SQ + SQ - 1; i < r; i += SQ){
			int x = dq[i / SQ].back();
			dq[i / SQ].pop_back();
			st[i / SQ].erase(- a[x]);
			mx[i / SQ] = - *st[i / SQ].begin();
			dq[i / SQ + 1].push_front(x);
			st[i / SQ + 1].insert(- a[x]);
			mx[i / SQ + 1] = - *st[i / SQ + 1].begin();
		}
	}
	int x = dq[r / SQ][r % SQ + flag];
	st[r / SQ].erase(- a[x]);
	mx[r / SQ] = - *st[r / SQ].begin();
	for (int i = r % SQ - 1 + flag; i >= 0; -- i) dq[r / SQ][i + 1] = dq[r / SQ][i];
	dq[r / SQ].pop_front();
	dq[l / SQ].push_back(x);
	for (int i = SQ - 1; i > l % SQ; -- i) if (i < SZ(dq[l / SQ])) dq[l / SQ][i] = dq[l / SQ][i - 1];
	dq[l / SQ][l % SQ] = x;
	st[l / SQ].insert(- a[x]);
	mx[l / SQ] = - *st[l / SQ].begin();
}
int get_val(int id, int val){ for (int i = min(id * SQ + SQ - 1, n - 1); i >= id * SQ; -- i) if (a[dq[id][i % SQ]] > val) return i;}
int get(int ind, int val){
	for (int i = ind; i >= 0;){
		if (i % SQ == SQ - 1){
			if (mx[i / SQ] > val) return get_val(i / SQ, val);
			i -= SQ;
		}
		else{
			if (a[dq[i / SQ][i % SQ]] > val) return i;
			-- i;
		}
	}
	return - 1;
}
 
int main(){
    InTheNameOfGod;
    
    cin >> n;
    for (int i = 0; i < n; ++ i) cin >> a[i] >> c[i];
    for (int i = 0; i < n; ++ i){
		dq[i / SQ].push_back(i);
		st[i / SQ].insert(- a[i]);
		mx[i / SQ] = - *st[i / SQ].begin();
	}
    for (int i = 1; i < n; ++ i) update(max(i - c[i], get(i - 1, a[i]) + 1), i);
	for (int i = 0; i < n; ++ i) cout << dq[i / SQ][i % SQ] + 1 << sep;
	cout << endl;
    
    return 0;
}