// khodaya khodet komak kon
// Toxicity
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
 
const int xn = 4e4 + 10;
const int xm = 100 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;
 
int n, k, a[xn], L, R, dp[xm][xn], res;
deque <int> dq[xn];
 
ll F(int id){
	if (!SZ(dq[id]))
		return 0;
	return dq[id].back() - dq[id].front();
}
void solve(int l, int r, int ql, int qr, int t){
	if (r <= l || qr <= ql)
		return;
	int mid = l + r >> 1, ind = - 1;
	while (R < mid){
		++ R;
		res -= F(a[R]);
		dq[a[R]].push_back(R);
		res += F(a[R]);
	}
	while (L > ql){
		L --;
		res -= F(a[L]);
		dq[a[L]].push_front(L);
		res += F(a[L]);
	}
	while (R > mid){
		res -= F(a[R]);
		dq[a[R]].pop_back();
		res += F(a[R]);
		-- R;
	}
	while (L < ql){
		res -= F(a[L]);
		dq[a[L]].pop_front();
		res += F(a[L]);
		L ++;
	}
	dp[t][mid] = inf;
	for (int i = ql; i < qr && i <= mid; ++ i){
		if (dp[t - 1][i - 1] + res < dp[t][mid])
			dp[t][mid] = dp[t - 1][i - 1] + res, ind = i;
		res -= F(a[L]);
		dq[a[L]].pop_front();
		res += F(a[L]);
		L ++;
	}
	solve(l, mid, ql, ind + 1, t);
	solve(mid + 1, r, ind, qr, t);
}
 
int main(){
	InTheNameOfGod;

	cin >> n >> k;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++ i)
		dp[0][i] = inf;
	L = R = 1;
	dq[a[1]].push_back(1);
	for (int i = 1; i <= k; ++ i)
		solve(1, n + 1, 1, n + 1, i);
	cout << dp[k][n] << endl;

	return 0;
}