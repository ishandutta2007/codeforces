//khodaya khodet komak kon
# include <bits/stdc++.h>
 
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
# define fast_io                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e6 + 10;
const int xm = 21;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;
 
int n, m, A[1 << xm], rev[1 << xm];
bool flag[xn];
vector <int> ans;
 
void NTT(int *A, bool inv){
	int n = (1 << xm);
	for (int i = 0; i < (1 << xm); ++ i)
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
		int invn = power(1 << xm, mod - 2, mod);
		for (int i = 0; i < n; ++ i)
			A[i] = 1ll * A[i] * invn % mod;
	}
}
 
int main(){
	fast_io;
 
	//kill("Hello, World!");
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i){
		int x;
		cin >> x;
		++ A[x];
		flag[x] = true;
	}
	++ A[0];
	for (int i = 1; i < (1 << xm); ++ i)
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (xm - 1));
	NTT(A, 0);
	for (int i = 0; i < 1 << xm; ++ i)
		A[i] = power(A[i], 2, mod);
	NTT(A, 1);
	for (int i = 1; i <= m; ++ i){
		if (flag[i] && A[i] == 2)
			ans.push_back(i);
		if (!flag[i] && A[i])
			kill("NO");
	}
	cout << "YES" << endl;
	cout << SZ(ans) << endl;
	for (int i = 0; i < SZ(ans); ++ i)
		cout << ans[i] << sep;
	cout << endl;
 
	return 0;
}