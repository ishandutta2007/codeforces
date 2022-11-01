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
typedef pair <ll,  ll >                                  pii;
typedef pair <pii, ll >                                  ppi;
typedef pair <ll , pii>                                  pip;
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
 
const int xn = 1e2 + 10;
const int xm = 1e5 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ll mod = 1e9 + 7;
const int TM = 30;
const int BASE = 257;
 
struct matrix{
    ll n, m, a[xn][xn];
    matrix(int n1, int m1, int x = 0){
        n = n1; m = m1;
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                a[i][j] = x;
    }
    matrix operator * (const matrix &t){
        matrix r = matrix(n, t.m);
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < t.m; j ++)
                for (int k = 0; k < m; k ++)
                    r.a[i][j] = (r.a[i][j] + a[i][k] * t.a[k][j] % mod) % mod;
        return r;
    }
};
 
matrix Pow(matrix a, ll b){
    matrix res = matrix(a.n, a.m);
    for (int i = 0; i < a.n; i ++)
    	res.a[i][i] = 1;
    for (; b; b = b >> 1){
        if (b & 1)
            res = res * a;
        a = a * a;
    }
    return res;
}
 
ll n, x, num[xm], cnt[xn], dp[xn];
matrix m = matrix(101, 1), c = matrix(101, 101);
 
int main(){
    InTheNameOfGod;
    
    cin >> n >> x;
    for (int i = 0; i < n; ++ i) cin >> num[i], ++ cnt[num[i]];
    for (int i = 0; i < 100; ++ i){
    	dp[i] = 1;
    	for (int j = 1; j <= i; ++ j) dp[i] = (dp[i] + dp[i - j] * cnt[j]) % mod;
	}
	for (int i = 0; i < 101; ++ i){
		if (i < 100) m.a[99 - i][0] = dp[i];
		else m.a[i][0] = 1;
	}
	for (int i = 0; i < 101; ++ i){
		if (i < 100) c.a[0][i] = cnt[i + 1];
		else c.a[0][i] = 1;
	}
	for (int i = 1; i < 100; ++ i) c.a[i][i - 1] = 1;
	c.a[100][100] = 1;
	if (x < 100) kill(dp[x]);
	m = Pow(c, x - 99) * m;
	cout << m.a[0][0] << endl;
    
    return 0;
}