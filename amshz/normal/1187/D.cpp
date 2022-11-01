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
const int xn = 3e5 + 10;
const int xm = -20 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;

ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";

int qq, n, A[xn], B[xn], num[xn], seg[xn * 4];
vector <int> adj[2][xn];
bool flag;

void Build(int id, int L, int R){
	if (R - L == 1){
		seg[id] = 0;
		return;
	}
	int Mid = (L + R) / 2;
	Build(id * 2, L, Mid);
	Build(id * 2 + 1, Mid, R);
	seg[id] = 0;
}
void Update(int id, int L, int R, int ind, int val){
	if (R - L == 1){
		seg[id] = max(seg[id], val);
		return;
	}
	int Mid = (L + R) / 2;
	if (ind < Mid) Update(id * 2, L, Mid, ind, val);
	else Update(id * 2 + 1, Mid, R, ind, val);
	seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
}
int Get(int id, int L, int R, int Ql, int Qr){
	if (Qr <= L || R <= Ql) return 0;
	if (Ql <= L && R <= Qr) return seg[id];
	int Mid = (L + R) / 2;
	return max(Get(id * 2, L, Mid, Ql, Qr), Get(id * 2 + 1, Mid, R, Ql, Qr));
}

void Solve(){
	for (int i = 1; i <= n; ++ i) adj[0][i].clear(), adj[1][i].clear();
	flag = true;
	Build(1, 0, n + 1);
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> A[i], adj[0][A[i]].push_back(i);
	for (int i = 1; i <= n; ++ i) cin >> B[i], adj[1][B[i]].push_back(i);
	for (int i = 1; i <= n; ++ i){
		if (SZ(adj[0][i]) != SZ(adj[1][i])){
			cout << "NO" << endl;
			return;
		}
		for (int j = 0; j < SZ(adj[0][i]); ++ j)
			num[adj[0][i][j]] = adj[1][i][j];
	}
	for (int i = 1; i <= n; ++ i){
		flag &= (num[i] > Get(1, 0, n + 1, 1, A[i]));
		Update(1, 0, n + 1, A[i], num[i]);
	}
	if (flag) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main(){
	InTheNameOfGod;
	
	cin >> qq;
	while (qq --) Solve();
	
	return 0;
}