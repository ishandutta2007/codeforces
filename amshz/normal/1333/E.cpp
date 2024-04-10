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
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 5e2 + 10;
const int xm = 1e3 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 2e9 + 10;
const ll INF = 1e18 + 10;
const int MOD = 1e9 + 7;
const int TM = 3;
const int BASE = 257;
 
int n, num[xn][xn], ptr;
 
int main(){
    InTheNameOfGod;
    
    cin >> n;
    if (n < 3) kill(- 1);
    num[1][1] = 7;
    num[1][2] = 6;
    num[1][3] = 9;
    num[2][1] = 8;
    num[2][2] = 4;
    num[2][3] = 3;
    num[3][1] = 1;
    num[3][2] = 2;
    num[3][3] = 5;
    for (int i = 1; i <= 3; ++ i) for (int j = 1; j <= 3; ++ j) num[i][j] += n * n - 9;
    ptr = n * n - 9;
    for (int i = 4; i <= n; ++ i){
    	if (i % 2 == 0){
    		for (int j = 1; j <= i; ++ j) num[i][j] = ptr --;
    		for (int j = i - 1; j >= 1; -- j) num[j][i] = ptr --;
		}
		else{
			for (int j = 1; j <= i; ++ j) num[j][i] = ptr --;
			for (int j = i - 1; j >= 1; -- j) num[i][j] = ptr --;
		}
	}
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= n; ++ j) cout << num[i][j] << sep;
		cout << endl;
	}
	
    return 0;
}