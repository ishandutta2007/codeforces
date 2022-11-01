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

const int xn = 4e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int m, n, ptr[xn], d[xn];
pair <ld, ld> a[xn];
pii b[xn];
vector <pair <ld, int> > vec;

int mark[xn], h[xn];
vector < pii > adj[xn];
vector <int> out[xn];
map <int, int> mp[xn];
 
void dfs(int v, int p, int d, int pid = 0){
    mark[v] = 1;
    h[v] = d;
    for (pii U : adj[v]){
    	int u = U.A, id = U.B;
        if (pid == id)
            continue;
        if (mark[u] && h[u] < h[v])
            out[v].push_back(id);
        else if (!mark[u])
            dfs(u, v, d + 1, id);
    }
    if (out[v].size() % 2 == 1 && p)
        out[v].push_back(pid);
    else if (out[v].size() % 2 == 0 && p)
        out[p].push_back(pid);
}

int main(){
	InTheNameOfGod;

	cin >> m;
	for (int i = 1; i <= m; ++ i){
		int aa, b, c, d;
		cin >> aa >> b >> c >> d;
		ld x = ld(aa) / ld(b);
		ld y = ld(c) / ld(d);
		a[i].A = (x + 1) / y;
		a[i].B = x / (y + 1);
		vec.push_back({a[i].A, i});
		vec.push_back({a[i].B, - i});
	}
	sort(all(vec));
	for (int i = 0; i < SZ(vec); ++ i){
		if (!i || abs(vec[i].A - vec[i - 1].A) >= 0.00000000000001)
			++ n;
		if (vec[i].B > 0)
			b[vec[i].B].A = n;
		else
			b[- vec[i].B].B = n;
	}
	for (int i = 1; i <= m; ++ i){
		int v = b[i].A, u = b[i].B;
		adj[v].push_back({u, i});
		adj[u].push_back({v, i});
	}
	for (int v = 1; v <= n; v ++)
        if (!mark[v])
            dfs(v, 0, 0);
    int ans = 0;
    for (int i = 1; i <= n; i ++)
        ans += out[i].size() / 2;
    cout << ans << '\n';
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j + 1 < out[i].size(); j += 2)
            cout << out[i][j] << ' ' << out[i][j + 1] << '\n';

	return 0;
}