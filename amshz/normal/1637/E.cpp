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

const int xn = 3e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int qq, n, m, a[xn], ptr, cnt[xn], b[xn];
ppi A[xn];
vector <int> adj[xn], cprs, V;
vector <pii> vec[xn];
ll ans;
unordered_map <int, int> mp;
bool mark[xn];

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n >> m;
		cprs.clear();
		for (int i = 1; i <= n; ++ i)
			cin >> a[i], cprs.push_back(a[i]);
		sort(all(cprs));
		mp.clear(), ptr = 0;
		for (int i = 0; i < SZ(cprs); ++ i)
			if (!i || cprs[i] != cprs[i - 1])
				b[ptr] = cprs[i], mp[cprs[i]] = ptr ++;
		fill(cnt, cnt + ptr, 0);
		for (int i = 1; i <= n; ++ i)
			++ cnt[mp[a[i]]], vec[i].clear();
		for (int i = 0; i < ptr; ++ i)
			vec[cnt[i]].push_back({b[i], i});
		V.clear();
		for (int i = 1; i <= n; ++ i){
			if (SZ(vec[i]))
				V.push_back(i);
			sort(all(vec[i]));
			reverse(all(vec[i]));
		}
		for (int i = 0; i < ptr; ++ i)
			adj[i].clear();
		while (m --){
			int v, u;
			cin >> v >> u;
			adj[mp[v]].push_back(mp[u]);
			adj[mp[u]].push_back(mp[v]);
		}
		ans = 0;
		for (int v = 0; v < ptr; ++ v){
			mark[v] = true;
			for (int u : adj[v])
				mark[u] = true;
			for (int x : V){
				for (pii y : vec[x]){
					if (mark[y.B])
						continue;
					ans = max(ans, 1ll * (cnt[v] + x) * (b[v] + y.A));
					break;
				}
			}
			for (int u : adj[v])
				mark[u] = false;
			mark[v] = false;
		}
		cout << ans << endl;
	}

	return 0;
}