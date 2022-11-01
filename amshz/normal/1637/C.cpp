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

int qq, n, a[xn], cnt, mn;
bool flag;
ll sum, ans;

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n;
		for (int i = 1; i <= n; ++ i)
			cin >> a[i];
		ans = 0;
		if (3 < n){
			sort(a + 2, a + n);
			if (3 <= a[n - 1] && a[n - 1] % 2 && a[n - 2] == 0)
				++ ans, ++ a[n - 2], a[n - 1] -= 2;
		}
		flag = true, cnt = 0, mn = 0, sum = 0;
		for (int i = 2; i < n; ++ i){
			flag &= (a[i] % 2 == 1);
			sum += a[i];
			cnt += a[i] % 2;
			mn = max(mn, a[i]);
		}
		if (flag && (n == 3 || mn <= 1))
			cout << - 1 << endl;
		else if (mn <= 1 && sum)
			cout << - 1 << endl;
		else
			cout << (sum + cnt) / 2 + ans << endl;
	}

	return 0;
}