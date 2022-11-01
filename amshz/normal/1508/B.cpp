// khodaya khodet komak kon
// Maybe on the Moon
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
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 2e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, qq, ans[xn], ptr, m;
ll k;

ll PW(int x){
	if (x == - 1)
		return 1;
	if (x > 60)
		return INF;
	return (1LL << x);
}

int main(){
	InTheNameOfGod;

	cin >> qq;
	while (qq --){
		cin >> n >> k;
		ptr = 1, m = n;
		for (int i = 1; i <= n;){
			while (PW(n - ptr - 1) < k && ptr + 1 <= n)
				k -= PW(n - ptr - 1), ++ ptr;
			for (int j = i; j <= ptr; ++ j)
				ans[j] = ptr - j + i;
			m -= ptr, ++ ptr, i = ptr;
		}
		if (ptr <= n)
			for (int i = ptr; i <= n; ++ i)
				ans[i] = i;
		if (k == 1)
			for (int i = 1; i <= n; ++ i)
				cout << ans[i] << sep;
		else
			cout << - 1;
		cout << endl;
	}

	return 0;
}