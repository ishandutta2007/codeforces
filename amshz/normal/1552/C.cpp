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

const int xn = 2e2 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int qq, n, k, ans;
vector <pii> E;
vector <int> vec;
bool mark[xn];

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n >> k;
		E.clear();
		memset(mark, false, sizeof mark);
		for (int i = 0; i < k; ++ i){
			int x, y;
			cin >> x >> y;
			if (y < x)
				swap(x, y);
			E.push_back({x, y});
			mark[x] = mark[y] = true;
		}
		vec.clear();
		for (int i = 1; i <= n + n; ++ i)
			if (!mark[i])
				vec.push_back(i);
		int m = SZ(vec) / 2;
		for (int i = 0; i < m; ++ i)
			E.push_back({vec[i], vec[i + m]});
		sort(all(E));
		ans = 0;
		for (int i = 0; i < n; ++ i)
			for (int j = i + 1; j < n; ++ j)
				ans += (E[j].A < E[i].B && E[i].B < E[j].B);
		cout << ans << endl;
	}

	return 0;
}