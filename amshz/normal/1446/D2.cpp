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
const int sq = 450;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, a[xn], cnt[xn], mx, ps[xn], last[xn + xn], ans, f[xn], ptr;

void solve(int x){
	int mn = inf;
	for (int i = 1; i <= n; ++ i){
		ps[i] = ps[i - 1] + (a[i] == x) - (a[i] == mx);
		if (!ps[i] || last[ps[i] + xn])
			ans = max(ans, i - last[ps[i] + xn]);
		else
			last[ps[i] + xn] = i;
	}
	for (int i = 1; i <= n; ++ i)
		if (ps[i])
			last[ps[i] + xn] = 0;
}
void add(int x, int val){
	if (val == 1)
		++ cnt[x], ++ f[cnt[x]];
	else
		-- f[cnt[x]], -- cnt[x];
}

int main(){
	fast_io;

	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i], ++ cnt[a[i]];
	for (int i = 1; i <= n; ++ i)
		if (cnt[mx] < cnt[i])
			mx = i;
	for (int i = 1; i <= n; ++ i)
		if (sq < cnt[i] && i != mx)
			solve(i);
	for (int j = 1; j <= sq; ++ j){
		memset(cnt, 0, sizeof cnt);
		memset(f, 0, sizeof f);
		f[0] = n, ptr = 0;
		for (int i = 1; i <= n; ++ i){
			if (i)
				add(a[i - 1], - 1);
			while (ptr < n && cnt[mx] + (a[ptr + 1] == mx) <= j)
				add(a[++ ptr], 1);
			if (2 <= f[j])
				ans = max(ans, ptr - i + 1);
		}
	}
	cout << ans << endl;

	return 0;
}