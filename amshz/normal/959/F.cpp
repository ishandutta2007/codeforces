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
 
const int xn = 2e6 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

/*
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
*/

int n, q, a[xn], ans[xn], pw[xn], res;
vector <pii> Q[xn];
vector <int> vec, vec2;
bool mark[xn];

int main(){
    InTheNameOfGod;
    
    pw[0] = 1;
    for (int i = 1; i < xn; ++ i)
    	pw[i] = ll(pw[i - 1]) * 2LL % mod;
    cin >> n >> q;
    for (int i = 1; i <= n; ++ i)
    	cin >> a[i];
    for (int i = 1; i <= q; ++ i){
    	int l, x;
    	cin >> l >> x;
    	Q[l].push_back({x, i});
	}
	mark[0] = true;
	vec.push_back(0);
	for (int i = 1; i <= n; ++ i){
		if (mark[a[i]])
			++ res;
		else{
			vec2.clear();
			for (int x : vec){
				int y = (x ^ a[i]);
				vec2.push_back(y);
				mark[y] = true;
			}
			for (int x : vec2)
				vec.push_back(x);
		}
		for (pii x : Q[i])
			if (mark[x.A])
				ans[x.B] = pw[res];
	}
	for (int i = 1; i <= q; ++ i)
		cout << ans[i] << endl;
	
    return 0;
}