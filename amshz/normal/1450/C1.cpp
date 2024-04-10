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
vector <pii> vec[3];

int main(){
	InTheNameOfGod;
	
	cin >> qq;
	while (qq --){
		cin >> n;
		for (int i = 0; i < n; ++ i)
			cin >> s[i];
		for (int i = 0; i < 3; ++ i)
			vec[i].clear();
		for (int i = 0; i < n; ++ i)
			for (int j = 0; j < n; ++ j)
				if (s[i][j] == 'X')
					vec[(i + j) % 3].push_back({i, j});
		for (int i = 0; i < n; ++ i)
			for (int j = 0; j < n; ++ j)
				t[i][j] = s[i][j];
		k = SZ(vec[0]) + SZ(vec[1]) + SZ(vec[2]);
		if (SZ(vec[0]) <= k / 3){
			for (pii x : vec[0])
				t[x.A][x.B] = 'O';
		}
		else if (SZ(vec[1]) <= k / 3){
			for (pii x : vec[1])
				t[x.A][x.B] = 'O';
		}
		else{
			for (pii x : vec[2])
				t[x.A][x.B] = 'O';
		}
		for (int i = 0; i < n; ++ i){
			for (int j = 0; j < n; ++ j)
				cout << t[i][j];
			cout << endl;
		}
	}
			
	return 0;
}