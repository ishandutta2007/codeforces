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

const int xn = 80 + 10;
const int xm = 9;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

ll n, a[xn], b[xn];
double dp[xm][xn][xn], F[xn][xn];
vector <int> cprs;
 
void check(int x, int h, int y){
	double l = 0, r = 0, m;
	if (a[y] < x)
		l = 1.0 * (cprs[x] - cprs[a[y]]) / (cprs[b[y]] - cprs[a[y]]);
	if (1 < l)
		l = 1;
	if (x + 1 < b[y])
		r = 1.0 * (cprs[b[y]] - cprs[x + 1]) / (cprs[b[y]] - cprs[a[y]]);
	if (1 < r)
		r = 1;
	m = 1 - l - r;
	for (ll i = n; 0 <= i; -- i)
		for (ll j = n; 0 <= j; -- j)
			dp[h][i][j] = dp[h][i][j] * r + dp[h][i - 1][j] * l + dp[h][i][j - 1] * m;
}
 
void build(int val, int l, int r, int h){
	if(r - l == 1){
		if (!(a[l] <= val && val < b[l]))
			return;
		for (int i = 0; i < n; ++ i){
			for (int j = 0; j < n; ++ j){
				double res = dp[h][i][j] / (j + 1);
				res *= (cprs[val + 1] - cprs[val]);
				res /= (cprs[b[l]] - cprs[a[l]]);
				F[l][i + j + 1] -= res;
				res = dp[h][i][j] / (j + 1);
				res *= (cprs[val + 1] - cprs[val]);
				res /= (cprs[b[l]] - cprs[a[l]]);
				F[l][i] += res;
			}
		}
		return;
	}
	int mid = l + r >> 1;
	for (int i = 0; i < n; ++ i)
		for (int j = 0; j < n; ++ j)
			dp[h + 1][i][j] = dp[h][i][j];
	for (int i = mid; i < r; ++ i)
		check(val, h + 1, i);
	build(val, l, mid, h + 1);
	for (int i = 0; i < n; ++ i)
		for (int j = 0; j < n; ++ j)
			dp[h + 1][i][j] = dp[h][i][j];
	for (int i = l; i < mid; ++ i)
		check(val, h + 1, i);
	build(val, mid, r, h + 1);
}
 
int main(){
    fast_io;
    
    cin >> n;
    for(int i = 0; i < n; ++ i){
    	cin >> a[i] >> b[i];
    	cprs.push_back(a[i]);
    	cprs.push_back(b[i]);
	}
	sort(all(cprs));
	cprs.resize(unique(all(cprs)) - cprs.begin());
	for(int i = 0; i < n; ++ i){
		a[i] = lower_bound(all(cprs), a[i]) - cprs.begin();
		b[i] = lower_bound(all(cprs), b[i]) - cprs.begin();
	}
	dp[0][0][0] = 1;
	for (int i = 0; i < SZ(cprs); ++ i)
		build(i, 0, n, 0);
	cout << setprecision(9) << fixed;
	for(int i = 0; i < n; ++ i){
		for(int j = 1; j < xn; ++ j)
			F[i][j] += F[i][j - 1];
		for(int j = 0; j < n; ++ j)
			cout << F[i][j] << sep;
		cout << endl;
	}
 
    return 0;
}