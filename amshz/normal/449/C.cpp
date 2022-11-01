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
const int mod = 998244353;
const int base = 257;

int n, last[xn];
bool p[xn];
vector <int> vec[xn];
vector <pii> ans;

int main(){
	fast_io;

	cin >> n;
	for (int i = 2; i <= n; ++ i){
		if (p[i])
			continue;
		last[i] = i;
		for (int j = i + i; j <= n; j += i)
			last[j] = i, p[j] = true;
	}
	for (int i = 1; i <= n; ++ i)
		if (i % 2 || p[i / 2] || i == 4)
			vec[last[i]].push_back(i);
	vec[2].push_back(2);
	for (int i = 3; i + i <= n; ++ i){
		if (p[i])
			continue;
		if (SZ(vec[i]) % 2)
			vec[i].push_back(i + i);
		else
			vec[2].push_back(i + i);
	}
	for (int i = 2; i <= n; ++ i)
		for (int j = 0; j + 1 < SZ(vec[i]); j += 2)
			ans.push_back({vec[i][j], vec[i][j + 1]});
	cout << SZ(ans) << endl;
	for (pii x : ans)
		cout << x.A << sep << x.B << endl;

	return 0;
}