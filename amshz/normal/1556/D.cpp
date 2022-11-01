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
//# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define fast_io                                         ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 1e4 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, A[xn], a[4][4], b[4][4], k, f[4][30];

int main(){
	//fast_io;

	cin >> n >> k;
	for (int i = 1; i <= 3; ++ i){
		for (int j = i + 1; j <= 3; ++ j){
			cout << "and " << i << sep << j << endl;
			cin >> a[i][j];
			cout << "or " << i << sep << j << endl;
			cin >> b[i][j];
		}
	}
	memset(f, - 1, sizeof f);
	for (int i = 1; i <= 3; ++ i){
		for (int j = i + 1; j <= 3; ++ j){
			for (int bit = 0; bit < 30; ++ bit){
				if ((a[i][j] & (1 << bit)))
					f[i][bit] = f[j][bit] = 1;
				if (!(b[i][j] & (1 << bit)))
					f[i][bit] = f[j][bit] = 0;
			}
		}
	}
	for (int i = 1; i <= 3; ++ i){
		for (int j = i + 1; j <= 3; ++ j){
			for (int bit = 0; bit < 30; ++ bit){
				if ((a[i][j] & (1 << bit)))
					f[i][bit] = f[j][bit] = 1;
				else if (!(b[i][j] & (1 << bit)))
					f[i][bit] = f[j][bit] = 0;
				else if (f[i][bit] + 1)
					f[j][bit] = 1 - f[i][bit];
				else
					f[i][bit] = 1 - f[j][bit];
				if (f[i][bit])
					A[i] |= (1 << bit);
				if (f[j][bit])
					A[j] |= (1 << bit);
			}
		}
	}
	for (int i = 4; i <= n; ++ i){
		int x, y;
		cout << "and " << 1 << sep << i << endl;
			cin >> x;
			cout << "or " << 1 << sep << i << endl;
			cin >> y;
		for (int bit = 0; bit < 30; ++ bit){
			if ((x & (1 << bit)))
				A[i] += (1 << bit);
			else if ((y & (1 << bit))){
				A[i] += ((1 << bit) ^ (A[1] & (1 << bit)));
			}
		}
	}
	sort(A + 1, A + n + 1);
	cout << "finish " << A[k] << endl;

	return 0;
}