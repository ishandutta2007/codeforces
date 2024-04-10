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
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int qq, n, a[xn], ptr, dp[3][xn], fen[xn];
int pmx[xn], ans;
map <int, int> mp;
vector <int> cprs;

void mofen(int pos, int val){
	for (pos += 5; pos < xn; pos += pos & - pos)
		fen[pos] = (fen[pos] + val) % mod;
}
int gefen(int pos){
	int res = 0;
	for (pos += 5; 0 < pos; pos -= pos & - pos)
		res = (res + fen[pos]) % mod;
	return res;
}

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n;
		mp.clear(), cprs.clear();
		for (int i = 1; i <= n; ++ i)
			cin >> a[i], cprs.push_back(a[i]);
		sort(all(cprs));
		ptr = 0;
		ans = 0;
		for (int i = 0; i < SZ(cprs); ++ i){
			if (i && cprs[i] == cprs[i - 1])
				continue;
			mp[cprs[i]] = ptr ++;
		}
		for (int i = 1; i <= n; ++ i){
			a[i] = mp[a[i]];
			dp[0][i] = (gefen(a[i] - 1) + 1) % mod;
			mofen(a[i], dp[0][i]);
		}
		pmx[n + 1] = - inf;
		for (int i = n; 1 <= i; -- i)
			pmx[i] = max(pmx[i + 1], a[i]);
		for (int i = 1; i <= n; ++ i)
			mofen(a[i], (mod - dp[0][i]) % mod);
		for (int i = n; 1 <= i; -- i){
			dp[2][i] = ((gefen(ptr) - gefen(a[i]) + mod) % mod + 1) % mod;
			ans = (ans + 1ll * dp[0][i] * dp[2][i] % mod) % mod;
			mofen(a[i], dp[2][i]);
		}
		for (int i = 1; i <= n; ++ i)
			mofen(a[i], (mod - dp[2][i]) % mod);
		for (int i = n; 1 <= i; -- i){
			int lb = i, rb = n + 1;
			while (1 < rb - lb){
				int md = lb + rb >> 1;
				if (pmx[md] <= a[i])
					rb = md;
				else
					lb = md;
			}
			if (lb == i)
				dp[1][i] = 1;
			else
				dp[1][i] = (1 + gefen(a[lb] - 1) - gefen(a[i]) + mod) % mod;
			mofen(a[i], dp[1][i]);
			ans = (ans - 1ll * dp[0][i] * dp[1][i] % mod + mod) % mod;
		}
		cout << ans << endl;
		for (int i = 1; i <= n; ++ i)
			mofen(a[i], (mod - dp[1][i]) % mod);
	}

	return 0;
}