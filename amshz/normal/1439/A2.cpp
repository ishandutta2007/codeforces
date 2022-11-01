//khodaya khodet komak kon
# include <bits/stdc++.h>
 
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
 
const int xn = 1e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int qq, n, m, a[xn][xn], ans[6][xn * xn], ptr;
string s;

void add(int x1, int y1, int x2, int y2, int x3, int y3){
	ans[0][ptr] = x1;
	ans[1][ptr] = y1;
	ans[2][ptr] = x2;
	ans[3][ptr] = y2;
	ans[4][ptr] = x3;
	ans[5][ptr] = y3;
	a[x1][y1] ^= 1;
	a[x2][y2] ^= 1;
	a[x3][y3] ^= 1;
	++ ptr;
}

int main(){
	//InTheNameOfGod;
	
	cin >> qq;
	while (qq --){
		cin >> n >> m;
		for (int i = 1; i <= n; ++ i){
			cin >> s;
			for (int j = 1; j <= m; ++ j)
				a[i][j] = s[j - 1] - '0';
		}
		ptr = 0;
		if (n % 2 || m % 2){
			if (a[n][m])
				add(n, m, n - 1, m, n, m - 1);
			if (n % 2){
				for (int i = 1; i < m; ++ i){
					if (a[n][i]){
						if (m == 2)
							add(n, i, n - 1, i, n - 1, i + 1);
						else if (i < m - 1)
							add(n, i, n - 1, i, n - 1, i + 1);
						else
							add(n, i, n - 1, i, n - 1, i - 1);
					}
				}
			}
			if (m % 2){
				for (int i = 1; i < n; ++ i){
					if (a[i][m]){
						if (n == 2)
							add(i, m, i, m - 1, i + 1, m - 1);
						else if (i < n - 1)
							add(i, m, i, m - 1, i + 1, m - 1);
						else
							add(i, m, i, m - 1, i - 1, m - 1);
					}
				}
			}
		}
		for (int i = 1; i <= n - n % 2; i += 2){
			for (int j = 1; j <= m - m % 2; j += 2){
				//cout << i << " : " << j << endl;
				while (true){
					int ted = a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1];
					//cout << ted << endl;
					if (!ted)
						break;
					if (ted == 4){
						add(i, j, i + 1, j, i, j + 1);
						continue;
					}
					vector <pii> vec[2];
					if (a[i][j])
						vec[1].push_back({i, j});
					else
						vec[0].push_back({i, j});
					if (a[i + 1][j])
						vec[1].push_back({i + 1, j});
					else
						vec[0].push_back({i + 1, j});
					if (a[i][j + 1])
						vec[1].push_back({i, j + 1});
					else
						vec[0].push_back({i, j + 1});
					if (a[i + 1][j + 1])
						vec[1].push_back({i + 1, j + 1});
					else
						vec[0].push_back({i + 1, j + 1});
					if (ted < 3)
						add(vec[1][0].A, vec[1][0].B, vec[0][0].A, vec[0][0].B, vec[0][1].A, vec[0][1].B);
					else
						add(vec[1][0].A, vec[1][0].B, vec[1][1].A, vec[1][1].B, vec[1][2].A, vec[1][2].B);
				}
			}
		}
		cout << ptr << endl;
		for (int i = 0; i < ptr; ++ i){
			for (int j = 0; j < 6; ++ j)
				cout << ans[j][i] << sep;
			cout << endl;
		}
	}
	
	return 0;
}