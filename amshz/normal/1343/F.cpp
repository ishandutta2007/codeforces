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
 
const int xn = 5e2 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int MOD = 1e9 + 7;
const int TM = 3;
const int BASE = 257;
 
int qq, n, k[xn], ans[xn], cnt[xn], ptr, num[xn];
set <int> segment[xn], vec[xn];
set <pii> st;
bool mark[xn], flag;

bool check(int root){
	ans[1] = root;
	for (int i = 2; i <= n; ++ i){
		segment[i].clear();
		for (int x : vec[i]) if (x != root) segment[i].insert(x);
	}
	st.clear();
	for (int i = 2; i <= n; ++ i) st.insert({SZ(segment[i]), i});
	ptr = 2;
	for (int i = 2; i <= n; ++ i) mark[i] = false;
	while (SZ(st)){
		int index = st.begin() -> B;
		st.erase(st.begin());
		if (SZ(segment[index]) != 1) return false;
		mark[index] = true;
		num[ptr] = index;
		int x = *segment[index].begin();
		ans[ptr ++] = x;
		for (int i = 2; i <= n; ++ i){
			st.erase({SZ(segment[i]), i});
			segment[i].erase(x);
			if (!mark[i]) st.insert({SZ(segment[i]), i});
		}
	}
	for (int i = 2; i <= n; ++ i){
		int index = num[i];
		st.clear();
		for (int j = i - k[index] + 1; j <= i; ++ j) st.insert({ans[j], j});
		segment[i].clear();
		for (int x : vec[index]) segment[i].insert(x);
		flag = true;
		while (SZ(st)){
			int x = st.begin() -> A;
			int y = *segment[i].begin();
			flag &= x == y;
			st.erase(st.begin());
			segment[i].erase(segment[i].begin());
		}
		if (!flag) return false;
	}
	return true;
}
 
int main(){
    InTheNameOfGod;
    
    cin >> qq;
    while (qq --){
    	cin >> n;
    	for (int i = 2; i <= n; ++ i){
    		cin >> k[i];
    		vec[i].clear();
    		for (int j = 0; j < k[i]; ++ j){
    			int x; cin >> x;
    			vec[i].insert(x);
			}
		}
		for (int i = 1; i <= n; ++ i) if (check(i)) break;
		for (int i = 1; i <= n; ++ i) cout << ans[i] << sep;
		cout << endl;
	}
	
    return 0;
}