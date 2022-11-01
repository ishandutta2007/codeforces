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

const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int qq, n, k, a[xn], cnt[xn], ptr, R[xn], res, last;

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n >> k;
		fill(cnt, cnt + n + 1, 0);
		for (int i = 1; i <= n; ++ i)
			cin >> a[i], ++ cnt[a[i]];
		res = ptr = 0;
		for (int i = 1; i <= n; ++ i){
			res -= cnt[i - 1];
			while (ptr < n && res < (n + k + 1) / 2)
				res += cnt[++ ptr];
			R[i] = inf;
			if (res >= (n + k + 1) / 2)
				R[i] = ptr;
		}
		int mn = inf, L = - 1;
		for (int i = 1; i <= n; ++ i)
			if (R[i] - i < mn)
				mn = R[i] - i, L = i;
		cout << L << sep << R[L] << endl;
		ptr = res = last = 0;
		for (int i = 1; i <= k; ++ i){
			while (ptr < n && (res <= 0 || i == k)){
				++ ptr;
				if (L <= a[ptr] && a[ptr] <= R[L])
					++ res;
				else
					-- res;
			}
			cout << last + 1 << sep << ptr << endl;
			last = ptr, res = 0;
		}
	}

	return 0;
}