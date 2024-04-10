//khodaya khodet komak kon
# include <bits/stdc++.h>
//#pragma GCC optimize("Ofast", "-unroll-loops")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("avx", "avx2", "fma")

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

const int xn = 3e5 + 10;
const int xm = 1e7 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, m, c[xn], d[xm], lstbit[xn], cnt, ptr, A[xn], last, k, res;
pii a[xn];
bool p[xm], b[xn], fl[xn], f[xm], flag, mark[xn];
vector <int> vec[xm], pbs[xn], mlf[xn], adj[xn], ans;

void add(int x, int val){
	m = SZ(vec[x]), c[0] = 1;
	for (int mask = 0; mask < (1 << m); ++ mask){
		if (mask)
			c[mask] = c[mask - (1 << lstbit[mask])] * vec[x][lstbit[mask]];
		d[c[mask]] += val;
	}
}
int check(int x){
	m = SZ(vec[x]), c[0] = 1, res = 0;
	for (int mask = 0; mask < (1 << m); ++ mask){
		if (mask)
			c[mask] = c[mask - (1 << lstbit[mask])] * vec[x][lstbit[mask]];
		if (fl[mask])
			res -= d[c[mask]];
		else
			res += d[c[mask]];
	}
	return res;
}
void DFS(int v){
	mark[v] = true;
	mlf[ptr].push_back(v);
	for (int u : adj[v])
		if (!mark[u])
			DFS(u);
}

int main(){
	fast_io;

	for (int i = 0; i < xn; ++ i)
		for (int j = 0; j < 20; ++ j)
			if ((i & (1 << j)))
				lstbit[i] = j, fl[i] ^= 1;
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i)
		cin >> A[i], f[A[i]] = true;
	for (int i = 2; i < xm; ++ i){
		if (p[i])
			continue;
		for (int j = i; j < xm; j += i){
			p[j] = true;
			if (f[j])
				vec[j].push_back(i);
		}
	}
	for (int i = 1; i <= n; ++ i)
		a[i] = {0, n + 1}, pbs[(n + 1) / 2].push_back(i);
	for (int j = 0; j < 19; ++ j){
		for (int i = n + 1; i >= 1; -- i){
			if (i <= n)
				add(A[i], 1);
			for (int x : pbs[i])
				b[x] = bool(0 < check(A[x]));
			pbs[i].clear();
		}
		for (int i = 1; i <= n; ++ i){
			if (a[i].A + 1 == a[i].B)
				continue;
			if (b[i])
				a[i].A = (a[i].A + a[i].B) / 2;
			else
				a[i].B = (a[i].A + a[i].B) / 2;
			if (a[i].B - a[i].A > 1)
				pbs[(a[i].A + a[i].B) / 2].push_back(i);
		}
		memset(d, 0, sizeof d);
	}
	for (int i = 1; i <= n; ++ i)
		add(A[i], 1);
	flag = true;
	for (int i = 1; i <= n; ++ i){
		if (check(A[i]) > 1 && flag){
			flag = false, last = i;
			for (int j = 1; j <= n; ++ j)
				if (__gcd(A[i], A[j]) == 1)
					adj[i].push_back(j), adj[j].push_back(i);
		}
	}
	memset(d, 0, sizeof d);
	for (int i = 1; i <= n; ++ i){
		if (a[i].A)
			adj[a[i].A].push_back(i), ++ d[a[i].A], ++ d[i], adj[i].push_back(a[i].A);
		else
			++ cnt;
	}
	if (k <= cnt){
		for (int i = 1; i <= n; ++ i)
			if (!a[i].A && k)
				cout << i << sep, -- k;
		cout << endl;
		return 0;
	}
	if (flag){
		for (int i = 1; i <= n; ++ i)
			if (a[i].A < i && k)
				cout << i << sep, -- k;
		cout << endl;
		return 0;
	}
	ptr = 1, DFS(last);
	for (int i = 1; i <= n; ++ i)
		if (!mark[i] && SZ(adj[i]))
			++ ptr, DFS(i);
	for (int i = 1; i <= min(ptr, k / 2); ++ i)
		ans.push_back(mlf[i][0]), ans.push_back(mlf[i][1]);
	k -= 2 * min(k / 2, ptr);
	if (k){
		if (k == 1)
			ans.push_back(mlf[1][2]);
		if (1 < k){
			for (int i = 1; i <= ptr; ++ i)
				for (int j = 2; j < SZ(mlf[i]); ++ j)
					if (k)
						ans.push_back(mlf[i][j]), -- k;
		}
	}
	for (int x : ans)
		cout << x << sep;
	cout << endl;

	return 0;
}