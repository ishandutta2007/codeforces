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
const int mod = 998244353;
const int base = 257;

int qq, n, k, a[xn], ty[xn], nxt[2][xn];
ll ans;

int main(){
	fast_io;

	for (int i = 2; i < xn; ++ i){
		if (ty[i] == 2)
			continue;
		ty[i] = 1;
		for (int j = i + i; j < xn; j += i)
			ty[j] = 2;
	}
	cin >> qq;
	while (qq --){
		cin >> n >> k, ans = 0;
		for (int i = 1; i <= n; ++ i){
			cin >> a[i];
			nxt[0][i] = 1;
			if (1 <= i - k && !ty[a[i - k]])
				nxt[0][i] += nxt[0][i - k];
		}
		for (int i = n; 1 <= i; -- i){
			nxt[1][i] = 1;
			if (i + k <= n && !ty[a[i + k]])
				nxt[1][i] += nxt[1][i + k];
			if (ty[a[i]] == 1)
				ans += 1ll * nxt[0][i] * nxt[1][i] - 1;
		}
		cout << ans << endl;
	}

	return 0;
}