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
 
const int xn = 3e5 + 10;
const int xm = 19;
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

int n, k, a[xn], ps[2][xn], cnt[xn], q, b[xn], ans[xn];
int A[1 << xm], B[1 << xm], C[1 << xm], Q[xn];

int main(){
	fast_io;

	//kill("Hello, World!");
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i], ++ cnt[a[i]];
	for (int i = 1; i <= k; ++ i)
		cin >> b[i];
	for (int i = 0; i < xn; ++ i)
		if (cnt[i])
			++ ps[min(2, cnt[i]) - 1][i];
	for (int i = 0; i < 2; ++ i)
		for (int j = 1; j < xn; ++ j)
			ps[i][j] += ps[i][j - 1];
	A[0] = B[0] = B[2] = 1, A[1] = B[1] = 2;
	NTT(A, 0), NTT(B, 0);
	for (int i = 0; i < 1 << xm; ++ i)
		C[i] = 1ll * A[i] * B[i] % mod;
	cin >> q;
	for (int i = 1; i <= q; ++ i)
		cin >> Q[i], Q[i] /= 2;
	for (int i = 1; i <= k; ++ i){
		for (int j = 0; j < 1 << xm; ++ j)
			C[j] = 1ll * power(A[j], ps[0][b[i] - 1], mod) * power(B[j], ps[1][b[i] - 1], mod) % mod;
		NTT(C, 1);
		for (int j = 1; j <= q; ++ j)
			if (b[i] < Q[j] && Q[j] - b[i] - 1 < xn)
				ans[j] = (ans[j] + C[Q[j] - b[i] - 1]) % mod;
	}
	for (int i = 1; i <= q; ++ i)
		cout << ans[i] << endl;

	return 0;
}