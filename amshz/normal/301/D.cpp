# include <bits/stdc++.h>
 
using namespace std;

/*
// ordered_set 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/
 
typedef long long          ll;
typedef long double        ld;
typedef pair <int, int>    pii;
typedef pair <pii, int>    ppi;
typedef pair <pii, pii>    pip;
 
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
const int xm = -20 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;

ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";

int n, qq, num[xn], ans[xn], pos[xn], Seg[xn * 4];
vector <pii> Q[xn];
vector <int> vec[xn];

void Update(int id, int L, int R, int ind){
	if (R - L == 1){
		++ Seg[id];
		return;
	}
	int Mid = (L + R) / 2;
	if (ind < Mid) Update(id * 2, L, Mid, ind);
	else Update(id * 2 + 1, Mid, R, ind);
	Seg[id] = Seg[id * 2] + Seg[id * 2 + 1];
}
int Get(int id, int L, int R, int Ql, int Qr){
	if (Qr <= L || R <= Ql) return 0;
	if (Ql <= L && R <= Qr) return Seg[id];
	int Mid = (L + R) / 2;
	return Get(id * 2, L, Mid, Ql, Qr) + Get(id * 2 + 1, Mid, R, Ql, Qr);
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> qq;
	for (int i = 1; i <= n; ++ i) cin >> num[i], pos[num[i]] = i;
	for (int i = 1; i <= qq; ++ i){
		int l, r;
		cin >> l >> r;
		Q[l].push_back({r, i});
	}
	for (int i = 1; i <= n; ++ i){
		for (int j = i; j <= n; j += i){
			if (pos[i] < pos[j]) vec[pos[i]].push_back(pos[j]);
			else vec[pos[j]].push_back(pos[i]);
		}
	}
	for (int i = n; i >= 1; -- i){
		for (int x : vec[i]) Update(1, 0, xn, x);
		for (pii q : Q[i]) ans[q.B] = Get(1, 0, xn, i, q.A + 1);
	}
	for (int i = 1; i <= qq; ++ i) cout << ans[i] << endl;
	cout << endl;
	
	return 0;
}