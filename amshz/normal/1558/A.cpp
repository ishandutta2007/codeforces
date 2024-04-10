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

const int xn = - 20 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int qq, a, b, f, z;
set <int> st;

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> a >> b;
		z = (a + b) / 2;
		f = a + b - z;
		set <int> st;
		for (int i = 0; i <= min(f, b); ++ i)
			if (f - i <= a)
				st.insert(i + a - f + i);
		swap(f, z);
		for (int i = 0; i <= min(f, b); ++ i)
			if (f - i <= a)
				st.insert(i + a - f + i);
		cout << SZ(st) << endl;
		for (int x : st)
			cout << x << sep;
		cout << endl;
	}

	return 0;
}