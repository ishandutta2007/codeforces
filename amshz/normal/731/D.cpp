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

const int xn = 1e6 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 9;//998244353;
const int base = 257;

int n, c, ps[xn];
vector <int> vec[xn];

void add(int l, int r){
	l += c, r += c;
	l %= c, r %= c;
	++ ps[l], -- ps[r + 1];
	if (r < l)
		++ ps[0];
}

int main(){
	fast_io;

	cin >> n >> c;
	for (int i = 1; i <= n; ++ i){
		int sz;
		cin >> sz;
		while (sz --){
			int x;
			cin >> x;
			vec[i].push_back(x);
		}
	}
	for (int i = 1; i < n; ++ i){
		bool flag = false;
		for (int j = 0; j < min(SZ(vec[i]), SZ(vec[i + 1])); ++ j){
			if (vec[i][j] == vec[i + 1][j])
				continue;
			int x = vec[i][j];
			int y = vec[i + 1][j];
			int d = (y - x + c) % c;
			add(c - d + 1 - x, c - x);
			flag = true;
			break;
		}
		if (!flag && SZ(vec[i + 1]) < SZ(vec[i]))
			kill(- 1);
	}
	for (int i = 0; i < c; ++ i){
		if (i)
			ps[i] += ps[i - 1];
		if (!ps[i])
			kill(i);
	}
	kill(- 1);

	return 0;
}