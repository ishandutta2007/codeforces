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
const int SQ = 850;
const int sq = 710 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e14 + 10;
const int MOD = 1e9 + 7;
const int TM = 1e7;
const int BASE = 257;

int n, q, num[xn];
set <pii> st[xn];
ll lazy[xn];

void add(int id, int x){
	if (st[id].lower_bound({x, 0}) == st[id].end()){
		st[id].insert({x, 1});
		return;
	}
	pii s = *st[id].lower_bound({x, 0});
	if (s.A != x){
		st[id].insert({x, 1});
		return;
	}
	st[id].erase(s);
	++ s.B;
	st[id].insert(s);
}
void remove(int id, int x){
	pii s = *st[id].lower_bound({x, 0});
	st[id].erase(s);
	-- s.B;
	if (s.B) st[id].insert(s);
}
void update(int l, int r, int x){
	for (int i = l; i <= r;){
		if (i % SQ == 0 && i + SQ - 1 <= r){
			lazy[i / SQ] += x;
			i += SQ;
		}
		else{
			if (num[i] >= inf){
				++ i;
				continue;
			}
			remove(i / SQ, num[i]);
			num[i] += x;
			if (num[i] < inf) add(i / SQ, num[i]);
			++ i;
		}
	}
}
int getmin(int id, int x){ for (int i = id * SQ; i < id * SQ + SQ; ++ i) if (num[i] == x) return i;}
int getmax(int id, int x){ for (int i = id * SQ + SQ - 1; i >= id * SQ; -- i) if (num[i] == x) return i;}
int Get(int id, int x){
	int mn = - 1, mx = 0;
	for (int i = id * SQ; i < id * SQ + SQ; ++ i){
		if (num[i] == x){
			mx = i;
			if (mn == - 1) mn = i;
		}
	}
	return mx - mn;
}
int get(int y){
	int mn = inf, mx = - 1;
	for (int i = 0; i < n; i += SQ){
		if (lazy[i / SQ] > y) continue;
		if (st[i / SQ].lower_bound({y - lazy[i / SQ], 0}) == st[i / SQ].end()) continue;
		pii x = *st[i / SQ].lower_bound({y - lazy[i / SQ], 0});
		if (x.A != y - lazy[i / SQ]) continue;
		mn = min(mn, i / SQ);
		mx = max(mx, i / SQ);
	}
	if (mx == - 1) return - 1;
	if (mx == mn) return Get(mn, y - lazy[mn]);
	return getmax(mx, y - lazy[mx]) - getmin(mn, y - lazy[mn]);
}

int main(){
    InTheNameOfGod;
    
    cin >> n >> q;
    for (int i = 0; i < n; ++ i){
    	cin >> num[i];
    	add(i / SQ, num[i]);
	}
	while (q --){
		ll t, l, r, x, y;
		cin >> t;
		if (t == 1){
			cin >> l >> r >> x;
			update(l - 1, r - 1, x);
		}
		else{
			cin >> y;
			cout << get(y) << endl;
		}
	}
    
    return 0;
}