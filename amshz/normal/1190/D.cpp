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
const int xn = 2e5 + 10;
const int xm = 20;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";

int n, ptr;
ll ans, last, cnt[xn], seg[xn * 4];
vector <int> adj[xn], vec;
pii num[xn];
unordered_map <int, int> mp;

void update(int id, int L, int R, int ind){
	if (R - L == 1){
		++ cnt[ind];
		seg[id] = (cnt[L] > 0);
		return;
	}
	int Mid = (L + R) / 2;
	if (ind < Mid) update(id * 2, L, Mid, ind);
	else update(id * 2 + 1, Mid, R, ind);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
ll get(int id, int L, int R, int Ql, int Qr){
	if (Qr <= L || R <= Ql) return 0;
	if (Ql <= L && R <= Qr) return seg[id];
	int Mid = (L + R) / 2;
	return get(id * 2, L, Mid, Ql, Qr) + get(id * 2 + 1, Mid, R, Ql, Qr);
}

void Compress(){
	for (int i = 0; i < n; ++ i) vec.push_back(num[i].B);
	sort(all(vec));
	for (int i = 0; i < n; ++ i){
		if (i && vec[i] == vec[i - 1]) continue;
		mp[vec[i]] = ++ ptr;
	}
	for (int i = 0; i < n; ++ i) num[i].B = mp[num[i].B];
	mp.clear();	
	ptr = 0;
	vec.clear();
	for (int i = 0; i < n; ++ i) vec.push_back(num[i].A);
	sort(all(vec));
	for (int i = 0; i < n; ++ i){
		if (i && vec[i] == vec[i - 1]) continue;
		mp[vec[i]] = ++ ptr;
	}
	for (int i = 0; i < n; ++ i) num[i].A = mp[num[i].A];
	for (int i = 0; i < n; ++ i) adj[num[i].B].push_back(num[i].A);
}

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 0; i < n; ++ i) cin >> num[i].A >> num[i].B;
	Compress();
	for (int i = n; i >= 1; -- i){
		sort(all(adj[i]));
		for (int x : adj[i]) update(1, 0, xn, x);
		last = 0;
		for (ll x : adj[i]) 	ans += get(1, 0, xn, last + 1, x + 1) * get(1, 0, xn, x, xn), last = x;
	}
	cout << ans << endl;
	
	return 0;
}