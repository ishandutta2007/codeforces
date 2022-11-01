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
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e2 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
int mod = 1e9 + 7;
const int base = 257;


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
    matrix operator = (const int &t){
    	for (int i = 0; i < n; ++ i)
    		for (int j = 0; j < m; ++ j)
    			a[i][j] = t;
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

ll n, m, k, l, bit, ans, x, y;

int main(){
    InTheNameOfGod;
    
    cin >> n >> k >> l >> mod;
    if (l < 63 && k >= (1LL << l)) kill(0);
    for (ll i = 0; i < l; ++ i)
    	bit += ((1LL << i) & k) > 0;
    matrix m(2, 1), c(2, 2);
    m.a[0][0] = 1;
    c.a[0][0] = c.a[0][1] = c.a[1][0] = 1;
    m = Pow(c, n) * m;
    x = (m.a[0][0] + m.a[1][0]) % mod;
    y = (power(2, n, mod) - x + mod) % mod;
    cout << power(x, l - bit, mod) * power(y, bit, mod) % mod << endl;
	
    return 0;
}