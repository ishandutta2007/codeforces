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
 
const int xn = 2e2 + 10;
const int xm = 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
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

int a[xm], dp[xn][xm][2], last[xn], pt1 = 7, pt2 = - 1;

int main(){
	InTheNameOfGod;
    
    for (int i = 0; i < 7; ++ i)
    	cin >> a[i];
    for (int i = 0; i < 7; ++ i){
    	if (!a[i]) continue;
    	pt1 = min(pt1, i);
    	pt2 = max(pt2, i);
	}
    for (int mask = 0; mask < 128; ++ mask){
    	dp[mask][0][1] = 1;
    	for (int i = 1; i < xm; ++ i){
    		dp[mask][i][0] = dp[mask][i][1] = dp[mask][i - 1][0] + dp[mask][i - 1][1];
    		if ((mask & (1 << (i - 1)))) dp[mask][i][1] -= dp[mask][i - 1][1];
		}
	}
	last[(1 << pt1) - 1] = 1;
	for (int i = pt1; i <= pt2; ++ i){
		int n = 1 << (i + 1);
		matrix m(n, 1), c(n, n);
		for (int mask = 0; mask < 1 << i; ++ mask)
			swap(last[mask], last[mask | (1 << i)]);
		for (int mask = 0; mask < n; ++ mask)
			for (int mask2 = 0; mask2 < n; ++ mask2)
				c.a[mask][mask2] = dp[(mask & mask2)][i + 1][1];
		for (int mask = 0; mask < n; ++ mask)
			m.a[mask][0] = last[mask];
		m = Pow(c, a[i]) * m;
		for (int mask = 0; mask < n; ++ mask)
			last[mask] = m.a[mask][0];
	}
	cout << last[(1 << (pt2 + 1)) - 1] << endl;
	
    return 0;
}