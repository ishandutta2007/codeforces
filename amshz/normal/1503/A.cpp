// khodaya khodet komak kon
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
typedef pair <ll, ll>                                    pll;
typedef pair <pll,  ll>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
 
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
 
const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int qq, n, res[2];
string S;
char a[xn], b[xn];
vector <int> vec[2];
bool flag;

int main(){
	InTheNameOfGod;

	cin >> qq;
	while (qq --){
		cin >> n >> S;
		vec[0].clear(), vec[1].clear();
		for (int i = 0; i < n; ++ i)
			vec[S[i] - '0'].push_back(i);
		if (SZ(vec[0]) % 2){
			cout << "NO" << endl;
			continue;
		}
		for (int i = 0; i < SZ(vec[1]); ++ i){
			if (i < SZ(vec[1]) / 2)
				a[vec[1][i]] = b[vec[1][i]] = '(';
			else
				a[vec[1][i]] = b[vec[1][i]] = ')';
		}
		for (int i = 0; i < SZ(vec[0]); ++ i){
			if (i % 2)
				a[vec[0][i]] = '(', b[vec[0][i]] = ')';
			else
				a[vec[0][i]] = ')', b[vec[0][i]] = '(';
		}
		flag = true;
		for (int i = 0; i < n; ++ i){
			++ res[0], ++ res[1];
			if (a[i] == ')')
				res[0] -= 2;
			if (b[i] == ')')
				res[1] -= 2;
			flag &= res[0] >= 0;
			flag &= res[1] >= 0;
		}
		if (flag){
			cout << "YES" << endl;
			for (int i = 0; i < n; ++ i)
				cout << a[i];
			cout << endl;
			for (int i = 0; i < n; ++ i)
				cout << b[i];
			cout << endl;
			continue;
		}
		cout << "NO" << endl;
	}
			
	return 0;
}