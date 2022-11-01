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
 
const int xn = 2e5 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int MOD = 1e9 + 7;
const int TM = 3;
const int BASE = 257;
 
int n, m, a[xn], food, index;
pii num[xn];
set <int> vec[xn];
set <pii> st;
vector <int> ans;

void remove(int ind, int index){
	pii x = {- a[index] + SZ(vec[index]), index};
	vec[index].erase(ind);
	st.erase(x);
	-- x.A;
	if (SZ(vec[index])) st.insert(x);
}
 
int main(){
    InTheNameOfGod;
    
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    for (int i = 1; i <= m; ++ i){
    	cin >> num[i].A >> num[i].B;
    	vec[num[i].A].insert(i);
    	vec[num[i].B].insert(i);
	}
	for (int i = 1; i <= n; ++ i) if (SZ(vec[i])) st.insert({- a[i] + SZ(vec[i]), i});
	while (SZ(st)){
		food = st.begin() -> B;
		if (a[food] - SZ(vec[food]) < 0) kill("DEAD");
		index = *vec[food].begin();
		ans.push_back(index);
		remove(index, num[index].A);
		remove(index, num[index].B);
	}
	cout << "ALIVE" << endl;
	reverse(all(ans));
	for (int x : ans) cout << x << sep;
	cout << endl;
	
    return 0;
}