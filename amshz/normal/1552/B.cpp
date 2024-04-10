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
const int mod = 998244353;
const int base = 257;

int qq, n, a[xn][5], ind;
bool flag;

bool check(int i, int j){
	int ted = 0;
	for (int k = 0; k < 5; ++ k)
		ted += a[i][k] < a[j][k];
	return 3 <= ted;
}

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n;
		for (int i = 1; i <= n; ++ i)
			for (int j = 0; j < 5; ++ j)
				cin >> a[i][j];
		ind = 1;
		for (int i = 2; i <= n; ++ i)
			if (check(i, ind))
				ind = i;
		flag = true;
		for (int i = 1; i <= n; ++ i)
			if (i != ind)
				flag &= check(ind, i);
		if (flag)
			cout << ind << endl;
		else
			cout << - 1 << endl;
	}

	return 0;
}