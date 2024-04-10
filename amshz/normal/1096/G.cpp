//khodaya khodet komak kon
# include <bits/stdc++.h>
 
using namespace std;
typedef long long                                        ll;
typedef long double                                      ld;
typedef complex <ld>                                     cd;
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
 
const int xn = - 20 + 10;
const int xm = 20;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;
const ld PI = acos(-1);

int rev[1 << xm];

void NTT(int *A, bool inv){
	for (int i = 1; i < (1 << xm); ++ i)
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (xm - 1));
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

int n, k, A[1 << xm], ans;

int main(){
	fast_io;

	//kill("Hello, World!");
	cin >> n >> k;
	while (k --){
		int x;
		cin >> x;
		++ A[x];
	}
	NTT(A, 0);
	for (int i = 0; i < 1 << xm; ++ i)
		A[i] = power(A[i], n / 2, mod);
	NTT(A, 1);
	for (int i = 0; i < 1 << xm; ++ i)
		ans = (ans + 1ll * A[i] * A[i] % mod) % mod;
	cout << ans << endl;

	return 0;
}