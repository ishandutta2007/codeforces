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
const int mod = 1e9 + 6;
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

ll n, f1, f2, f3, a, ans, z[3];

int main(){
    InTheNameOfGod;
    
    cin >> n >> f1 >> f2 >> f3 >> a;
    matrix m(5, 1), c(5, 5);
    m.a[0][0] = 1;
    m.a[1][0] = 4;
    c.a[0][0] = 1;
	c.a[1][0] = 1;
	c.a[1][1] = 1;
	c.a[2][3] = 1;
	c.a[3][4] = 1;
	c.a[4][0] = mod - 6;
	c.a[4][1] = 2;
	c.a[4][2] = 1;
	c.a[4][3] = 1;
	c.a[4][4] = 1;
	m = Pow(c, n - 3) * m;
	ans = power(a, m.a[4][0], mod + 1);
	for (int i = 0; i < 3; ++ i){
		matrix m(3, 1), c(3, 3);
		m.a[i][0] = 1;
		c.a[0][1] = 1;
		c.a[1][2] = 1;
		c.a[2][0] = 1;
		c.a[2][1] = 1;
		c.a[2][2] = 1;
		m = Pow(c, n - 3) * m;
		z[i] = m.a[2][0];
	}
	ans = ll(ans) * power(f1, z[0], mod + 1) % (mod + 1);
	ans = ll(ans) * power(f2, z[1], mod + 1) % (mod + 1);
	ans = ll(ans) * power(f3, z[2], mod + 1) % (mod + 1);
	cout << ans << endl;
	
    return 0;
}