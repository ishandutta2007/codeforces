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

const int xn = 5e4 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

ll qq, n, m, k, a[xn], b[xn];
vector <pll> vec[2];

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n >> m;
		for (int i = 1; i <= n; ++ i){
			cin >> a[i];
		}
		cin >> k;
		for (int i = 1; i <= k; ++ i){
			cin >> b[i];
		}
		vec[0].clear();
		vec[1].clear();
		for (int i = 1; i <= n; ++ i){
			pll x = {a[i], 1};
			while (a[i] % m == 0){
				x.A /= m;
				x.B *= m;
				a[i] /= m;
			}
			if (SZ(vec[0]) && vec[0].back().A == x.A){
				pll y = vec[0].back();
				vec[0].pop_back();
				x.B += y.B;
				vec[0].push_back(x);
			}
			else{
				vec[0].push_back(x);
			}
		}
		for (int i = 1; i <= k; ++ i){
			pll x = {b[i], 1};
			while (b[i] % m == 0){
				x.A /= m;
				x.B *= m;
				b[i] /= m;
			}
			if (SZ(vec[1]) && vec[1].back().A == x.A){
				pll y = vec[1].back();
				vec[1].pop_back();
				x.B += y.B;
				vec[1].push_back(x);
			}
			else{
				vec[1].push_back(x);
			}
		}
		if (SZ(vec[0]) != SZ(vec[1])){
			cout << "No" << endl;
		}
		else{
			bool flag = true;
			for (int i = 0; i < SZ(vec[0]); ++ i)
				flag &= vec[0][i] == vec[1][i];
			if (flag)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}

	return 0;
}