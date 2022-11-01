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

const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, q, res;
string S;
char s[xn];

bool check(int ind){
	if (ind < 1 || n < ind + 2)
		return false;
	if (s[ind] == 'a' && s[ind + 1] == 'b' && s[ind + 2] == 'c')
		return true;
	return false;
}

int main(){
	fast_io;

	cin >> n >> q >> S;
	for (int i = 1; i <= n; ++ i)
		s[i] = S[i - 1];
	for (int i = 1; i <= n; ++ i)
		res += check(i);
	while (q --){
		int x;
		char c;
		cin >> x >> c;
		res -= check(x - 2) + check(x - 1) + check(x);
		s[x] = c;
		res += check(x - 2) + check(x - 1) + check(x);
		cout << res << endl;
	}

	return 0;
}