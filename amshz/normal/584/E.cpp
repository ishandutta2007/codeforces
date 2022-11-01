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

const int xn = 2e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, a[xn], b[xn], p[xn], cs;
vector <pii> ans;
vector <int> vec;

int main(){
	fast_io;

	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	for (int i = 1; i <= n; ++ i)
		cin >> b[i], p[b[i]] = i;
	for (int _ = 0; _ < n; ++ _){
		for (int i = 1; i <= n; ++ i){
			if (p[a[i]] == i)
				continue;
			int v = i;
			vec.clear();
			vec.push_back(v);
			while (p[a[v]] != i){
				v = p[a[v]];
				vec.push_back(v);
			}
			int u = i;
			for (int x : vec)
				if (p[a[u]] < p[a[x]])
					u = x;
			for (int x : vec)
				if (u < x && x <= p[a[u]] && p[a[x]] <= u)
					v = x;
			ans.push_back({u, v});
			cs += abs(u - v);
			swap(a[u], a[v]);
			break;
		}
	}
	cout << cs << endl << SZ(ans) << endl;
	for (pii x : ans)
		cout << x.A << sep << x.B << endl;

	return 0;
}