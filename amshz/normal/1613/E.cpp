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

const int xn = 1e6 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int qq, n, m;
vector <int> a[xn], b[xn];
string S[xn];
queue <pii> q;

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n >> m;
		for (int i = 1; i <= n; ++ i){
			cin >> S[i];
			S[i] = '.' + S[i];
			a[i].clear(), a[i].push_back(0);
			b[i].clear(), b[i].push_back(0);
			for (int j = 1; j <= m; ++ j)
				a[i].push_back(0), b[i].push_back(0);
		}
		for (int i = 1; i <= n; ++ i){
			for (int j = 1; j <= m; ++ j){
				bool flag = false;
				if (1 < i && S[i - 1][j] == '.')
					++ a[i][j];
				if (i < n && S[i + 1][j] == '.')
					++ a[i][j];
				if (1 < j && S[i][j - 1] == '.')
					++ a[i][j];
				if (j < m && S[i][j + 1] == '.')
					++ a[i][j];
				flag |= (1 < i && S[i - 1][j] == 'L');
				flag |= (i < n && S[i + 1][j] == 'L');
				flag |= (1 < j && S[i][j - 1] == 'L');
				flag |= (j < m && S[i][j + 1] == 'L');
				if (S[i][j] == '.' && a[i][j] < 2 && flag)
					q.push({i, j}), b[i][j] = 1;
			}
		}
		while (SZ(q)){
			int x = q.front().A, y = q.front().B;
			q.pop();
			if (1 < x && S[x - 1][y] == '.'){
				-- a[x - 1][y];
				if (a[x - 1][y] < 2 && !b[x - 1][y])
					b[x - 1][y] = 1, q.push({x - 1, y});
			}
			if (x < n && S[x + 1][y] == '.'){
				-- a[x + 1][y];
				if (a[x + 1][y] < 2 && !b[x + 1][y])
					b[x + 1][y] = 1, q.push({x + 1, y});
			}
			if (1 < y && S[x][y - 1] == '.'){
				-- a[x][y - 1];
				if (a[x][y - 1] < 2 && !b[x][y - 1])
					b[x][y - 1] = 1, q.push({x, y - 1});
			}
			if (y < m && S[x][y + 1] == '.'){
				-- a[x][y + 1];
				if (a[x][y + 1] < 2 && !b[x][y + 1])
					b[x][y + 1] = 1, q.push({x, y + 1});
			}
		}
		for (int i = 1; i <= n; ++ i){
			for (int j = 1; j <= m; ++ j){
				if (b[i][j])
					cout << "+";
				else
					cout << S[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}