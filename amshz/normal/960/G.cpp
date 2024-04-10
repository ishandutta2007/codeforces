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
 
const int xn = 1e5 + 10;
int xm = 17;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;
const ld PI = acos(-1);

int rev[1 << 17];

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

int n, a, b, A[1 << 17], B[1 << 17];
int fact[xn], ifact[xn];
vector <int> vec[xn << 2];

int C(int n, int r){
	if (r < 0 || n - r < 0)
		return 0;
	return 1ll * fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}
void divide(int id, int l, int r){
	if (r - l == 1){
		vec[id].push_back(1);
		vec[id].push_back(l);
		return;
	}
	int mid = l + r >> 1;
	divide(lc, l, mid);
	divide(rc, mid, r);
	xm = 17;
	for (int i = 16; 0 <= i; -- i)
		if (r - l < (1 << i))
			xm = i;
	fill(A, A + (1 << xm), 0);
	for (int i = 0; i <= mid - l; ++ i)
		A[i] = vec[lc][i];
	fill(B, B + (1 << xm), 0);
	for (int i = 0; i <= r - mid; ++ i)
		B[i] = vec[rc][i];
	NTT(A, 0), NTT(B, 0);
	for (int i = 0; i < 1 << xm; ++ i)
		A[i] = 1ll * A[i] * B[i] % mod;
	NTT(A, 1);
	for (int i = 0; i <= r - l; ++ i)
		vec[id].push_back(A[i]);
}

int main(){
	fast_io;

	//kill("Hello, World!");
	fact[0] = 1;
	for (int i = 1; i < xn; ++ i)
		fact[i] = 1ll * fact[i - 1] * i % mod;
	ifact[xn - 1] = power(fact[xn - 1], mod - 2, mod);
	for (int i = xn - 2; 0 <= i; -- i)
		ifact[i] = 1ll * ifact[i + 1] * (i + 1) % mod;
	cin >> n >> a >> b;
	if (n + 1 < a + b || !b || !a)
		kill(0);
	if (n < 2)
		kill(1);
	divide(1, 0, n - 1);
	cout << 1ll * C(a + b - 2, a - 1) * vec[1][n - a - b + 1] % mod << endl;

	return 0;
}