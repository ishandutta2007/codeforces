# include <bits/stdc++.h>
 
///*
// ordered_set 
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
//*/
 
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
const int SQ = 320;
const int sq = 500 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e14 + 10;
const int MOD = 1e9 + 7;
const int TM = 1e7;
const int BASE = 257;

int qq, n, num[xn], a[xn], ptr, last[xn], cnt[xn];
set <pii> st;
vector <pii> vec;

void add(int x){
	st.erase({- cnt[x], x});
	++ cnt[x];
	st.insert({- cnt[x], x});
}
void remove(int x){
	st.erase({- cnt[x], x});
	-- cnt[x];
	st.insert({- cnt[x], x});
}
bool check(int k){
	st.clear();
	for (int i = 1; i <= n; ++ i) st.insert({0, i}), cnt[i] = 0;
	for (int i = 1; i <= n; ++ i) add(num[i]);
	ptr = 0;
	while (true){
		int ted = 0;
		vec.clear();
		for (pii x : st){
			if (ted == k) break;
			if (x.A == 0) break;
			vec.push_back(x);
			++ ted;
		}
		for (pii x : vec) a[++ ptr] = x.B;
		for (pii x : vec) remove(x.B);
		if (ptr == n) break;
	}
	for (int i = 1; i <= n; ++ i) last[i] = - inf;
	for (int i = 1; i <= n; ++ i){
		if (i - last[a[i]] < k) return false;
		last[a[i]] = i;
	}
	return true;
}

int main(){
    InTheNameOfGod;
    
    cin >> qq;
    while (qq --){
    	cin >> n;
    	for (int i = 1; i <= n; ++ i) cin >> num[i];
    	int l = 0, r = n;
    	while (r - l > 1){
    		int mid = l + r >> 1;
    		if (check(mid)) l = mid;
    		else r = mid;
		}
		cout << l - 1 << endl;
	}
    
    return 0;
}