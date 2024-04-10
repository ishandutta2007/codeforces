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
 
const ll md = 1e9 + 7;//998244353;
const int xn = 2e5 + 10;
const int xm = -20 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";

int n, k, num[xn], c[xn], seg[xn * 4];
vector <int> vec[xn];

void Build(int id, int L, int R){
	if (R - L == 1){
		seg[id] = c[L];
		return;
	}
	int Mid = (L + R) / 2;
	Build(id * 2, L, Mid);
	Build(id * 2 + 1, Mid, R);
	seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}
int get(int id, int L, int R, int Ql, int Qr){
	if (Qr <= L || R <= Ql) return inf;
	if (Ql <= L && R <= Qr) return seg[id];
	int Mid = (L + R) / 2;
	return min(get(id * 2, L, Mid, Ql, Qr), get(id * 2 + 1, Mid, R, Ql, Qr));
}

bool Check(int x){
	for (int i = 0; i < x; ++ i) vec[i].clear();
	for (int i = 0; i < n; ++ i) vec[i % x].push_back(num[i]);
	for (int i = 0; i < x; ++ i){
		int t = SZ(vec[i]);
		int last = 0;
		for (int j = 0; j < t; ++ j){
			if (get(1, 1, k + 1, last + 1, vec[i][j] + 1) < t - j) return false;
			last = vec[i][j];
		}
	}
	return true;
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> k;
	for (int i = 0; i < n; ++ i) cin >> num[i];
	for (int i = 1; i <= k; ++ i) cin >> c[i];
	Build(1, 1, k + 1);
	sort(num, num + n);
	int L = 0, R = n, Mid;
	while (R - L > 1){
		Mid = (L + R) / 2;
		if (Check(Mid)) R = Mid;
		else L = Mid;
	}
	cout << R << endl;
	Check(R);
	for (int i = 0; i < R; ++ i){
		cout << SZ(vec[i]) << sep;
		for (int x : vec[i]) cout << x << sep;
		cout << endl;
	}
	
	return 0;
}