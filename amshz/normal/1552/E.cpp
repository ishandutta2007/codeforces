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

const int xn = 1e4 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, k, a[xn], sz[xn];
pii ans[xn];
vector <int> vec[xn];
vector <pii> V;
bool mark[xn];

int main(){
	fast_io;

	cin >> n >> k;
	for (int i = 1; i <= n * k; ++ i)
		cin >> a[i], vec[a[i]].push_back(i);
	int res = n % (k - 1);
	for (int i = 1; i < k; ++ i){
		sz[i] = n / (k - 1);
		if (res)
			++ sz[i], -- res;
	}
	for (int i = 1; i < k; ++ i){
		V.clear();
		for (int j = 1; j <= n; ++ j)
			if (!mark[j])
				V.push_back({vec[j][i], j});
		sort(all(V));
		for (int j = 0; j < sz[i]; ++ j){
			int id = V[j].B;
			mark[id] = true;
			ans[id] = {vec[id][i - 1], vec[id][i]};
		}
	}
	for (int i = 1; i <= n; ++ i)
		cout << ans[i].A << sep << ans[i].B << endl;

	return 0;
}