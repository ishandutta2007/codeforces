// khodaya khodet komak kon
// Nightcall - London Grammer
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

const int xn = (1 << 18);
const int xm = 18;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, a[xn], par[xn], sz[xn], tot;
ll ans;
pii dp[xn], mx[xn];

int get_root(int v){
	if (v == par[v])
		return v;
	return par[v] = get_root(par[v]);
}
void merge(int v, int u, int w){
	v = get_root(v);
	u = get_root(u);
	if (v == u)
		return;
	if (sz[v] < sz[u])
		swap(v, u);
	par[u] = v;
	sz[v] += sz[u];
	ans += w, -- tot;
}
void add(int id, int val){
	if (!val)
		return;
	if (!dp[id].A){
		dp[id].A = val;
		return;
	}
	int v = get_root(dp[id].A);
	int u = get_root(val);
	if (v == u)
		return;
	if (!dp[id].B){
		if (a[dp[id].A] < a[val])
			dp[id] = {val, dp[id].A};
		else
			dp[id].B = val;
		return;
	}
	if (a[dp[id].A] < a[val])
		dp[id] = {val, dp[id].A};
	else
		dp[id].B = (a[dp[id].B] < a[val] ? val : dp[id].B);
}

int main(){
	InTheNameOfGod;

	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i], ans -= a[i];
	for (int i = 0; i < xn; ++ i)
		par[i] = i, sz[i] = 1;
	//for (int tt = 0; tt < xm; ++ tt){
	tot = ++ n;
	while (tot > 1){
		memset(dp, 0, sizeof dp);
		for (int i = 1; i <= n; ++ i)
			mx[i] = {- 1, 0}, add(a[i], i);
		for (int i = 0; i < xm; ++ i)
			for (int mask = xn - 1; mask > 0; -- mask)
				if (mask >> i & 1)
					add(mask, dp[mask ^ (1 << i)].A), add(mask, dp[mask ^ (1 << i)].B);
		for (int i = 1; i <= n; ++ i){
			int mask = (xn - 1) ^ a[i];
			int v = get_root(i);
			pii x;
			if (!dp[mask].A)
				continue;
			if (get_root(dp[mask].A) == v){
				if (!dp[mask].B)
					continue;
				x = {a[i] + a[dp[mask].B], dp[mask].B};
			}
			else
				x = {a[i] + a[dp[mask].A], dp[mask].A};
			mx[v] = max(mx[v], x);
		}
		for (int i = 1; i <= n; ++ i)
			if (get_root(i) == i && mx[i].A + 1)
				merge(i, mx[i].B, mx[i].A);
	}
	cout << ans << endl;

	return 0;
}