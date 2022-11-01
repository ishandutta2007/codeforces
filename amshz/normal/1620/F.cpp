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
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int qq, n, a[xn][2], ans[xn];
pii dp[xn][2];

int main(){
	fast_io;

	dp[0][0].A = a[0][0] = - inf;
	cin >> qq;
	while (qq --){
		cin >> n;
		for (int i = 1; i <= n; ++ i){
			cin >> a[i][0];
			a[i][1] = - a[i][0];
			for (int f1 = 0; f1 < 2; ++ f1){
				dp[i][f1].A = inf;
				for (int f2 = 0; f2 < 2; ++ f2){
					if (a[i - 1][f2] < a[i][f1])
						dp[i][f1] = min(dp[i][f1], {dp[i - 1][f2].A, f2});
					if (dp[i - 1][f2].A < a[i][f1])
						dp[i][f1] = min(dp[i][f1], {a[i - 1][f2], f2});
				}
			}
		}
		int ptr = n, ind = 0;
		if (dp[n][1].A < inf)
			ind = 1;
		if (dp[n][ind].A == inf){
			cout << "NO" << endl;
			continue;
		}
		while (ptr){
			ans[ptr] = a[ptr][ind];
			ind = dp[ptr][ind].B;
			-- ptr;
		}
		cout << "YES" << endl;
		for (int i = 1; i <= n; ++ i)
			cout << ans[i] << sep;
		cout << endl;
	}

	return 0;
}