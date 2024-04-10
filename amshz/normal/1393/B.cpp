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

int qq, n, num[xn], cnt[xn];
set <pii> st;

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
bool check(){
	pii x = *st.begin();
	st.erase(x);
	pii y = *st.begin();
	st.erase(y);
	pii z = *st.begin();
	st.erase(z);
	st.insert(x);
	st.insert(y);
	st.insert(z);
	if (- x.A > 7) return true;
	if (- y.A < 2 || - x.A < 4) return false;
	if (- z.A > 1) return true;
	if (- x.A > 5) return true;
	if (- x.A > 3 && - y.A > 3) return true;
	return false;
}

int main(){
    InTheNameOfGod;
    
    for (int i = 1; i <= 1e5; ++ i) st.insert({0, i});
    cin >> n;
    for (int i = 1; i <= n; ++ i){
    	cin >> num[i];
    	add(num[i]);
	}
	cin >> qq;
	while (qq --){
		int x;
		char c;
		cin >> c >> x;
		if (c == '+') add(x);
		else remove(x);
		if (check()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
    
    return 0;
}