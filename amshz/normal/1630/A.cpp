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

int n, k, qq;

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n >> k;
		if (k == n - 1 && n == 4)
			cout << - 1 << endl;
		else if (k == n - 1){
			cout << n - 1 << sep << n - 2 << endl;
			cout << 1 << sep << 3 << endl;
			cout << 0 << sep << n - 4 << endl;
			for (int i = 1; i + i < n; ++ i)
				if (i != k && i != ((n - 1) ^ k) && i != 3 && i != 1)
					cout << i << sep << ((n - 1) ^ i) << endl;
		}
		else{
			cout << k << sep << n - 1 << endl;
			if (k)
				cout << 0 << sep << ((n - 1) ^ k) << endl;
			for (int i = 1; i + i < n; ++ i)
				if (i != k && i != ((n - 1) ^ k))
					cout << i << sep << ((n - 1) ^ i) << endl;
		}
	}

	return 0;
}