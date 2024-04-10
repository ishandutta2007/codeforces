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

const int xn = 1e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, m, a[xn][xn], ptr, ans, ted, r, c;
pii cnt[3];
unordered_map <int, int> mp;
vector <int> compress;
vector <pii> vec[xn * xn];

int main(){
	InTheNameOfGod;

	cin >> n >> m;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j)
			cin >> a[i][j], compress.push_back(a[i][j]);
	cin >> r >> c;
	sort(all(compress));
	for (int i = 0; i < SZ(compress); ++ i)
		if (!i || compress[i] != compress[i - 1])
			mp[compress[i]] = ptr ++;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j)
			a[i][j] = mp[a[i][j]], vec[a[i][j]].push_back({i, j});
	for (int i = 0; i < ptr; ++ i){
		if (a[r][c] < i)
			break;
		int inv = power(ted, mod - 2, mod);
		ted += SZ(vec[i]);
		int INV = power(ted, mod - 2, mod);
		if (a[r][c] == i)
			INV = 1;
		for (pii x : vec[i]){
			if (i == a[r][c] && (x.A != r || x.B != c))
				continue;
			int res = 1ll * x.A * x.A % mod * cnt[0].A % mod;
			res = (res + 1ll * x.A * cnt[1].A % mod) % mod;
			res = (res + cnt[2].A) % mod;
			res = (res + 1ll * x.B * x.B % mod * cnt[0].B) % mod;
			res = (res + 1ll * x.B * cnt[1].B % mod) % mod;
			res = (res + cnt[2].B) % mod;
			res = 1ll * res * INV % mod * inv % mod;
			ans = (ans + res) % mod;
		}
		for (pii x : vec[i]){
			++ cnt[0].A, ++ cnt[0].B;
			cnt[1].A = (cnt[1].A + mod - 2ll * x.A % mod) % mod;
			cnt[1].B = (cnt[1].B + mod - 2ll * x.B % mod) % mod;
			cnt[2].A = (cnt[2].A + 1ll * x.A * x.A % mod) % mod;
			cnt[2].B = (cnt[2].B + 1ll * x.B * x.B % mod) % mod;
		}
	}
	cout << ans << endl;

	return 0;
}