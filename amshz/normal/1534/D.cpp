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
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 2e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, a[xn], ind;
bool adj[xn][xn];
vector <int> vec[2];

int main(){
	InTheNameOfGod;

	cin >> n;
	cout << "? 1" << endl;
	for (int i = 1; i <= n; ++ i){
		cin >> a[i];
		vec[a[i] % 2].push_back(i);
		adj[1][i] |= (a[i] == 1);
	}
	ind = (SZ(vec[1]) < SZ(vec[0]));
	for (int v : vec[ind]){
		if (v == 1)
			continue;
		cout << "? " << sep << v << endl;
		for (int i = 1; i <= n; ++ i){
			cin >> a[i];
			adj[v][i] |= (a[i] == 1);
			adj[i][v] |= (a[i] == 1);
		}
	}
	cout << "! " << endl;
	for (int i = 1; i <= n; ++ i)
		for (int j = i + 1; j <= n; ++ j)
			if (adj[i][j])
				cout << i << sep << j << endl;

	return 0;
}