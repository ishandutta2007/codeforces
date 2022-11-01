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

int qq, n, a[xn], pt[xn], b[xn];
vector <int> vec[xn], V;

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n;
		for (int i = 1; i <= n; ++ i){
			pt[i] = 0;
			vec[i].clear();
		}
		for (int i = 1; i <= n; ++ i)
			cin >> a[i], vec[a[i]].push_back(i);
		for (int i = 1; i <= n; ++ i)
			if (SZ(vec[i]))
				V.push_back(i);
		while (SZ(V)){
			vector <int> V2;
			V2.clear();
			for (int i = 0; i < SZ(V); ++ i){
				int nxt = (i + 1) % SZ(V);
				int x = V[i];
				b[vec[x][pt[x] ++]] = V[nxt];
				if (pt[x] < SZ(vec[x]))
					V2.push_back(x);
			}
			V.clear();
			for (int x : V2)
				V.push_back(x);
		}
		for (int i = 1; i <= n; ++ i)
			cout << b[i] << sep;
		cout << endl;
	}

	return 0;
}