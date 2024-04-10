//khodaya khodet komak kon
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
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e6 + 10;
//const int xm = 18;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;
 
int n, A[xn], B[xn], rev[xn], d[xn];
int fact[xn], ifact[xn], ans;
vector <int> dp[xn], adj[xn];
 
void NTT(int *A, bool inv, int lg){
	int n = (1 << lg);
	for (int i = 0; i < (1 << lg); ++ i)
		if (rev[i] < i)
			swap(A[i], A[rev[i]]);
	for (int ln = 1; ln < n; ln <<= 1){
		int w = power(3, mod / 2 / ln, mod);
		if (inv)
			w = power(w, mod - 2, mod);
		for (int i = 0; i < n; i += ln + ln){
			int wn = 1;
			for (int j = i; j < i + ln; ++ j){
				int x = A[j], y = 1ll * A[j + ln] * wn % mod;
				A[j] = (x + y) % mod;
				A[j + ln] = (x - y + mod) % mod;
				wn = 1ll * wn * w % mod;
			}
		}
	}
	if (inv){
		int invn = power(1 << lg, mod - 2, mod);
		for (int i = 0; i < n; ++ i)
			A[i] = 1ll * A[i] * invn % mod;
	}
}
void DFS(int v, int p = - 1){
	for (int u : adj[v])
		if (u != p)
			DFS(u, v), ++ d[v];
}
void divide(int id, int l, int r){
	if (r - l == 1){
		dp[id].push_back(1);
		dp[id].push_back(d[l]);
		return;
	}
	int mid = l + r >> 1;
	divide(lc, l, mid);
	divide(rc, mid, r);
	int lg = 0;
	for (int i = 0; i < 20; ++ i){
		if (r - l + 1 <= (1 << i)){
			lg = i;
			break;
		}
	}
	//++ lg;
	for (int i = 0; i <= mid - l; ++ i)
		A[i] = dp[lc][i];
	for (int i = mid - l + 1; i < (1 << lg); ++ i)
		A[i] = 0;
	for (int i = 0; i <= r - mid; ++ i)
		B[i] = dp[rc][i];
	for (int i = r - mid + 1; i < (1 << lg); ++ i)
		B[i] = 0;
	for (int i = 1; i < (1 << lg); ++ i)
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (lg - 1));
	NTT(A, 0, lg), NTT(B, 0, lg);
	for (int i = 0; i < (1 << lg); ++ i)
		A[i] = 1ll * A[i] * B[i] % mod;
	NTT(A, 1, lg);
	for (int i = 0; i <= r - l; ++ i)
		dp[id].push_back(A[i]);
}
 
int main(){
	InTheNameOfGod;
	
	fact[0] = 1;
	for (int i = 1; i < xn; ++ i)
		fact[i] = 1ll * fact[i - 1] * i % mod;
	ifact[xn - 1] = power(fact[xn - 1], mod - 2, mod);
	for (int i = xn - 2; i >= 0; -- i)
		ifact[i] = 1ll * ifact[i + 1] * (i + 1) % mod;
	cin >> n;
	for (int i = 1; i < n; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	DFS(1), divide(1, 1, n + 1);
	for (int i = 0; i <= n; ++ i){
		if (i % 2)
			ans = (ans - 1ll * dp[1][i] * fact[n - i] % mod + mod) % mod;
		else
			ans = (ans + 1ll * dp[1][i] * fact[n - i] % mod) % mod;
	}
	cout << ans << endl;
 
	return 0;
}