# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 4e3 + 10;
const int xm = 2e4 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, p, q, a[xm], b[xm], ans[xm], dp[2][xn][xn], res[xn];
pair <int, pii> c[xn];
vector <pii> adj[xm];

void build(int id, int l, int r){
	if (r - l == 1){
		for (pii x : adj[l])
			if (b[x.B] >= c[l].B.A && x.A < r)
				ans[x.B] = c[l].B.B;
		return;
	}
	int mid = l + r >> 1;
	for (int i = 0; i < xn; ++ i)
		dp[0][mid - 1][i] = 0;
	for (int i = mid; i < r; ++ i){
		for (int j = 0; j < xn; ++ j){
			dp[0][i][j] = dp[0][i - 1][j];
			if (j >= c[i].B.A)
				dp[0][i][j] = max(dp[0][i][j], dp[0][i - 1][j - c[i].B.A] + c[i].B.B);
		}
	}
	for (int i = 0; i < xn; ++ i)
		dp[1][mid][i] = 0;
	for (int i = mid - 1; i >= l; -- i){
		for (int j = 0; j < xn; ++ j){
			dp[1][i][j] = dp[1][i + 1][j];
			if (j >= c[i].B.A)
				dp[1][i][j] = max(dp[1][i][j], dp[1][i + 1][j - c[i].B.A] + c[i].B.B);
		}
		for (pii x : adj[i]){
			if (x.A < mid || x.A >= r)
				continue;
			for (int j = 0; j <= b[x.B]; ++ j)
				ans[x.B] = max(ans[x.B], dp[1][i][j] + dp[0][x.A][b[x.B] - j]);
		}
	}
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
}

int main(){
    InTheNameOfGod;
    
    cin >> n >> p;
    for (int i = 0; i < n; ++ i)
    	cin >> c[i].B.A >> c[i].B.B >> c[i].A;
    sort(c, c + n);
	cin >> q;
	for (int i = 1; i <= q; ++ i){
		cin >> a[i] >> b[i];
		int l = n, r = - 1;
		for (int j = 0; j < n; ++ j){
			if (a[i] >= c[j].A && a[i] < c[j].A + p)
				l = min(l, j);
			if (a[i] >= c[j].A && a[i] < c[j].A + p)
				r = max(r, j);
		}
		if (r != - 1)
			adj[l].push_back({r, i});
	}
	build(1, 0, n);
	for (int i = 1; i <= q; ++ i)
		cout << ans[i] << endl;
 
    return 0;
}