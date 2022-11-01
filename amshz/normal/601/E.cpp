//khodaya khodet komak kon
# include <bits/stdc++.h>

/*
// ordered_set 
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/

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

const int xn = 3e4 + 10;
const int xm = 1e3 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 1e7 + 19;

int n, k, q, ans, pw[xm], dp[xm], pd[17][xm];
pii a[xn], b[xn];
bool flag[xn];
vector <int> seg[xn << 2];

void update(int id, int l, int r, int ql, int qr, int x){
	if (qr <= l || r <= ql || qr <= ql)
		return;
	if (ql <= l && r <= qr){
		seg[id].push_back(x);
		return;
	}
	int mid = l + r >> 1;
	update(lc, l, mid, ql, qr, x);
	update(rc, mid, r, ql, qr, x);
}
void get(int id, int l, int r, int h = 0){
	for (int i = 0; i <= k; ++ i)
		pd[h][i] = dp[i];
	for (int ind : seg[id])
		for (int i = k; i >= a[ind].B; -- i)
			dp[i] = max(dp[i], dp[i - a[ind].B] + a[ind].A);
	if (r - l == 1 && flag[l]){
		ans = 0;
		for (int i = 1; i <= k; ++ i)
			ans = (ans + 1ll * pw[i - 1] * dp[i] % mod) % mod;
		cout << ans << endl;
	}
	int mid = l + r >> 1;
	if (r - l > 1)
		get(lc, l, mid, h + 1), get(rc, mid, r, h + 1);
	for (int i = 0; i <= k; ++ i)
		dp[i] = pd[h][i];
}

int main(){
	InTheNameOfGod;

	pw[0] = 1;
	for (int i = 1; i < xm; ++ i)
		pw[i] = 1ll * pw[i - 1] * base % mod;	
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i].A >> a[i].B;
	cin >> q;
	for (int i = 1; i <= n; ++ i)
		b[i].B = q;
	for (int i = 1; i <= q; ++ i){
		int t, x;
		cin >> t;
		if (t == 1)
			++ n, cin >> a[n].A >> a[n].B, b[n] = {i, q};
		else if (t == 2)
			cin >> x, b[x].B = i;
		else
			flag[i] = true;
	}
	for (int i = 1; i <= n; ++ i)
		update(1, 0, q + 1, b[i].A, b[i].B + 1, i);
	get(1, 0, q + 1);

	return 0;
}