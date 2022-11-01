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
# define fast_io                                         ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 2e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod[2] = {1000000007, 998244353};
const int base = 257;

int n, k, pw[2][xn], res;
pii hsh;
string S, T;
bool mark[xn];
set <pii> st;

int main(){
	fast_io;

	for (int i = 0; i < 2; ++ i){
		pw[i][0] = 1;
		for (int j = 1; j < xn; ++ j)
			pw[i][j] = 1ll * pw[i][j - 1] * base % mod[i];
	}
	cin >> S >> T >> k;
	n = SZ(S), S = '.' + S;
	for (int i = 0; i < 26; ++ i)
		mark[i] = T[i] - '0';
	for (int i = 1; i <= n; ++ i){
		hsh = {0, 0}, res = 0;
		for (int j = i; j <= n; ++ j){
			res += !mark[S[j] - 'a'];
			if (k < res)
				break;
			hsh.A = (hsh.A + 1ll * pw[0][j - i + 1] * (S[j] - 'a' + 1) % mod[0]) % mod[0];
			hsh.B = (hsh.B + 1ll * pw[1][j - i + 1] * (S[j] - 'a' + 1) % mod[1]) % mod[1];
			st.insert(hsh);
		}
	}
	cout << SZ(st) << endl;

	return 0;
}