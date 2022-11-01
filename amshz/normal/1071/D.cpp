// khodaya khodet komak kon
# include <bits/stdc++.h>
# pragma comment(linker, "/stack:200000000")
# pragma GCC optimize("Ofast")
 
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
typedef pair <ll, ll>                                    pll;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
 
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
 
const int xn = 1e6 + 10;
const int xm = 1e3 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e15 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int qq, a[xm], n, c[xm], dist[xm][xm], ans;
bool pr[xn];
vector <int> prm, vec[xm], vec2, adj[xm], mg[xn];
unordered_map <int, int> mp;
queue <int> q;

void solve(int ptr = 0, ll val = 1, int res = 1){
	for (int i = 0; i < ptr; ++ i)
		vec[n].push_back(a[i]);
	mp[val] = n, c[n ++] = res;
	for (int i = 2; i < 40; ++ i){
		val *= prm[ptr];
		if (val > 1e8 || (ptr && i > a[ptr - 1]))
			break;
		a[ptr] = i, solve(ptr + 1, val, res * i);
	}
}
int check(){
	sort(all(vec2)), reverse(all(vec2));
	ll res = 1;
	for (int i = 0; i < SZ(vec2); ++ i)
		for (int j = 1; j < vec2[i]; ++ j)
			res *= prm[i];
	if (res > 1e8)
		return - 1;
	return mp[res];
}

int main(){
	InTheNameOfGod;
 
	for (int i = 2; i < xn; ++ i){
		if (pr[i])
			continue;
		prm.push_back(i);
		for (int j = i; j < xn; j += i)
			pr[j] = true, mg[j].push_back(i);
	}
	solve();
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j <= SZ(vec[i]); ++ j){
			vec2.clear();
			for (int k = 0; k < SZ(vec[i]); ++ k){
				if (k == j)
					vec2.push_back(vec[i][k] + 1);
				else
					vec2.push_back(vec[i][k]);
			}
			if (j == SZ(vec[i]))
				vec2.push_back(2);
			int id = check();
			if (id == - 1)
				continue;
			adj[i].push_back(id);
			adj[id].push_back(i);
		}
	}
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < n; ++ j)
			dist[i][j] = inf;
		for (int j = 0; j < n; ++ j)
			if (c[i] == c[j])
				dist[i][j] = 0, q.push(j);
		while (SZ(q)){
			int v = q.front();
			q.pop();
			for (int u : adj[v])
				if (dist[i][u] == inf)
					dist[i][u] = dist[i][v] + 1, q.push(u);
		}
	}
	cin >> qq;
	while (qq --){
		int x, y;
		cin >> x >> y;
		vec2.clear();
		for (int z : mg[x]){
			int t = 1, w = x;
			while (w % z == 0)
				w /= z, ++ t;
			vec2.push_back(t);
		}
		int id1 = check();
		vec2.clear();
		for (int z : mg[y]){
			int t = 1, w = y;
			while (w % z == 0)
				w /= z, ++ t;
			vec2.push_back(t);
		}
		int id2 = check();
		ans = inf;
		for (int i = 0; i < n; ++ i)
			ans = min(ans, dist[i][id1] + dist[i][id2]);
		cout << ans << endl;
	}
 
	return 0;
}