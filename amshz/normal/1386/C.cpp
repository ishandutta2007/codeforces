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

int n, m, q, sz[xn], dp[xn];
pii E[xn], par[xn];
vector <pii> his;

pii get_root(int v){
	if (v == par[v].A)
		return {v, 0};
	pii x = get_root(par[v].A);
	x.B ^= par[v].B;
	return x;
}
pii merge(int pv, int pu){
	pii v = get_root(pv);
	pii u = get_root(pu);
	if (v.A == u.A){
		if (v.B == u.B)
			return {0, 1};
		return {0, 0};
	}
	if (sz[v.A] < sz[u.A])
		swap(v, u);
	his.push_back({v.A, u.A});
	par[u.A] = {v.A, v.B ^ u.B ^ 1};
	sz[v.A] += sz[u.A];
	return {1, 0};
}
void undo(){
	int v = his.back().A, u = his.back().B;
	par[u] = {u, 0};
	sz[v] -= sz[u];
	his.pop_back();
}
void solve(int l, int r, int qr, bool flag){
	if (r <= l)
		return;
	if (flag){
		for (int i = l; i < r; ++ i)
			dp[i] = m + 2;
		return;
	}
	int mid = l + r >> 1, cnt = 0;
	bool fl2 = flag;
	for (int i = l + 1; i <= mid; ++ i){
		pii x = merge(E[i].A, E[i].B);
		fl2 |= x.B, cnt += x.A;
	}
	pii x = merge(E[mid + 1].A, E[mid + 1].B);
	solve(mid + 1, r, qr, (fl2 | x.B));
	if (x.A)
		undo();
	if (fl2)
		dp[mid] = m + 2;
	else{
		dp[mid] = mid + 1;
		for (int i = qr - 1; i > mid; -- i){
			pii x = merge(E[i].A, E[i].B);
			cnt += x.A;
			if (x.B){
				dp[mid] = i + 1;
				break;
			}
		}
	}
	for (int i = 0; i < cnt; ++ i)
		undo();
	cnt = 0;
	for (int i = dp[mid]; i < qr; ++ i){
		pii x = merge(E[i].A, E[i].B);
		cnt += x.A, flag |= x.B;
	}
	solve(l, mid, min(dp[mid], m + 1), flag);
	for (int i = 0; i < cnt; ++ i)
		undo();
}

int main(){
	fast_io;

	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++ i)
		par[i].A = i, sz[i] = 1;
	for (int i = 1; i <= m; ++ i){
		int v, u;
		cin >> v >> u;
		E[i] = {v, u};
	}
	solve(0, m + 1, m + 1, 0);
	while (q --){
		int l, r;
		cin >> l >> r;
		if (dp[l - 1] <= r + 1)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}

	return 0;
}