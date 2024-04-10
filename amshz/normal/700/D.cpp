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

const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, q, a[xn], cnt[xn], f[xn], ps[sq][xn], m, b[xn], L, R, c[xn], ans[xn], res;
ppi query[xn];
priority_queue <int> pq;

bool cmp(ppi x, ppi y){
	if (x.A.A / sq != y.A.A / sq)
		return x.A.A < y.A.A;
	return x.A.B < y.A.B;
}
void add(int x, int val){
	-- f[cnt[x]];
	cnt[x] += val;
	++ f[cnt[x]];
}
void upd(int x, int y, int z){
	res += (x + y) * z;
	if (sq < x + y){
		for (int i = 0; i < z; ++ i)
			pq.push(- x - y);
		return;
	}
	c[x + y] += z;
}

int main(){
	fast_io;

	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i], ++ cnt[a[i]];
	for (int i = 1; i < xn; ++ i)
		if (sq < cnt[i])
			b[++ m] = i;
	for (int i = 1; i <= m; ++ i)
		for (int j = 1; j <= n; ++ j)
			ps[i][j] = ps[i][j - 1] + (a[j] == b[i]);
	cin >> q;
	for (int i = 1; i <= q; ++ i)
		cin >> query[i].A.A >> query[i].A.B, query[i].B = i;
	sort(query + 1, query + q + 1, cmp);
	memset(cnt, 0, sizeof cnt);
	L = R = 1, ++ cnt[a[1]], ++ f[1];
	for (int ii = 1; ii <= q; ++ ii){
		int l = query[ii].A.A;
		int r = query[ii].A.B;
		int ind = query[ii].B;
		while (R < r)
			++ R, add(a[R], 1);
		while (l < L)
			-- L, add(a[L], 1);
		while (r < R)
			add(a[R], - 1), -- R;
		while (L < l)
			add(a[L], - 1), ++ L;
		for (int i = 1; i <= m; ++ i)
			if (sq < ps[i][r] - ps[i][l - 1])
				pq.push(ps[i][l - 1] - ps[i][r]);
		for (int i = 1; i <= sq; ++ i)
			c[i] = f[i];
		int last = 0;
		res = 0;
		for (int i = 1; i <= sq; ++ i){
			if (last && c[i])
				upd(last, i, 1), last = 0, -- c[i];
			upd(i, i, c[i] / 2), c[i] %= 2;
			if (c[i])
				last = i;
		}
		if (last)
			pq.push(- last);
		while (1 < SZ(pq)){
			int x = - pq.top();
			pq.pop();
			int y = - pq.top();
			pq.pop();
			res += x + y;
			pq.push(- x - y);
		}
		if (SZ(pq))
			pq.pop();
		ans[ind] = res;
	}
	for (int i = 1; i <= q; ++ i)
		cout << ans[i] << endl;

	return 0;
}