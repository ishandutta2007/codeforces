//khodaya khodet komak kon
# include <bits/stdc++.h>
# pragma GCC optimize("O2")

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
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, a[xn], ans, b[xn], ptr;
//unordered_map <int, int> cnt, mp[xn];

int calc(){
	sort(b + 1, b + ptr + 1);
	int res = 0, cnt = 0;
	for (int i = 1; i <= ptr; ++ i){
		if (1 < i && b[i] != b[i - 1])
			res = max(res, cnt), cnt = 0;
		++ cnt;
	}
	res = max(res, cnt);
	return res;
}

int main(){
	fast_io;

	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	for (int d = - sq; d <= sq; ++ d){
		ptr = 0;
		for (int i = 1; i <= n; ++ i){
			//++ cnt[a[i] - i * d];
			//ans = max(ans, cnt[a[i] - i * d]);
			b[++ ptr] = a[i] - i * d;
		}
		ans = max(ans, calc());
	}
	for (int i = n; 1 <= i; -- i){
		ptr = 0;
		for (int j = i + 1; j <= min(n, i + sq); ++ j){
			int d = a[j] - a[i];
			if (d % (j - i))
				continue;
			d /= (j - i);
			b[++ ptr] = d;
		}
		ans = max(ans, calc() + 1);
	}
	cout << n - ans << endl;

	return 0;
}