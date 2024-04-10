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

int n, x, a[xn], qq, dp[xn];

bool check(int l, int r){
	if (l < 1)
		return true;
	ld sum = 0, ted = (r - l + 1), y = x;
	for (int i = l; i <= r; ++ i)
		sum += a[i];
	return (y * ted <= sum);
}

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n;
		for (int i = 1; i <= n; ++ i)
			cin >> a[i];
		cin >> x;
		for (int i = 1; i <= n; ++ i){
			dp[i] = dp[i - 1];
			for (int j = i; 1 <= j && i - j + 1 <= 3; -- j){
				bool flag = true;
				for (int l = j; l <= i; ++ l)
					for (int r = l + 1; r <= i; ++ r)
						flag &= check(l, r);
				if (flag)
					dp[i] = max(dp[i], dp[max(0, j - 2)] + i - j + 1);
			}
			if (check(i - 3, i) && check(i - 2, i) && check(i - 1, i))
				dp[i] = max(dp[i], dp[i - 1] + 1);
		}
		cout << dp[n] << endl;
	}

	return 0;
}