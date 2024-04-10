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

int qq, n, k;
string s[xn];
char t[xn][xn];
vector <pii> vec[2][3];

int main(){
	InTheNameOfGod;
	
	cin >> qq;
	while (qq --){
		cin >> n;
		for (int i = 0; i < n; ++ i)
			cin >> s[i];
		for (int i = 0; i < 3; ++ i)
			vec[0][i].clear(), vec[1][i].clear();
		for (int i = 0; i < n; ++ i){
			for (int j = 0; j < n; ++ j){
				t[i][j] = s[i][j];
				if (s[i][j] == 'X')
					vec[0][(i + j) % 3].push_back({i, j});
				else if (s[i][j] == 'O')
					vec[1][(i + j) % 3].push_back({i, j});
			}
		}
		k = 0;
		for (int i = 0; i < 2; ++ i)
			for (int j = 0; j < 3; ++ j)
				k += SZ(vec[i][j]);
		if (SZ(vec[0][0]) + SZ(vec[1][1]) <= k / 3){
			for (pii x : vec[0][0])
				t[x.A][x.B] = 'O';
			for (pii x : vec[1][1])
				t[x.A][x.B] = 'X';
		}
		else if (SZ(vec[0][1]) + SZ(vec[1][2]) <= k / 3){
			for (pii x : vec[0][1])
				t[x.A][x.B] = 'O';
			for (pii x : vec[1][2])
				t[x.A][x.B] = 'X';
		}
		else{
			for (pii x : vec[0][2])
				t[x.A][x.B] = 'O';
			for (pii x : vec[1][0])
				t[x.A][x.B] = 'X';
		}
		for (int i = 0; i < n; ++ i){
			for (int j = 0; j < n; ++ j)
				cout << t[i][j];
			cout << endl;
		}
	}
			
	return 0;
}