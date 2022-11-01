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

const int xn = 5e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, a[xn], L, R;
bool mark[xn];
set <pii> st, ts;
ll ans;

void rem(int x){
	mark[x] = true;
	st.erase({x, a[x]});
	ts.erase({a[x], x});
}

int main(){
	fast_io;

	cin >> n;
	for (int i = 1; i <= n; ++ i){
		cin >> a[i];
		st.insert({i, a[i]});
		ts.insert({a[i], i});
	}
	L = 1, R = n;
	for (int _ = 0; _ < n - 2; ++ _){
		while (mark[L])
			++ L;
		while (mark[R])
			-- R;
		pii x = *ts.begin();
		if (L < x.B && x.B < R){
			rem(x.B);
			pii y = *st.lower_bound({x.B, 0});
			pii z = *prev(st.find(y));
			ans += min(y.B, z.B);
		}
		else if (L == x.B || true){
			ans += min(a[L], a[R]);
			rem(x.B);
			//pii y = *st.lower_bound({x.B, 0});
		}
	}
	cout << ans << endl;

	return 0;
}